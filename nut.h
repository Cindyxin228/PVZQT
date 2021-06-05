#ifndef NUT_H
#define NUT_H

#pragma once
#include"config.h"
#include"plant.h"
#include"zombie.h"

class nut:public plant
{
public:
    nut();
    void advance(int phase) override;
};

#endif // NUT_H
