#include "peashooter.h"
#include"pea.h"
#include"store.h"
peaShooter::peaShooter()
{
    life = peaLife;
    time = peaShooterSpeed;
    power = peaPower;
    t = 1;
    setMovie(":/res/peaShooter.gif");
}


void peaShooter::advance(int phase){
    if (!phase)
            return;
    update();
    //dead
    if (life <= 0){
        store *Store = qgraphicsitem_cast<store *>(scene()->items(QPointF(300, 15))[0]);
        Store->plantNum[int((this->y() - 81) / 98)] --;
        delete this;
    }
    //time to generate bean
    else if (++counter >= time)
    {
        counter = 0;
        //There's items
        if (!collidingItems().isEmpty())
        {
            pea *Pea = new pea(power, 0);
            //设置子弹的初始位置
            Pea->setX(x() + 32);
            Pea->setY(y());
            //场景中添加
            scene()->addItem(Pea);
            return;
        }
    }

}

bool peaShooter::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const {
    Q_UNUSED(mode)
    return other->type() == zombie::Type && qFuzzyCompare(other->y(), y());
}
