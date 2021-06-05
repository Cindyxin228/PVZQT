#include "nut.h"
#include"store.h"

nut::nut()
{
    life = peaLife;
    setMovie(":/res/Nut.gif");
}

void nut::advance(int phase){
    if (!phase)
            return;
    update();
    if (life <= 0){
        store *Store = qgraphicsitem_cast<store *>(scene()->items(QPointF(300, 15))[0]);
        Store->plantNum[int((this->y() - 81) / 98)] --;
        delete this;
    }
    else if (life > nutLife/4 && life < nutLife/2){
        setMovie(":/res/Nut1.gif");
    }
    //生命不足一半但还没死
    else if (life <= nutLife/3){
        setMovie(":/res/Nut2.gif");
    }

}
