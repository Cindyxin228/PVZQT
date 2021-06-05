#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#pragma once
#include"plant.h"
#include"config.h"

class sunFlower: public plant
{
public:
    sunFlower();
    void advance(int phase) override;
};

#endif // SUNFLOWER_H
