#include "helpwidget.h"

helpwidget::helpwidget(QWidget *parent) : QWidget(parent)
{
    this->resize(1700,956);//设置窗口大小
    this->setWindowTitle("Crazy Arcade");//设置窗口标题
    this->setWindowIcon(QIcon("img/icon.png"));//设置窗口图标
    this->setAutoFillBackground(true);//当游戏界面显示的时候，完全覆盖主界面

    QPalette palette; //调色板对象
    palette.setBrush(QPalette::Background,QBrush(QPixmap("img/gamewindow.jpg")));//用笔刷画mainwindow背景
    this->setPalette(palette);

    //添加按钮
    this->returnbtn= new QPushButton(this);
    this->returnbtn->setIcon(QIcon("img/returnbtn.png"));
    this->returnbtn->setIconSize(QSize(235,90));
    this->returnbtn->setFlat(true);
    this->returnbtn->move(1400,820);

    //点击按钮返回到主界面
    this->connect(returnbtn,SIGNAL(clicked()),this,SLOT(returnbtnclick()));

}
void helpwidget::returnbtnclick() //定义returnbtn的方法，隐藏游戏界面以达到返回主界面的效果
{
    this->hide();
}
