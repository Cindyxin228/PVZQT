#include "pause.h"


pause::pause(QSound *s, QTimer *t){
    sound = s;
    timer = t;
}

QRectF pause::boundingRect() const{
    return QRectF(-80, -20, 160, 40);
}

void pause::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(-80, -20, 160, 40), QPixmap(":/res/Button.png"));
    //设置绿色
    painter->setPen(Qt::green);
    QFont font("Helvetica", 19, QFont::Bold, true);
    painter->setFont(font);
    //游戏在继续
    if (timer->isActive())
        painter->drawText(boundingRect(), Qt::AlignCenter, "PAUSE");
    else
        painter->drawText(boundingRect(), Qt::AlignCenter, "CONTINUE");
}

void pause::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (event->button() == Qt::LeftButton)
    {
        if (timer->isActive())
        {
            sound->stop();
            timer->stop();
        }
        else
        {
            sound->play();
            timer->start();
        }
    }
    update();
}
