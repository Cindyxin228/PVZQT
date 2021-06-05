#ifndef LEVELSCENE_H
#define LEVELSCENE_H

#pragma once
#include <QMainWindow>
#include<QMenuBar>
#include<QPainter>
#include"fightbutton.h"
#include"config.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSound>
#include <QTimer>
#include"zombie.h"

class levelScene : public QMainWindow
{
    Q_OBJECT
    QSound *sound;
    QTimer* timer;
    QGraphicsScene* scene;
    QGraphicsView* view;
public:
    explicit levelScene(QWidget *parent = nullptr);
    //重写paintevent绘图事件
    ~levelScene() override;
    void addZom();
    void check();
    void timerBegin();
    void paintEvent(QPaintEvent *ev) override;
signals:
    //自定义信号，告诉主场景，点了返回
    void chooseSceneBack();

};

#endif // LEVELSCENE_H
