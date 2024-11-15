#include "mainwidget.h"

mainwidget::mainwidget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(1700,956);//设置窗口大小
    this->setWindowTitle("Crazy Arcade");//设置窗口标题
    this->setWindowIcon(QIcon("img/icon.png"));//设置窗口图标

    QPalette palette; //调色板对象
    palette.setBrush(QPalette::Background,QBrush(QPixmap("img/mainwindow.jpg")));//用笔刷画主界面mainwindow背景
    this->setPalette(palette);

//    //标签初始化
//    this->label = new QLabel(this);
//    label->setPixmap(QPixmap("ima/.png"));

    //添加按钮
    this->startbtn= new QPushButton(this);
    this->startbtn->setIcon(QIcon("img/startbtn.png"));
    this->startbtn->setIconSize(QSize(235,90));
    this->startbtn->setFlat(true);
    this->startbtn->move(190,530);

    this->setbtn= new QPushButton(this);
    this->setbtn->setIcon(QIcon("img/setbtn.png"));
    this->setbtn->setIconSize(QSize(235,90));
    this->setbtn->setFlat(true);
    this->setbtn->move(190,630);

    this->helpbtn= new QPushButton(this);
    this->helpbtn->setIcon(QIcon("img/helpbtn.png"));
    this->helpbtn->setIconSize(QSize(235,90));
    this->helpbtn->setFlat(true);
    this->helpbtn->move(190,730);

    this->quitbtn= new QPushButton(this);
    this->quitbtn->setIcon(QIcon("img/quitbtn.png"));
    this->quitbtn->setIconSize(QSize(235,90));
    this->quitbtn->setFlat(true);
    this->quitbtn->move(190,830);


    //设置音频
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    playlist->addMedia(QUrl::fromLocalFile("music/main.wav"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);//设置循环模式
    player->setPlaylist(playlist);//获取将播放列表要播放的文件
    player->setVolume(10);
    player->play();


    //槽函数关联 btn
    this->connect(startbtn,SIGNAL(clicked()),this,SLOT(startbtnclick()));
    this->connect(setbtn,SIGNAL(clicked()),this,SLOT(setbtnclick()));
    this->connect(helpbtn,SIGNAL(clicked()),this,SLOT(helpbtnclick()));
    this->connect(quitbtn,SIGNAL(clicked()),this,SLOT(quitbtnclick()));


    //创建并先隐藏game, set, help widget
    gamew = new gamewidget(this);
    gamew->hide();

    setw = new setwidget(this);
    setw->hide();

    helpw = new helpwidget(this);
    helpw->hide();

    //调节音量
    this->connect(setw,&setwidget::slider_signal,[=](int v){
        player->setVolume(v);
    });


}

mainwidget::~mainwidget()
{
}


//主界面下的一些方法函数定义
void mainwidget::startbtnclick()  //鼠标点击start按钮时，显示游戏界面
{
    gamew->show();
}

void mainwidget::setbtnclick()  //鼠标点击settings按钮时，显示游戏设置界面
{
    setw->show();
}

void mainwidget::helpbtnclick() //鼠标点击help按钮时，显示帮助界面
{
    helpw->show();
}

void mainwidget::quitbtnclick() //鼠标点击quit按钮时，显示对话框是否结束游戏
{
    if(QMessageBox::Yes==QMessageBox::question(this,"Question","Quit the game?",QMessageBox::Yes|QMessageBox::No))
    {
        this->close();
    }

}


