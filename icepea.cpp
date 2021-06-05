#include "icepea.h"
#include"config.h"
#include"store.h"

icePea::icePea()
{
    power = peaPower;
    life = iceLife;
    time = iceShooterSpeed;
    t = 4;
    setMovie(":/res/icePea.gif");
}

void icePea::advance(int phase){
    if (!phase)
       return;
    update();
    //dead
    if (life <= 0){
        store *Store = qgraphicsitem_cast<store *>(scene()->items(QPointF(300, 15))[0]);
        Store->plantNum[int((this->y() - 81) / 98)] --;
        delete this;
    }
    //if it's time to generate bean
    else if (++counter >= time)
    {
        counter = 0;
        if (!collidingItems().isEmpty())
        {
            pea *Pea = new pea(power, 1);
            Pea->setX(x() + 32);
            Pea->setY(y());
            scene()->addItem(Pea);
            return;
        }
    }
}

bool icePea::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const {
    Q_UNUSED(mode)
       return other->type() == zombie::Type && qFuzzyCompare(other->y(), y());
}
