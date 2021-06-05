#ifndef PAPERZOM_H
#define PAPERZOM_H

#pragma once
#include"zombie.h"

class paperZom: public zombie
{
    bool ifSpeedUp;
public:
    paperZom();
    void advance(int phase) override;
};

#endif // PAPERZOM_H
