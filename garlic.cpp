#include "garlic.h"
#include"store.h"

garlic::garlic()
{
    life = garlicLife;
    t = 9;
    setMovie(":/res/garlic.gif");
}

void garlic::advance(int phase){
    if (!phase)
            return;
    update();
    if (life <= 0){
        store *Store = qgraphicsitem_cast<store *>(scene()->items(QPointF(300, 15))[0]);
        Store->plantNum[int((this->y() - 81) / 98)] --;
        delete this;
    }
    else if (life > nutLife/4 && life < nutLife/2){
        setMovie(":/res/garlic1.gif");
    }
    //生命不足一半但还没死
    else if (life <= nutLife/3){
        setMovie(":/res/garlic2.gif");
    }

}

bool garlic::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const {
    Q_UNUSED(mode)
    return other->type() == zombie::Type && qFuzzyCompare(other->y(), y());
}
