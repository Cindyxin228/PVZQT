#ifndef HIGHNUT_H
#define HIGHNUT_H

#pragma once
#include"config.h"
#include"plant.h"
#include"zombie.h"

class highNut: public plant
{
public:
    highNut();
    void advance(int phase) override;
};

#endif // HIGHNUT_H
