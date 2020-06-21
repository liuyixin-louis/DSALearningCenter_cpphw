#ifndef ZILIAO_H
#define ZILIAO_H

#include <QWidget>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


namespace Ui {
class ziliao;
}

class ziliao : public QWidget
{
    Q_OBJECT

public:
    explicit ziliao(QWidget *parent = nullptr);
    ~ziliao();


public:
    QSqlDatabase database;
    void connect_db();

signals:
    void backToMain();
public slots:
    void on_pushButton_clicked();

private:
    Ui::ziliao *ui;
};

#endif // ZILIAO_H
