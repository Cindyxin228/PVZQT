#include "jokerzom.h"
#include"config.h"
#include"plant.h"
#include<QDebug>

//state 0, 正常行走，1, 攻击， 2， 死亡， 3， 爆炸
jokerZom::jokerZom(){
    speed = jokerSpeed;
    life = jokerLife;
    power = jokerPower;
    setMovie(":/res/jokerWalk.gif");
}

void jokerZom::advance(int phase){
    cnt ++;
    if (!phase)
            return;
    update();
    //dead
    if (life <= 0)
    {
        qDebug()<<"life < 0";
        //alive before
        if (state < 2)
        {
            state = 2;
            setMovie(":/res/jokerDie.gif");
            setMovie(":/res/jokerWalk.gif");
        }
        else if (movie->currentFrameNumber() == movie->frameCount() - 1){
//            qDebug()<<"life < 0";
            delete this;
        }
        return;
    }
    if(cnt % 14 == 0){
        int ran = qrand() % 80;
        if(ran == 11){/*
            qDebug()<<"boom";*/
            state = 3;
            setMovie(":/res/jokerBoom.gif");
            life = 0;
            QList<QGraphicsItem *> items = collidingItems();
            foreach (QGraphicsItem *item, items)
            {
                if(item ->type() == plant::Type){
                    plant *Plant = qgraphicsitem_cast<plant *>(item);
                    Plant->life -= 2000;
                    //设置僵尸被炸死的movie
                    if (Plant->life <= 0)
                    {
                        delete item;
                    }
                }
            }
            return;
        }
    }
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        plant *Plant = qgraphicsitem_cast<plant *>(items[0]);
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
        if (state != 1)
        {
            state = 1;
            setMovie(":/res/jokerAttack.gif");
        }
        return;
    }
    //attack before, now walk
    if (state)
    {
        state = 0;
        setMovie(":/res/jokerWalk.gif");
    }
    setX(x() - speed);
}

//碰撞检测
bool jokerZom::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    if(state == 0 || state == 1)
        return other->type() == plant::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 30;
    else
        return other->type() == plant::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 160;
}
