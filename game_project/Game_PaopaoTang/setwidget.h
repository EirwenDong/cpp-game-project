#ifndef SETWIDGET_H
#define SETWIDGET_H

#include <QWidget>
#include <QIcon>
#include <QBrush>
#include <QLabel>
#include <QPushButton>

class setwidget : public QWidget
{
    Q_OBJECT
public:
    explicit setwidget(QWidget *parent = nullptr);

private:
    QPushButton *returnbtn; //return按钮

public slots:
    void returnbtnclick(); //自定义槽函数，点击return按钮返回主界面

};

#endif // SETWIDGET_H
