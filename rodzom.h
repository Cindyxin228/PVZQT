#ifndef RODZOM_H
#define RODZOM_H

#pragma once
#include"zombie.h"

class rodZom: public zombie
{
private:
    bool tool;
public:
    rodZom();
    void advance(int phase) override;
};

#endif // RODZOM_H
