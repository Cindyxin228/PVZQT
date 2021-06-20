#include "cherrybomb.h"
#include"store.h"

cherryBomb::cherryBomb(){
    power = cherryPower;
    setMovie(":/res/cherryBomb.gif");
}

QRectF cherryBomb::boundingRect() const{
    return state ? QRectF(-130, -130, 260, 260) : plant::boundingRect();
}

//state 0 walk, 1 attack, 2 dead
void cherryBomb::advance(int phase){
    if (!phase)
            return;
    update();
    //dead
    if (life <= 0){
        delete this;
        store *Store = qgraphicsitem_cast<store *>(scene()->items(QPointF(300, 15))[0]);
        Store->plantNum[int((this->y() - 81) / 98)] --;
    }
    //正常模式结束了准备爆炸
    else if (state == 0 && movie->currentFrameNumber() == movie->frameCount() - 1)
    {
        state = 1;
        setMovie(":/res/Boom.gif");
        QList<QGraphicsItem *> items = collidingItems();
        foreach (QGraphicsItem *item, items)
        {
            zombie *Zombie = qgraphicsitem_cast<zombie *>(item);
            Zombie->life -= power;
            //设置僵尸被炸死的movie
            if (Zombie->life <= 0)
            {
                Zombie->state = 3;
                Zombie->setMovie(":/res/Burn.gif");
            }
        }
    }
    //炸弹爆炸的gif到了最后一帧，删除
    else if (state == 1 && movie->currentFrameNumber() == movie->frameCount() - 1)
        delete this;
}

//爆炸范围
bool cherryBomb::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const{
    Q_UNUSED(mode)
        return other->type() == zombie::Type && QLineF(pos(), other->pos()).length() < 140;
}
