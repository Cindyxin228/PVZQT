#ifndef POTATO_H
#define POTATO_H

#pragma once
#include"plant.h"
#include"config.h"
#include"zombie.h"

class potato:public plant
{
public:
    potato();
    QRectF boundingRect() const override;
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // POTATO_H
