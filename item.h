#ifndef ITEM_H
#define ITEM_H
#pragma once
#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>

class item: public QGraphicsItem
{
public:
    //重新实现该类型type函数,以便对其中的 QGraphicsItem 进行类型检测与转换时以确定实际的 item。
    enum { Type = UserType + 3};
    item();
    int type() const override;
};

#endif // ITEM_H
