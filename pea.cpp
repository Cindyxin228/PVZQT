#include "pea.h"
#include"config.h"
#include"zombie.h"
#include<QDebug>

pea::pea()
{

}

pea::pea(int Power, bool Flag){
    power = Power;
    ifIce = Flag;
    speed = peaSpeed;
}

QRectF pea::boundingRect() const {
    return QRectF(-12, -28, 24, 24);
}

void pea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QPixmap pix;
    if(ifIce == true){
        pix.load(":/res/iceBean.png");
    }
    else{
        pix.load(":/res/bean.png");
    }
    painter->drawPixmap(QRect(-12, -28, 24, 24), pix);
}

bool pea::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const{
    Q_UNUSED(mode)
    //碰到僵尸
    return other->type() == zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 15;
}

void pea::advance(int phase) {
    if (!phase)
            return;
    update();
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        //随意打范围内任意一个僵尸
        zombie *Zombie = qgraphicsitem_cast<zombie *>(items[qrand() % items.size()]);
        Zombie->life -= power;
        qDebug()<<Zombie->life;
        //还没被减速
        if (ifIce && Zombie->speed > 1)
            Zombie->speed /= 2;
        delete this;
        return;
    }
    //子弹右移
    setX(x() + speed);
    //超出范围
    if (x() > GAME_WIDTH)
        delete this;
}
