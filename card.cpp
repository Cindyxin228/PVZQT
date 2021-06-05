#include "card.h"
#include"store.h"
#include<QDebug>

//编号
const QMap<QString, int> card::map = {{"sunFlower", 0}, {"peaShooter", 1}, {"cherryBomb", 2}, {"Nut", 3},
                                      {"icePea", 4}, {"Potato", 5}, {"biPea", 6},{"pumpkin", 7}, {"TallNut", 8}, {"garlic", 9}};
//名字
const QVector<QString> card::name = {"sunFlower", "peaShooter", "cherryBomb", "Nut",
                                     "icePea", "Potato", "biPea", "pumpkin", "TallNut", "garlic"};
//花费阳光数量
const QVector<int> card::cost = {50, 100, 150, 50, 175, 25, 200, 125, 175, 50};
//冷却时间
const QVector<int> card::cool = {226, 226, 600, 600, 226, 600, 226, 226, 600, 226};

card::card(QString s)
{
    //s是名字字符串
    text = s;
    counter = 0;
}

QRectF card::boundingRect() const
{
    return QRectF(-50, -30, 100, 60);
}

void card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //防止编译警告
    Q_UNUSED(option)
    Q_UNUSED(widget)

    //放大比例
    painter->scale(0.6, 0.58);
    //画图
    painter->drawPixmap(QRect(-50, -70, 100, 140), QPixmap(":/res/card.png"));
    painter->drawPixmap(QRect(-35, -42, 70, 70), QPixmap(":/res/" + text + ".png"));
    //写名字
    QFont font;
    font.setPointSizeF(15);
    painter->setFont(font);
    //格式化字符串，写上花费阳光数
    painter->drawText(-30, 60, QString().sprintf("%3d", cost[map[text]]));
    //还没到冷却时间结束
    if (counter < cool[map[text]])
    {
        QBrush brush(QColor(0, 0, 0, 200));
        painter->setBrush(brush);
        //按剩余冷却时间比例来画阴影
        painter->drawRect(QRectF(-48, -68, 98, 132 * (1 - qreal(counter) / cool[map[text]])));
    }
}

void card::advance(int phase)
{
    //用于在冷却和未冷却间切换
    if (!phase){
        //qDebug()<<"!phase";
        return;
    }
    update();
    if (counter < cool[map[text]]){
        //qDebug()<<"counter++";
        ++counter;
    }
}

//点击卡片
void card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //冷却ing，不回应
    if (counter < cool[map[text]])
        event->setAccepted(false);
    store *Store = qgraphicsitem_cast<store *>(parentItem());
    //阳光数量不足，不回应
    if (cost[map[text]] > Store->sun)
        event->setAccepted(false);
    setCursor(Qt::ArrowCursor);
}

//拖拽植物
void card::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //防止用户因为手的抖动等因素造成的鼠标拖动。用户必须将鼠标拖动一段距离之后，
    //我们才认为他是希望进行拖动操作，而这一距离就是 QApplication::startDragDistance() 提供的，这个值通常是 4px
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length()
     >= QApplication::startDragDistance()){
        QDrag *drag = new QDrag(event->widget());
        //QDrag 使用 QMimeData 存储数据。
        QMimeData *mime = new QMimeData;
        //使用 QMimeData::setText() 函数将一个字符串存储为 text/plain 类型的数据
        mime->setText(text);
        QImage image(":/res/" + text + ".png");
        mime->setImageData(image);
        drag->setMimeData(mime);
        //设置拖动发生时鼠标的样式
        drag->setPixmap(QPixmap::fromImage(image));
        //设置指定的点的像素图的左上角的位置
        drag->setHotSpot(QPoint(35, 35));
        //阻塞拖动的操作，直到用户完成操作或者取消操作
        drag->exec();
        //重置样式
        setCursor(Qt::ArrowCursor);
    }
}

void card::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::ArrowCursor);
}

card::card()
{

}
