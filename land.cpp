#include "land.h"
#include"remove.h"

land::land()
{
    //accept drag and drop events
    setAcceptDrops(true);
}

QRectF land::boundingRect() const{
    return QRectF(-369, -235, 738, 470);
}

//为了在drag的时候实现特殊的操作必须重写相关函数
//如果事件被接受，项目将在控件返回到事件循环之前接收一个拖动事件。（是否接受事件，在card.cpp中根据阳光是否满足，以及冷却是否满足已经过滤一遍了
void land::dragEnterEvent(QGraphicsSceneDragDropEvent *ev) {
    //card接受了mousemove之后有存储相应的名字
    if (ev->mimeData()->hasText())
    {
        ev->setAccepted(true);
        update();
    }
    else
        ev->setAccepted(false);
}

//鼠标离开后的事件
void land::dragLeaveEvent(QGraphicsSceneDragDropEvent *ev) {
    Q_UNUSED(ev);
    //种了植物，准备要更新场景
    update();
}

//Items can only receive drop events if the last drag move event was accepted
void land::dropEvent(QGraphicsSceneDragDropEvent *ev) {
    //card接受了mousemove之后有存储相应的名字
    if (ev->mimeData()->hasText())
    {
        //存储名字
        QString s = ev->mimeData()->text();
        //存储放下时候的位置
        QPointF pos = mapToScene(ev->pos());
        pos.setX((int(pos.x()) - 249) / 82 * 82 + 290);
        pos.setY((int(pos.y()) - 81) / 98 * 98 + 130);
        if (s == "remove"){
            Remove *re = qgraphicsitem_cast<Remove *>(scene()->items(QPointF(100, 15))[0]);
            re->removePlant(pos);
        }else{
            store *Store = qgraphicsitem_cast<store *>(scene()->items(QPointF(300, 15))[0]);
            Store->addPlant(s, pos);
        }
    }
    update();
}

//为了过编译
void land::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

