#include "zombie.h"
#include <QDebug>

zombie::zombie()
{
    movie = head = nullptr;
    life = power = 0;
    //状态为行走
    state = 0;
    speed = 0.0;
    life = norLife;
    power = norPower;
    tool = 0;
}

zombie::~zombie()
{
    delete movie;
    delete head;
}

//返回矩形框住的范围，用于碰撞检测
QRectF zombie::boundingRect() const
{
    return QRectF(-80, -100, 200, 140);
}

//重写绘图事件
void zombie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    //当前帧
    QImage image = movie->currentImage();
    //slow
    if (speed < 1 && state != 3)
    {
        if (state != 2)
            //减速一半
            movie->setSpeed(50);
        for (int i = 0; i < image.height(); ++i)
        {
            uchar *line = image.scanLine(i);
            for (int j = 5; j < image.width() - 5; ++j)
                line[j << 2] = 200;
        }
    }
    painter->drawImage(QRectF(-70, -100, 140, 140), image);
    if (head)
    {
        image = head->currentImage();
        if (speed < 1)
        {
            for (int i = 0; i < image.height(); ++i)
            {
                uchar *line = image.scanLine(i);
                for (int j = 5; j < image.width() - 5; ++j)
                    line[j << 2] = 200;
            }
        }
        painter->drawImage(QRectF(0, -100, 140, 140), image);
    }
}

//碰撞检测
bool zombie::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == plant::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 30;
}

int zombie::type() const
{
    return Type;
}

void zombie::setMovie(QString path)
{
    if (movie)
        delete movie;
    movie = new QMovie(path);
    movie->start();
}


void zombie::setHead(QString path)
{
    if (head)
        delete head;
    head = new QMovie(path);
    head->start();
}



