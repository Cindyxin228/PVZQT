#include "hatzom.h"
#include"config.h"

hatZom::hatZom()
{
    life = hatLife;
    power = hatPower;
    speed = hatSpeed;
    setMovie(":/res/ConeZombieWalk.gif");
}

void hatZom::advance(int phase){
    if(!phase)
        return;
    //用于重绘
    update();
    if(life <= 0){
        //在此之前还活着
        if(state < 2){
            state = 2;
            setMovie(":/res/norDie.gif");
            setMovie(":/res/norHead.gif");
        }
        //已经死了，并且动画已经播放到最后一帧
        else if(movie->currentFrameNumber() == movie->frameCount() - 1)
            delete this;
        return;
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
        //不处于攻击状态
        if(state != 1){
            state = 1;
            setMovie(":/res/ConeZombieAttack.gif");
        }
        return;
    }
    //处于攻击状态
    if(state){
        //使之处于行走状态
        state = 0;
        setMovie(":/res/ConeZombieWalk.gif");
    }
    //位置移动
    setX(x() - speed);
}
