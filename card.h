#ifndef CARD_H
#define CARD_H

#include "item.h"
#pragma once
#include<QString>
#include<QMap>
#include<QVector>
#include<QPainter>
#include <QMimeData>
#include <QDrag>
#include <QLineF>

class card: public item
{
public:
    card();
    int counter;
    QString text;
    card(QString s);
    const static QMap<QString, int> map;
    const static QVector<QString> name;
    const static QVector<int> cost;
    const static QVector<int> cool;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // CARD_H
