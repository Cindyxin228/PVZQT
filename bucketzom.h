#ifndef BUCKETZOM_H
#define BUCKETZOM_H

#pragma once
#include"zombie.h"

class bucketZom: public zombie
{
public:
    bucketZom();
    void advance(int phase) override;
};

#endif // BUCKETZOM_H
