#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <keshihua.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("主界面");
    connect(&k,&keshihua::backToMain,this,&MainWindow::BackToMain);
    connect(&z,&ziliao::backToMain,this,&MainWindow::BackToMain_2);
    connect (this,&MainWindow::view_on,&k,&keshihua::view_show);
    connect (this,&MainWindow::view_hide,&k,&keshihua::view_hide);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::enter_keshihua()
{
    emit view_on();
    this->hide();
    k.show();
}


void MainWindow::BackToMain(){
    emit view_hide();
    k.hide();
    this->show();
}

void MainWindow::BackToMain_2(){
    z.hide();
    this->show();
}



void MainWindow::enter_ziliao()
{
    this->hide();
    z.show();
}

void MainWindow::on_pushButton_clicked()
{
    enter_keshihua();
}


void MainWindow::on_pushButton_2_clicked()
{
    enter_ziliao();
}
