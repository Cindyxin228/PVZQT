#ifndef SUN_H
#define SUN_H

#pragma once
#include"item.h"

class Sun : public item
{
public:
    Sun();
    Sun(QPointF pos);
    ~Sun() override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void advance(int phase) override;
private:
    QMovie *movie;
    QPointF dest;       //产生的目的地址
    int counter;
    int time;
    qreal speed;
};

#endif // SUN_H
