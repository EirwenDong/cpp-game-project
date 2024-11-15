#include "setwidget.h"

setwidget::setwidget(QWidget *parent) : QWidget(parent)
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

    //添加滑动条
    this->soundslider=new QSlider(Qt::Horizontal,this);
    this->soundslider->move(300,300);
    this->soundslider->setFixedSize(1100,200);
    this->soundslider->setMaximum(100);
    this->soundslider->setMinimum(0);
    this->soundslider->setValue(10);
    this->soundslider->setStyleSheet("QSlider::groove:horizontal{\
                                                border: 6px solid #80c23a;\
                                                backgound:#f0db90;\
                                                height:60px; \
                                                width:1000;\
                                                left:30px;\
                                                right:30px;\
                                                border-radius:10px;\
                                                  }\
                                      QSlider::sub-page:horizontal{\
                                                background:#85d92e;\
                                                margin:5px;\
                                                  }\
                                      QSlider::add-page:horizontal{\
                                                background:#a8e06e;\
                                                margin:5px;\
                                                  }\
                                      QSlider::handle:horizontal{\
                                               width:120px;\
                                               margin: -30px -60px -30px -60px;\
                                               border-image: url(img/qslider_btn.png);\
                                               }\
                           ");
    //添加文字说明
    this->soundlabel=new QLabel(this);
    this->soundlabel->setText("Use the slider to change volume of background music");
    this->soundlabel->move(360,290);
    this->soundlabel->setAlignment(Qt::AlignCenter);
    QFont soundfont("Arial Black",12);
    this->soundlabel->setFont(soundfont);
    QPalette soundpa;
    soundpa.setColor(QPalette::WindowText,QColor(99,179,16));
    this->soundlabel->setPalette(soundpa);


    //点击按钮返回到主界面
    this->connect(returnbtn,SIGNAL(clicked()),this,SLOT(returnbtnclick()));
    //调节滑动条
    //this->connect(soundlabel,SIGNAL(valueChanged(int)),this,SLOT(slider_slot(int)));
    this->connect(soundslider,&QSlider::valueChanged,[=](int v){
       //this->soundlabel->setFont(QFont(QFont("Arial Black",v)));
        emit slider_signal(v);

    });



}
void setwidget::returnbtnclick() //定义returnbtn的方法，隐藏游戏界面以达到返回主界面的效果
{
    this->hide();
}

