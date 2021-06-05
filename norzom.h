#ifndef NORZOM_H
#define NORZOM_H
#pragma once
#include"zombie.h"

//三种状态，行走，攻击，死亡，分别记为0， 1， 2
class norZom: public zombie
{
public:
    norZom();
    //更新 状态
    void advance(int phase) override;
};

#endif // NORZOM_H
