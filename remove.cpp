#include "remove.h"
#include<QDebug>

Remove::Remove(){
}

QRectF Remove::boundingRect() const{
     return QRectF(-40, -40, 80, 80);
}
void Remove::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(-40, -40, 80, 80), QPixmap(":/res/removeBack.png"));
    painter->drawPixmap(QRect(-35, -35, 70, 70), QPixmap(":/res/remove.png"));
}
void Remove::mousePressEvent(QGraphicsSceneMouseEvent *event){
    Q_UNUSED(event)
    setCursor(Qt::ArrowCursor);
    qDebug()<<"press";
}
void Remove::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    //超过一定距离避免手抖
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length() >= QApplication::startDragDistance()){
        QDrag *drag = new QDrag(event->widget());
        QMimeData *mime = new QMimeData;
        QImage image(":/res/remove.png");
        mime->setText("remove");
        mime->setImageData(image);
        //drag设置存储结构
        drag->setMimeData(mime);
        //设置大小
        drag->setPixmap(QPixmap::fromImage(image).scaled(70, 70));
        //这个鼠标的焦点，我们可以通过setHotSpot来指定鼠标在拖动期间在pixmap上的位置
        drag->setHotSpot(QPoint(35, 35));
        drag->exec();
        setCursor(Qt::ArrowCursor);
        qDebug()<<"move";
    }
}
void Remove::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    Q_UNUSED(event)
    setCursor(Qt::ArrowCursor);
    qDebug()<<"release";
}
void Remove::removePlant(QPointF pos){
    QList<QGraphicsItem *> items = scene()->items(pos);
    qDebug()<<"enter remove";
    foreach (QGraphicsItem *item, items)
        //删除对应植物
        if (item->type() == plant::Type)
        {
            delete item;
            qDebug()<<"delete";
            return;
        }

}
