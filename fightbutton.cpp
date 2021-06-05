#include "fightbutton.h"

//fightButton::fightButton(QWidget *parent) : QWidget(parent)
//{

//}

fightButton::fightButton(QString normalImg){
    this->normalImgPath = normalImg;

    QPixmap pix;
    bool ret = pix.load(normalImg);
    pix = pix.scaled(pix.width()*1.5, pix.height()*1.5);
    if(!ret){
        qDebug()<<"图片加载失败";
        return;
    }

    //设置图片固定大小
    this->setFixedSize(pix.width(), pix.height());

    //设置不规则图片的样式
    this->setStyleSheet("QPushButton{border:0px;}");

    //设置图标
    this->setIcon(pix);

    //设置图标大小
    this->setIconSize(QSize(pix.width(), pix.height()));
}

void fightButton::zoom1(){
    //创建动画对象
    QPropertyAnimation* animation1 = new QPropertyAnimation(this, "geometry");
    //设置时间间隔，单位ms
    animation1->setDuration(300);
    //创建起始位置
    animation1->setStartValue(QRect(this->x(),this->y(), this->width(), this->height()));

    //创建结束位置
    animation1->setEndValue(QRect(this->x(), this->y()+10, this->width(), this->height()));

    //设置缓和曲线
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    animation1->start();
}

void fightButton::zoom2(){
    //创建动画对象
    QPropertyAnimation* animation1 = new QPropertyAnimation(this, "geometry");
    //设置时间间隔，单位ms
    animation1->setDuration(300);
    //创建起始位置
    animation1->setStartValue(QRect(this->x(),this->y() + 10, this->width(), this->height()));

    //创建结束位置
    animation1->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));

    //设置缓和曲线
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    animation1->start();
}
