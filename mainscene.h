#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#pragma once
#include <QMouseEvent>
#include"fightbutton.h"
#include"levelscene.h"
#include<QTimer>
#include"config.h"
#include<QPainter>
QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
    void initScene();
    //重写paintevent绘图事件
    void paintEvent(QPaintEvent *ev) override;

    levelScene * chooseLevel = NULL;
private:
    Ui::MainScene *ui;
    QTimer m_Timer;
};
#endif // MAINSCENE_H
