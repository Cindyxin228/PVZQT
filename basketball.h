#ifndef BASKETBALL_H
#define BASKETBALL_H

#pragma once
#include"item.h"

class basketBall: public item
{
    int power;
    qreal speed;
public:
    basketBall();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
};

#endif // BASKETBALL_H
