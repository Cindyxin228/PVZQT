#ifndef plant_H
#define plant_H

#pragma once
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>
#include "config.h"

class plant : public QGraphicsItem
{
public:
    int life;       //生命值
    int state;         //状态
    int t;      //类型
    enum { Type = UserType + 1};        //类型值
    plant();
    ~plant() override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    int type() const override;      //返回类型
    void setMovie(QString path);        //设置gif
protected:
    QMovie *movie;
    int power;
    int counter;
    int time;
};

#endif // plant_H
