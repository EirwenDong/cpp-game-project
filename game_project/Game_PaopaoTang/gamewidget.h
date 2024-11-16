#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QIcon>
#include <QBrush>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QResizeEvent>

class gamewidget : public QWidget
{
    Q_OBJECT
public:
    explicit gamewidget(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent *event);

private:
    QPushButton *returnbtn; //return按钮
    QPushButton *map1;
    QPushButton *map2;
    QPushButton *mode1;
    QPushButton *mode2;
    QPushButton *ctn;
    QLabel *maplabel;
    QLabel *modelabel;
    QLabel *moderemind;
    QLabel *mapremind;
    QVBoxLayout *mapvout;
    QVBoxLayout *modevout;
    QVBoxLayout *remindout;
    QHBoxLayout *hout;

    int gamemap=0;
    int gamemode=0;



public slots:
    void returnbtnclick(); //自定义槽函数，点击return按钮返回主界面

};

#endif // GAMEWIDGET_H
