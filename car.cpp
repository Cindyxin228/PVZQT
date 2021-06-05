#include "car.h"
#include"config.h"

car::car()
{
    flag = false;
    speed = carSpeed;
}

QRectF car::boundingRect() const
{
    return QRectF(-30, -30, 60, 60);
}

void car::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(-30, -30, 60, 60), QPixmap(":/res/LawnMower.png"));
}

bool car::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 15;
}

void car::advance(int phase)
{
    if (!phase)
        return;
    update();
    QList<QGraphicsItem *> items = collidingItems();
    //旁边有僵尸
    if (!items.empty())
    {
        flag = true;
        foreach (QGraphicsItem *item, items)
        {
            zombie *Zombie = qgraphicsitem_cast<zombie *>(item);
            Zombie->life = 0;
        }
    }
    if (flag)
        setX(x() + speed);
    if (x() > GAME_WIDTH)
        delete this;
}

