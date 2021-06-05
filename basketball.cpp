#include "basketball.h"
#include"plant.h"
#include"zombie.h"
#include"config.h"
#include"store.h"

basketBall::basketBall(){
    power = basketballPower;
    speed = basketBallSpeed;
}

QRectF basketBall::boundingRect() const {
    return QRectF(-12, -28, 24, 24);
}

void basketBall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QPixmap pix;
    pix.load(":/res/basketball.png");
    painter->drawPixmap(QRect(-12, -28, 24, 24), pix);
}

bool basketBall::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const{
    Q_UNUSED(mode)
    //碰到僵尸
    return other->type() == plant::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 15;
}

void basketBall::advance(int phase) {
    if (!phase)
            return;
    update();
    setX(x() - speed);
    qDebug()<<"speed";
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        plant *Plant = qgraphicsitem_cast<plant *>(items[0]);
        if(items.size() > 1 && Plant ->t == 7){
            Plant = qgraphicsitem_cast<plant* >(items[1]);
        }
        Plant->life -= power;
        delete this;
    }
    //超出范围
    if (x() < 0)
        delete this;
}

