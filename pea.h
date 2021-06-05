#ifndef PEA_H
#define PEA_H

#pragma once
#include"item.h"

class pea: public item
{
public:
    pea();
    pea(int Power = 0, bool Flag = false);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
private:
    bool ifIce;     //标记是否是寒冰射手的子弹
    int power;
    qreal speed;
};

#endif // PEA_H
