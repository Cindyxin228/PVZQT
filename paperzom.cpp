#include "paperzom.h"
#include"config.h"
#include<QDebug>

paperZom::paperZom()
{
    speed = paperSpeed;
    life = paperLife;
    power = paperPower;
    ifSpeedUp = false;
    setMovie(":/res/HeadWalk1.gif");
}

//state 0 报纸行走， 1 报纸攻击， 2 无报纸行走， 3死亡, 4 无报纸攻击
void paperZom::advance(int phase){
    if(!phase)
        return;
    //用于重绘
    update();
    if(life <= 0){
        //在此之前还活着
        if(state != 3){
            state = 3;
            setMovie(":/res/norDie.gif");
            setHead(":/res/norHead.gif");
        }
        //已经死了，并且动画已经播放到最后一帧
        else if(movie->currentFrameNumber() == movie->frameCount() - 1)
            delete this;
        return;
    }
    if(life < paperLife/2 && ifSpeedUp == false){
        speed *= 2;
        ifSpeedUp = true;
        qDebug()<<"speedUP";
    }
    QList<QGraphicsItem*> items = collidingItems();
    if(!items.empty()){
        plant* Plant = qgraphicsitem_cast<plant* >(items[0]);
        //!pumpkin
        if(items.size() > 1 && Plant ->t != 7){
            Plant = qgraphicsitem_cast<plant* >(items[1]);
        }
        Plant->life -= power;
        if(Plant->t == 9){
            if(y() < 200){
                setY(y() + 98);
            }
            else if(y()>520){
                setY(y() - 98);
            }
            else{
                int ran = qrand() % 2;
                if(ran == 0){
                    setY(y() + 98);
                }
                else{
                    setY(y() - 98);
                }
            }
        }
        //报纸被打掉了
        if(life < paperLife/2){
            //不处于攻击状态
            if(state != 4){
                qDebug()<<"noPaper";
                state = 4;
                setMovie(":/res/HeadAttack0.gif");
            }
        }
        else{
            if(state != 1){
                qDebug()<<"hasPaper";
                state = 1;
                setMovie(":/res/HeadAttack1.gif");
            }
        }
        return;
    }
    //处于攻击状态
    if(state){
        //使之处于行走状态
        if(life < paperLife/2){
            state = 2;
            setMovie(":/res/HeadWalk0.gif");
        }
        else{
            state = 0;
            setMovie(":/res/HeadWalk1.gif");
        }
    }
    //位置移动
    setX(x() - speed);
}
