#include "mainwidget.h"
#include "gamewidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    mainwidget w;  //绘制主界面

    w.show();
    return a.exec();
}
