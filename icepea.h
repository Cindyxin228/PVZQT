#ifndef ICEPEA_H
#define ICEPEA_H

#include "plant.h"
#include "zombie.h"
#include "pea.h"

class icePea:public plant
{
public:
    icePea();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // ICEPEA_H
