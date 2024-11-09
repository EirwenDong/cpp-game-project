#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QIcon>
#include <QBrush>
#include <QLabel>
#include <QPushButton>
#include "gamewidget.h"
#include "setwidget.h"
#include "helpwidget.h"
#include <QMessageBox>


class mainwidget : public QWidget //公有继承QWideget
{
    Q_OBJECT

public:
    mainwidget(QWidget *parent = nullptr);
    ~mainwidget();

private:
    QPushButton *startbtn; //按钮 指针类型，内存占用小
    QPushButton *setbtn;
    QPushButton *helpbtn;
    QPushButton *quitbtn;
    gamewidget *gamew;  //界面
    setwidget *setw;
    helpwidget *helpw;

public slots:
    void startbtnclick(); //自定义槽函数 startbtn点击事件到游戏界面
    void setbtnclick(); //setbtn点击事件到游戏设置界面
    void helpbtnclick();//helpbtn点击事件到帮助界面
    void quitbtnclick();//quitbtn点击事件弹出对话框是否关闭游戏


};
#endif // MAINWIDGET_H
