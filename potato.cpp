#include "potato.h"
#include"store.h"

potato::potato()
{
    power = potatoPower;
    time = potatoSpeed;
    life = potatoLife;
    t = 5;
    setMovie(":/res/potato.gif");
}

//determine whether the item requires redrawing
QRectF potato::boundingRect() const {
    return state == 2 ? QRectF(-75, -75, 150, 150) : plant::boundingRect();
}

void potato::advance(int phase){
    if (!phase)
            return;
    update();
    if (life <= 0){
        store *Store = qgraphicsitem_cast<store *>(scene()->items(QPointF(300, 15))[0]);
        Store->plantNum[int((this->y() - 81) / 98)] --;
        delete this;
    }
    //正常形态到了变成攻击的时候
    else if (state == 0 && ++counter >= time)
    {
        state = 1;
        counter = 0;
        time = potatoBoomSpeed;
    }
    //攻击状态足够到爆炸
    else if (state == 1 && ++counter >= time)
    {
        counter = 0;
        QList<QGraphicsItem *> items = collidingItems();
        //有僵尸在范围内
        if (!items.isEmpty())
        {
            state = 2;
            setMovie(":/res/PotatoBomb.gif");
            foreach (QGraphicsItem *item, items)
            {
                zombie *Zombie = qgraphicsitem_cast<zombie *>(item);
                Zombie->life -= power;
                if (Zombie->life <= 0)
                    delete Zombie;
            }
        }
    }
    //爆炸状态下放映到最后一帧
    else if (state == 2 && movie->currentFrameNumber() == movie->frameCount() - 1)
        delete this;
}

bool potato::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const {
    Q_UNUSED(mode)
    //爆炸范围
    return other->type() == zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 50;
}
