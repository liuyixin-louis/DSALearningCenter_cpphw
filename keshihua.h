#ifndef KESHIHUA_H
#define KESHIHUA_H
#include <QWidget>
//#include <ui_keshihua.h>
#include <QPaintEvent>
#include <customview.h>
#include <customscene.h>
#include <customitem.h>
#include <seqlist.h>
#include "exercise.h"

namespace Ui {
    class keshihua;
}

class keshihua : public QWidget
{
    Q_OBJECT

public:
    explicit keshihua(QWidget *parent = nullptr);
//    void paintEvent(QPaintEvent *event);
    ~keshihua();
    //    CustomView *view = new CustomView(this);
    //    CustomScene scene;
    //    CustomItem *item = new CustomItem;
    void view_show();
    void view_hide();
    void slotAddTextItem(QString text);
    void AddListItem(QString text);
    QGraphicsRectItem* gen_List_Rect_Item();
    QGraphicsTextItem* gen_List_Text_Item(QString text);
    void backtoKeshi();
    void PassCodeToEx();


signals:
    void backToMain();
    void donghuaDEBUG();


public slots:
    void on_pushButton_clicked();
    void slotAddRectItem(QString text);
    void slotClear();


private slots:
    void on_pushButton_17_clicked();
    void on_pushButton_15_clicked();
//    void on_comboBox_11_currentTextChanged(const QString &arg1);
//    void on_comboBox_11_textActivated(const QString &arg1);


//    void on_comboBox_11_activated(const QString &arg1);

    void on_comboBox_11_currentTextChanged(const QString &arg1);

    void on_pushButton_16_clicked();

public:
//    SeqList<int> seqlist;
    QString currentType;
    //数据结构-顺序表
    QList<int> *list= new QList<int>;
    qreal listx;
    qreal listy;
    SeqList *seqlist = new SeqList ();
    QString code;




private:
    Ui::keshihua *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    exercise e;

};

#endif // KESHIHUA_H
