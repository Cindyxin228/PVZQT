#ifndef BIPEA_H
#define BIPEA_H

#pragma once
#include"plant.h"
#include"zombie.h"
#include"config.h"

class biPea: public plant
{
public:
    biPea();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // BIPEA_H
