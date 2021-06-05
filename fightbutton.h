#ifndef FIGHTBUTTON_H
#define FIGHTBUTTON_H

#include <QWidget>
#include<QPushButton>
#include<QDebug>
#include <QPropertyAnimation>

class fightButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit fightButton(QWidget *parent = nullptr);
    //构造函数，显示图片的路径
    fightButton(QString normalImg);
    //成员属性，保存图片路径
    QString normalImgPath;
    void zoom1();
    void zoom2();
signals:

};

#endif // FIGHTBUTTON_H
