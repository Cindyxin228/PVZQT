#include "sunflower.h"
#include"sun.h"
#include"store.h"

sunFlower::sunFlower()
{
    life = flowerLife;
    t = 0;
    power = flowerSpeed;
    setMovie(":/res/sunflower.gif");
}


void sunFlower::advance(int phase){
    if (!phase)
        return;
    update();
    //死亡
    if (life <= 0){
        store *Store = qgraphicsitem_cast<store *>(scene()->items(QPointF(300, 15))[0]);
        Store->plantNum[int((this->y() - 81) / 98)] --;
        delete this;
    }
    //counter++,如果到了该加阳光的时候，就加一个阳光并且把counter清零
    else if (++counter >= power)
    {
        counter = 0;
        scene()->addItem(new Sun(pos()));
    }
}
