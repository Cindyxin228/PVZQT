#ifndef FOOTBALLZOM_H
#define FOOTBALLZOM_H

#pragma once
#include "zombie.h"
#include "plant.h"

class footballZom : public zombie
{
    int counter;
    int time;
public:
    footballZom();
    void advance(int phase) override;
};

#endif // FOOTBALLZOM_H
