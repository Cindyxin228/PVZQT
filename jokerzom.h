#ifndef JOKERZOM_H
#define JOKERZOM_H

#pragma once
#include"zombie.h"

class jokerZom: public zombie
{
    int cnt = 0;
public:
    jokerZom();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;   //碰撞检测
};

#endif // JOKERZOM_H
