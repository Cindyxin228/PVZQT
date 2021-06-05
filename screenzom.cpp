#include "screenzom.h"

screenZom::screenZom()
{
    life = screenLife;
    power = screenPower;
    speed = screenSpeed;
    setMovie(":/res/ScreenZombieWalk.gif");
}

void screenZom::advance(int phase){
    if (!phase)
            return;
    update();
    //dead
    if (life <= 0)
    {
        //alive before
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
            setMovie(":/res/ScreenZombieAttack.gif");
        }
        return;
    }
    //attack before, now walk
    if (state)
    {
        state = 0;
        setMovie(":/res/ScreenZombieWalk.gif");
    }
    setX(x() - speed);
}
