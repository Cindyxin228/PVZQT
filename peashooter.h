#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#include "plant.h"
#include "zombie.h"
#include"config.h"

class peaShooter: public plant
{
public:
    peaShooter();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // PEASHOOTER_H
