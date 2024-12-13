#include "widget.h"
#include "ui_widget.h"



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    btn=new QPushButton;
    btn->setText("点击关闭窗口");
    btn->setParent(this);
    btn->show();
    btn->resize(180,50);
    btn->move(180,150);
    connect(btn,&QPushButton::clicked,this,&Widget::close);
}

Widget::~Widget()
{
    delete ui;

}



