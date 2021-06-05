#ifndef STORE_H
#define STORE_H
#pragma once
#include"item.h"


//商店里的内容
class store: public item
{
public:
    store();
    int sun;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;
    void addPlant(QString s, QPointF pos);
    int plantNum[5];
private:
    int counter;
    int time;
};


#endif // STORE_H
