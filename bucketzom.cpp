#include "bucketzom.h"
#include<QDebug>

bucketZom::bucketZom()
{
    speed = bucketSpeed;
    life = bucketLife;
    power = bucketPower;
    setMovie(":/res/BucketZombieWalk.gif");
}

void bucketZom::advance(int phase) {
    if (!phase)
            return;
    update();
    //dead
    if (life <= 0)
    {
        if (state < 2)
        {
            state = 2;
            setMovie(":/res/norDie.gif");
            setHead(":/res/norHead.gif");
        }
        else if (movie->currentFrameNumber() == movie->frameCount() - 1)
            delete this;
        return;
    }
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        plant *Plant = qgraphicsitem_cast<plant *>(items[0]);
        //!pumpkin
        if(items.size() > 1 && Plant ->t != 7){
            Plant = qgraphicsitem_cast<plant* >(items[1]);
        }
        //garlic
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
        //没进攻
        if (state != 1)
        {
            state = 1;
            setMovie(":/res/BucketZombieAttack.gif");
        }
        return;
    }
    //如果在进攻状态，让其走路
    if (state)
    {
        state = 0;
        setMovie(":/res/BucketZombieWalk.gif");
    }
    setX(x() - speed);
}
