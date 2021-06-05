#ifndef SCREENZOM_H
#define SCREENZOM_H

#pragma once
#include "zombie.h"
#include "plant.h"

class screenZom: public zombie
{
public:
    screenZom();
    void advance(int phase) override;
};

#endif // SCREENZOM_H
