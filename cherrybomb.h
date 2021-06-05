#ifndef CHERRYBOMB_H
#define CHERRYBOMB_H

#pragma once
#include"plant.h"
#include"zombie.h"
#include"config.h"

class cherryBomb:public plant
{
public:
    cherryBomb();
    QRectF boundingRect() const override;
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // CHERRYBOMB_H
