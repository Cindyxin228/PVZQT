#ifndef HATZOM_H
#define HATZOM_H
#pragma once
#include"zombie.h"

//三种状态，行走，攻击，死亡，分别记为0， 1， 2
class hatZom: public zombie
{
public:
    hatZom();
    void advance(int phase) override;
};

#endif // HATZOM_H
