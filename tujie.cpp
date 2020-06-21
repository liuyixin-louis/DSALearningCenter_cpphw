#include "tujie.h"
#include "ui_subwidget.h"

subwidget::subwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::subwidget)
{
    ui->setupUi(this);
}

subwidget::~subwidget()
{
    delete ui;
}
