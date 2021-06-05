#include "store.h"
#include"card.h"
#include"sun.h"
#include"sunflower.h"
#include"plant.h"
#include"pea.h"
#include"nut.h"
#include"icepea.h"
#include"potato.h"
#include "pumpkin.h"
#include "highnut.h"
#include "garlic.h"
#include"cherrybomb.h"
#include"bipea.h"
#include"peashooter.h"
#include<QDebug>

store::store()
{
    //初始阳光
    sun = 1000;
    counter = 0;
    //设置counter的上限
    time = int(200);
    card *Card = nullptr;
    //初始化各个卡片
    for (int i = 0; i < card::name.size(); ++i)
    {
        Card = new card(card::name[i]);
        Card->setParentItem(this);
        Card->setPos(-157 + 65 * i, -2);
    }
    for(int i = 0; i < 5; i ++){
        plantNum[i] = 0;
    }
}

QRectF store::boundingRect() const
{
    return QRectF(-270, -45, 540, 90);
}

void store::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->drawPixmap(QRect(-270, -45, 540, 90), QPixmap(":/res/store.png"));
    QFont font;
    //
    font.setPointSizeF(15);
    painter->setFont(font);
    //写上阳光数
    painter->drawText(QRectF(-255, 18, 65, 22), Qt::AlignCenter, QString::number(sun));
}

void store::advance(int phase)
{
    if (!phase){
        //qDebug()<<"!phase";
        return;
    }
    update();
    //到时候增加阳光了
    if (++counter >= time)
    {
        //qDebug()<<"counter ++";
        counter = 0;
        //是时候加阳光了
        scene()->addItem(new Sun);
    }
}

void store::addPlant(QString s, QPointF pos)
{
    QList<QGraphicsItem *> items = scene()->items(pos);
    int cnt = 0;
    foreach (QGraphicsItem *item, items)
        if (item->type() == plant::Type){
            cnt ++;
            plant* P = qgraphicsitem_cast<plant* >(item);
            //不是南瓜头,已经有两个植物了
            if((P ->t != 7 && card::map[s] != 7)|| cnt > 1)
                return;
        }
    int y = int(((pos.y()) - 81) / 98);
    plantNum[y] ++;
    qDebug()<<y;
    sun -= card::cost[card::map[s]];
    plant *Plant = nullptr;
    switch (card::map[s])
    {
    case 0:
        Plant = new sunFlower; break;
    case 1:
        Plant = new peaShooter; break;
    case 2:
        Plant = new cherryBomb; break;
    case 3:
        Plant = new nut; break;
    case 4:
        Plant = new icePea; break;
    case 5:
        Plant = new potato; break;
    case 6:
        Plant = new biPea; break;
    case 7:
        Plant = new pumpkin; break;
    case 8:
        Plant = new highNut; break;
    case 9:
        Plant = new garlic; break;
    }
    Plant->setPos(pos);
    scene()->addItem(Plant);
    QList<QGraphicsItem *> child = childItems();
    foreach (QGraphicsItem *item, child)
    {
        //得到其childitem列表
        card *Card = qgraphicsitem_cast<card *>(item);
        if (Card->text == s)
            //让其冷却
            Card->counter = 0;
    }
    counter = 0;
}

