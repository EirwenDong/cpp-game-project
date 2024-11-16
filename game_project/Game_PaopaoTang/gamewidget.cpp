#include "gamewidget.h"

gamewidget::gamewidget(QWidget *parent) : QWidget(parent)
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
    this->returnbtn->setStyleSheet("border:0px");

    //添加地图按钮 模式按钮 文字说明
    //文字说明
    this->maplabel=new QLabel(this);
    this->maplabel->setText("Choose Game Map");
    this->maplabel->setFont(QFont(QFont("Arial Black",20)));
    QPalette pa;
    pa.setColor(QPalette::WindowText,QColor(99,179,16));
    this->maplabel->setPalette(pa);

    this->modelabel=new QLabel(this);
    this->modelabel->setText("Choose Game Mode");
    this->modelabel->setFont(QFont(QFont("Arial Black",20)));
    pa.setColor(QPalette::WindowText,QColor(99,179,16));
    this->modelabel->setPalette(pa);


    this->mapremind=new QLabel(this);
    this->mapremind->setText("Game Map:            ");
    this->mapremind->setFont(QFont(QFont("Consolas",12)));

    this->moderemind=new QLabel(this);
    this->moderemind->setText("Game Mode:            ");
    this->moderemind->setFont(QFont(QFont("Consolas",12)));

    //按钮
    this->map1=new QPushButton(this);
    this->map1->setIcon(QIcon("img/map1.jpg"));
    this->map1->setIconSize(QSize(412,395));
    this->map1->setFlat(true);
    //this->map1->setStyleSheet("border:0px");

    this->map2=new QPushButton(this);
    this->map2->setIcon(QIcon("img/map2.jpg"));
    this->map2->setIconSize(QSize(412,395));
    this->map2->setFlat(true);
    //this->map2->setStyleSheet("border:0px");

    this->mode1=new QPushButton(this);
    this->mode1->setIcon(QIcon("img/mode1.png"));
    this->mode1->setIconSize(QSize(232,133));
    this->mode1->setFlat(true);
    //this->mode1->setStyleSheet("border:0px");

    this->mode2=new QPushButton(this);
    this->mode2->setIcon(QIcon("img/mode2.png"));
    this->mode2->setIconSize(QSize(242,242));
    this->mode2->setFlat(true);
    //this->mode2->setStyleSheet("border:0px");

    this->ctn = new QPushButton(this);
    this->ctn->setIcon(QIcon("img/ctn.png"));
    this->ctn->setIconSize(QSize(235,90));
    this->ctn->setFlat(true);
    this->ctn->move(1400,700);
    //this->ctn->setStyleSheet("border:0px");

    //布局
    mapvout= new QVBoxLayout();
    //mapvout->setDirection(QBoxLayout::TopToBottom);
    //hout->addStretch(1);
    //mapvout->addWidget(this->map1,1,Qt::AlignCenter);
    mapvout->addWidget(this->maplabel);
    mapvout->addWidget(this->map1);
    mapvout->addStretch(1);
    mapvout->addWidget(this->map2);
    mapvout->addStretch(2);

    modevout= new QVBoxLayout();
    //modevout->setDirection(QBoxLayout::TopToBottom);
    //hout->addStretch(1);
    modevout->addWidget(this->modelabel);
    modevout->addStretch(1);
    modevout->addWidget(this->mode1);
    modevout->addStretch(1);
    modevout->addWidget(this->mode2);
    modevout->addStretch(1);

    remindout=new QVBoxLayout();
    remindout->addStretch(1);
    remindout->addWidget(this->mapremind);
    remindout->addWidget(this->moderemind);
    remindout->addWidget(this->ctn);
    remindout->addStretch(1);


    hout= new QHBoxLayout();
    hout->addLayout(mapvout);
    hout->setSpacing(35);
    hout->addLayout(modevout);
    hout->addLayout(remindout);
    hout->addStretch(1);
    this->setLayout(hout);


    //点击按钮返回到主界面
    this->connect(returnbtn,SIGNAL(clicked()),this,SLOT(returnbtnclick()));
    //点击选择地图和模式
    this->connect(this->map1,&QPushButton::clicked,[=](){
        mapremind->setText("Game Map: Map 1");
        gamemap=1;
    });


    this->connect(this->map2,&QPushButton::clicked,[=](){
        mapremind->setText("Game Map: Map 2");
        gamemap=2;
    });

    this->connect(this->mode1,&QPushButton::clicked,[=](){
        moderemind->setText("Game Mode: One Player ");
        gamemode=1;
    });

    this->connect(this->mode2,&QPushButton::clicked,[=](){
        moderemind->setText("Game Mode: Two Players");
        gamemode=2;
    });

    this->connect(this->ctn,&QPushButton::clicked,[=](){
        if (gamemap==1 && gamemode==1){

        }
        else if (gamemap==1 && gamemode==2){

        }
        else if (gamemap==2 && gamemode==1){

        }
        else if (gamemap==2 && gamemode==2){

        }
    });

}

void gamewidget::returnbtnclick() //定义returnbtn的方法，隐藏游戏界面以达到返回主界面的效果
{
    this->hide();
}

void gamewidget::resizeEvent(QResizeEvent *event){
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("img/gamewindow.jpg").scaled(event->size())));
    this->setPalette(palette);

    this->returnbtn->move(0.80*this->width(),0.86*this->height());
    this->returnbtn->resize(QSize(0.14*this->width(),0.09*this->height()));
    this->returnbtn->setIconSize(QSize(QSize(0.14*this->width(),0.09*this->height())));

    //this->ctn->resize(QSize(0.14*this->width(),0.09*this->height()));
    //this->ctn->setIconSize(QSize(QSize(0.14*this->width(),0.09*this->height())));
}
