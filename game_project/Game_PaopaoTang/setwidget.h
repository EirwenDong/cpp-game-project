#ifndef SETWIDGET_H
#define SETWIDGET_H

#include <QWidget>
#include <QIcon>
#include <QBrush>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QFont>
#include <QDebug>
#include <QVBoxLayout>

#include <QResizeEvent>

class setwidget : public QWidget
{
    Q_OBJECT
public:
    explicit setwidget(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent *event);

private:
    QPushButton *returnbtn; //return按钮
    QLabel *soundlabel;
    QSlider *soundslider;
    QVBoxLayout *gameout;

public slots:
    void returnbtnclick(); //自定义槽函数，点击return按钮返回主界面
signals:
    void slider_signal(int);

};

#endif // SETWIDGET_H
