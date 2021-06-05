#ifndef CAR_H
#define CAR_H

#include "item.h"
#include "zombie.h"

class car: public item
{
    bool flag;
    qreal speed;
public:
    car();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
};

#endif // CAR_H
