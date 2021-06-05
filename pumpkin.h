#ifndef PUMPKIN_H
#define PUMPKIN_H

#pragma once
#include"plant.h"
#include"config.h"
#include"zombie.h"

class pumpkin: public plant
{
public:
    pumpkin();
    void advance(int phase) override;
};
#endif // PUMPKIN_H
