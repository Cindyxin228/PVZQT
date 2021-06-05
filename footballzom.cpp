#include "footballzom.h"
#include"config.h"
#include"basketball.h"
#include"store.h"

footballZom::footballZom()
{
    life = basketZomLife;
    tool = 5;
    counter = 0;
    time = 100;
    power = basZomPower;
    speed = basketZomSpeed;
    setMovie(":/res/FootballZombieWalk.gif");
}

void footballZom::advance(int phase){
    if (!phase)
            return;
    update();
    if(tool > 0){
        store *Store = qgraphicsitem_cast<store *>(scene()->items(QPointF(300, 15))[0]);
        //it's time to generate a basketball
        if(++counter > time){
            //有植物生成篮球
            if(Store->plantNum[int((this->y() - 81) / 98)] > 0){
                counter = 0;
                tool --;
                basketBall* bb = new basketBall;
                bb->setX(x() - 32);
                bb->setY(y());
                qDebug()<<"basketball";
                scene()->addItem(bb);
                return;
            }
        }
        else if(Store->plantNum[int((this->y() - 81) / 98)] == 0){
            setX(x() - speed);
            return;
        }
        else{
            return;
        }
    }
    //dead
    if (life <= 0)
    {
        //alive before
        if (state < 2)
        {
            state = 2;
            setMovie(":/res/FootballZombieDie.gif");
        }
        else if (movie->currentFrameNumber() == movie->frameCount() - 1)
            delete this;
        return;
    }
    QList<QGraphicsItem *> items = collidingItems();
    foreach (QGraphicsItem *item, items)
    {
        plant *Plant = qgraphicsitem_cast<plant *>(item);
        Plant->life = 0;
        if (state != 1)
        {
            state = 1;
            setMovie(":/res/FootballZombieWalk.gif");
        }
    }
    setX(x() - speed);
}
