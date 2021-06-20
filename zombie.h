#ifndef ZOMBIE_H
#define ZOMBIE_H

#pragma once
#include"plant.h"
#include <QVector>
#include <QString>
#include"config.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>

class zombie : public QGraphicsItem
{
protected:
    int power; // 僵尸攻击力
    int tool;       //工具
    QMovie *movie;  //身体动画
    QMovie *head;   //头动画
public:
    int life; // 剩余生命力
    int state;  //状态
    enum { Type = UserType + 2};
    qreal speed; // 行走速度
    zombie();
    ~zombie() override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    int type() const override;
    //重置movie路径
    void setMovie(QString path);
    void setHead(QString path);
};



#endif // ZOMBIE_H
