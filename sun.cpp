#include "sun.h"
#include"store.h"

Sun::Sun()
{
    dest = QPointF(290 + qrand() % (82 * 8), 130 + qrand() % (98 * 5));
    setPos(QPointF(dest.x(), 80));
    speed = 3;
    counter = 0;
    time = int(230);
    movie = new QMovie(":/res/Sun.gif");
    movie->start();
    setAcceptedMouseButtons(Qt::LeftButton);
}

Sun::Sun(QPointF pos)
{
    dest = QPointF(pos.x() + qrand() % 30 - 15, pos.y() + qrand() % 30 + 15);
    setPos(QPointF(dest.x(), pos.y()));
    speed = 3;
    counter = 0;
    time = int(230);
    movie = new QMovie(":/res/Sun.gif");
    movie->start();
    setAcceptedMouseButtons(Qt::LeftButton);
}

Sun::~Sun()
{
    if (movie)
        delete movie;
}

QRectF Sun::boundingRect() const
{
    return QRectF(-35, -35, 70, 70);
}

void Sun::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    //绘制当前帧
    painter->drawImage(boundingRect(), movie->currentImage());
}

void Sun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    //获取scene的store这个item
    store *Store = qgraphicsitem_cast<store *>(scene()->items(QPointF(300, 15))[0]);
    Store->sun += 25;
    //让advance将其删除
    counter = time;
    event->setAccepted(true);
}

void Sun::advance(int phase)
{
    if (!phase)
        return;
    update();
    //超过规定时间还没点or点了
    if (++counter >= time)
        delete this;
    //还没点，要移动
    else if (y() < dest.y())
        setY(y() + speed);
}

