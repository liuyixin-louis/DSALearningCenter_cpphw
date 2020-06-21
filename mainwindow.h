#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<keshihua.h>
#include <ziliao.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


signals:
    void view_on();
    void view_hide();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void BackToMain();
    void BackToMain_2();

public slots:
    void enter_keshihua();
    void enter_ziliao();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    keshihua k;
    ziliao z;
};
#endif // MAINWINDOW_H
