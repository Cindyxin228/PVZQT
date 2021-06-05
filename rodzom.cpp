#include "rodzom.h"
#include"config.h"
#include"plant.h"
#include<QDebug>

//状态：0 有杆正常行走，1，无杆正常行走, 2, 无杆攻击， 2 跳跃 3 死亡 4， 跳跃

rodZom::rodZom(){
    speed = rodSpeed;
    life = rodLife;
    power = rodPower;
    tool = true;
    setMovie(":/res/rodWalk.gif");
}

void rodZom::advance(int phase){
    if(!phase)
        return;
    //用于重绘
    update();
    if(life <= 0){
        //在此之前还活着
        if(state != 3){
            state = 3;
            setMovie(":/res/rodDie.gif");
            setHead(":/res/rodHead.gif");
        }
        //已经死了，并且动画已经播放到最后一帧
        else if(movie->currentFrameNumber() == movie->frameCount() - 1)
            delete this;
        return;
    }
    QList<QGraphicsItem*> items = collidingItems();
    if(!items.empty()){
        //有杆子
        if(state == 0){
            if(tool == true){
                bool flag = 1;
                foreach (QGraphicsItem *item, items){
                    plant *Plant = qgraphicsitem_cast<plant *>(item);
                    if(Plant->t == 8){
                        flag = 0;
                    }
                }
                //不是hNut
                if(flag){
                    setMovie(":/res/rodJump1.gif");
                    state = 4;
                    return;
                }
                //是hNut
                if(!flag){
                    plant* Plant = qgraphicsitem_cast<plant* >(items[0]);
                    //!pumpkin
                    if(items.size() > 1 && Plant ->t != 7){
                        Plant = qgraphicsitem_cast<plant* >(items[1]);
                    }
                    Plant->life -= power;
                    return;
                }
            }
        }
        //无杆行走
        else if(state == 1){
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
            state = 2;
            setMovie(":/res/rodNoattack.gif");
            return;
        }
    }
    if(state == 4 && tool){
        setX(x() - 4);
        if(movie->currentFrameNumber() == movie->frameCount() - 1){
            setMovie(":/res/rodJump2.gif");
            tool = false;
            return;
        }
    }
    else if(state == 4 && !tool){
        setX(x() - 2);
        if(movie->currentFrameNumber() == movie->frameCount() - 1){
            state = 1;
            setMovie(":/res/rodNoWalk.gif");
            speed /= 1.3;
        }
    }
    //处于攻击状态
    if(state == 2){
        setMovie(":/res/rodNoWalk.gif");
    }
    //位置移动
    setX(x() - speed);
}

