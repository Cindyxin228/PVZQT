#ifndef PAUSE_H
#define PAUSE_H

#include <QTimer>
#include <QSound>
#include "item.h"

class pause : public item
{
    QSound *sound;
    QTimer *timer;
public:
    pause(QSound *s, QTimer *t);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // PAUSE_H
