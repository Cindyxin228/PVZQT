#ifndef LAND_H
#define LAND_H

#pragma once
#include "item.h"
#include "plant.h"
#include "store.h"
#include <QGraphicsSceneDragDropEvent>

class land: public item
{
public:
    land();
    QRectF boundingRect() const override;
    void dragEnterEvent(QGraphicsSceneDragDropEvent *ev) override;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *ev) override;
    void dropEvent(QGraphicsSceneDragDropEvent *ev) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // LAND_H
