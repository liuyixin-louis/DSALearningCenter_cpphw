#include "ziliao.h"
#include "ui_ziliao.h"


ziliao::ziliao(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ziliao)
{
    ui->setupUi(this);
    setWindowTitle("博客资料区");


}

ziliao::connect_db(){
    // 尝试连接
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("db.db");
    }

    // 尝试打开
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }
    else
    {
        // do something
        qDebug() << "succeed!";
    }

}


ziliao::~ziliao()
{
    delete ui;
}

void ziliao::on_pushButton_clicked()
{
    emit backToMain();
}
