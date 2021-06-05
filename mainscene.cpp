#include "mainscene.h"
#include "ui_mainscene.h"

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::initScene(){
    //初始化窗口大小
    this->setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    //设置窗口标题
    this->setWindowTitle(GAME_TITLE);
    this->setWindowIcon(QIcon(":/res/icon.jpg"));
    m_Timer.setInterval(GAME_RATE);

    //关卡按钮
    fightButton* startBtn = new fightButton(":/res/fight_1_botton_img.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.6, this->height()*0.32);

    //关卡选择
    chooseLevel = new levelScene;

    //监听选择关卡的返回按钮信号
    connect(chooseLevel, &levelScene::chooseSceneBack, this, [=](){
        chooseLevel->hide();        //将选择关卡
        this->show();
    });

    connect(startBtn, &fightButton::clicked, [=](){
        startBtn->zoom1();
        startBtn->zoom2();

        //延时进入
        QTimer::singleShot(100, this, [=](){
            //进入到选择关卡场景中，自身隐藏
            this->hide();
            chooseLevel->timerBegin();
            chooseLevel->show();
        });
    });
    //playGame();
}

void MainScene::paintEvent(QPaintEvent *ev){
    Q_UNUSED(ev);
    QPainter painter(this);
    QPixmap start_back;
    start_back.load(":/res/start.png");
    painter.drawPixmap(0, 0 , this->width(), this->height(), start_back);
    //painter.drawPixmap(0, 0 , this->width(), this->height(), mmap.background);
    //painter.drawPixmap(300, 0, 600, 90, mmap.gamestore);

}


