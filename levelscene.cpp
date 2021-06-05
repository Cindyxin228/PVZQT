#include "levelscene.h"
#include<QTime>
#include"remove.h"
#include"store.h"
#include"norzom.h"
#include"hatzom.h"
#include"rodzom.h"
#include"jokerzom.h"
#include"car.h"
#include"pause.h"
#include"paperzom.h"
#include"land.h"
#include"footballzom.h"
#include"bucketzom.h"
#include"screenzom.h"
#include<QDebug>

levelScene::levelScene(QWidget *parent) : QMainWindow(parent)
{
    //配置选择关卡场景
    this->setFixedSize(GAME_WIDTH, GAME_HEIGHT);
    //设置图标
    this->setWindowIcon(QIcon(":/res/icon.jpg"));
    //设置标题
    this->setWindowTitle(FIGHT1);
    //创建菜单栏
    QMenuBar* bar = menuBar();
    setMenuBar(bar);
    //创建开始菜单
    QMenu* startMenu = bar->addMenu("开始");
    //创建退出菜单项
    QAction* quitAction = startMenu->addAction("退出");
    //点击退出 实现退出游戏
    connect(quitAction, &QAction::triggered, [=]{
        this->close();
    });

    //返回主菜单
    fightButton* backBtn = new fightButton(":/res/pause_botton.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), 0);
    //点击返回
    connect(backBtn, &fightButton::clicked, [=]{
        //主场景监听它的返回按钮
        emit this->chooseSceneBack();
    });


    //生成随机数
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    //音乐
    sound = new QSound(":/Grazy Dave.wav");
    //循环播放
    sound->setLoops(QSound::Infinite);
    sound->play();

    //定时器
    timer = new QTimer;
    //绑到目前的场景上
    scene = new QGraphicsScene(this);
    //定义了场景的范围
    scene->setSceneRect(0,0,GAME_WIDTH, GAME_HEIGHT);
    //不添加索引，应用于动态场景
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    //暂停按钮
    pause *Pause = new pause(sound, timer);
    Pause->setPos(90, 20);
    scene->addItem(Pause);

    //设置铲子
    Remove *re = new Remove;
    re->setPos(210, 40);
    scene->addItem(re);


    //商店
    store *Store = new store;
    //卡牌位置
    Store->setPos(520, 50);
    //场景增加
    scene->addItem(Store);
    //视图上绑上这个场景

    land *Land = new land;
    Land->setPos(618, 326);
    scene->addItem(Land);

    //设置小推车
    for (int i = 0; i < 5; ++i){
        car *Car = new car;
        Car->setPos(210, 130 + 98 * i);
        scene->addItem(Car);
    }

    view = new QGraphicsView(scene, this);
    //重置大小
    view->resize(GAME_WIDTH, GAME_HEIGHT);
    //消除锯齿
    view->setRenderHint(QPainter::Antialiasing);
    QPixmap pix;
    pix.load(":/res/court2.jpg");
    pix.scaled(GAME_WIDTH, GAME_HEIGHT);
    //设置场景背景
    view->setBackgroundBrush(pix);
    //缓存预渲染的内容
    view->setCacheMode(QGraphicsView::CacheBackground);
    //只搜索一个区域的更改，将确定需要重绘的内容所花费的时间最小化
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);


    view->show();
}

void levelScene::timerBegin(){
    //定时check
    connect(timer, &QTimer::timeout, this, &levelScene::check);
    //定时更新场景
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    //定时增加僵尸
    connect(timer, &QTimer::timeout, this, &levelScene::addZom);
    //启动或重启超时时间为毫秒的定时器。如果计时器已经在运行，它将停止并重新启动
    timer->start(33);
}


levelScene::~levelScene(){
    delete sound;
    delete timer;
    delete scene;
    delete view;
}

void levelScene::addZom(){
    static int low = 4;
    static int high = 8;
    static int maxtime = 620;
    static int time = maxtime / 2;
    static int counter = 0;
    if (++counter >= time)
    {
       if (++low > high)
       {
           maxtime /= 1.1;
           high *= 2;
       }
       counter = 0;
       time = qrand() % (maxtime / 2) + 1/2 * maxtime;
       int type = qrand() % 100;
       zombie *Zombie = nullptr;
//       if (type < 40)
//          Zombie = new norZom;
//        else if(type < 50)
//          Zombie = new jokerZom;
//        else if(type < 60)
//           Zombie = new rodZom;
//        else if (type < 70)
//          Zombie = new paperZom;
//         else if (type < 80)
//          Zombie = new bucketZom;
//        else if (type < 90)
//          Zombie = new screenZom;
//        else
          Zombie = new footballZom;
       int i = qrand() % 5;
       Zombie->setPos(GAME_WIDTH, 130 + 98 * i);
       scene->addItem(Zombie);
    }
}

void levelScene::paintEvent(QPaintEvent *ev){
    Q_UNUSED(ev);
//    QPainter painter(this);
//    QPixmap pix;
//    pix.load(":/res/court2.jpg");
//    painter.drawPixmap(0, 0 , this->width(), this->height(), pix);
//    QPixmap pix1;
//    pix1.load(":/res/board.png");
//    painter.drawPixmap(300, 22, 600, 90, pix1);
}


//
void levelScene::check(){
    static int time = 33;
    static int counter = 0;
    //到时候check了
    if (++counter >= time)
    {
        counter = 0;
        const QList<QGraphicsItem *> items = scene->items();
        foreach (QGraphicsItem *item, items)
            if (item->type() == zombie::Type && item->x() < 200)
            {
                //输了
                scene->addPixmap(QPixmap(":/res/lost.png"))->setPos(336, 92);
                //使scene中所有item更新
                scene->advance();
                //游戏结束，timer停止了
                timer->stop();
                return;
            }
    }
}
