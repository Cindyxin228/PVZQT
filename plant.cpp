#include "plant.h"
#include "zombie.h"

plant::plant()
{
    movie = nullptr;
    power = counter = state = time = 0;
}

plant::~plant()
{
    delete movie;
}

//矩形范围，用于检测碰撞
QRectF plant::boundingRect() const
{
    return QRectF(-35, -35, 70, 70);
}


//重写绘图事件
void plant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    //绘图事件,当前帧
    painter->drawImage(boundingRect(), movie->currentImage());
}

bool plant::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    //避免编译器警告
    Q_UNUSED(mode)
    //检测是否碰撞
    return other->type() == zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 30;
}

int plant::type() const
{
    //
    return Type;
}

void plant::setMovie(QString path)
{
    //重置movie路径
    if (movie)
        delete movie;
    movie = new QMovie(path);
    movie->start();
}
