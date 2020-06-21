#include "mainwindow.h"
#include <QTime>
#include <QApplication>
#include <QDebug>
#include <stdio.h>
#include <sqlite3.h>


int main(int argc, char *argv[])
{
//   sqlite3 *db;
//   char *zErrMsg = 0;
//   int rc;
//   rc = sqlite3_open("test.db", &db);
//   if( rc ){
//      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//      exit(0);
//   }else{
//      fprintf(stderr, "Opened database successfully\n");
//   }
//   sqlite3_close(db);
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}



//#include "customscene.h"
//#include "customview.h"
//#include "customitem.h"
//#include <QApplication>
//#include <QTime>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

//    CustomScene scene;
//    scene.setSceneRect(-200, -150, 400, 300);
//    for(int i = 0; i < 5; ++i) {
//        CustomItem *item = new CustomItem;
//        item->setPos(i * 50 - 90, -50);
//        scene.addItem(item);
//    }
//    CustomView view;
//    view.setScene(&scene);
//    view.show();

//    return a.exec();
//}

