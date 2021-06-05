#ifndef GARLIC_H
#define GARLIC_H

#include "plant.h"
#include "zombie.h"
#include"config.h"

class garlic: public plant
{
public:
    garlic();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // GARLIC_H
