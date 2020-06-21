#ifndef EXERCISE_H
#define EXERCISE_H
#include <QHash>
#include <QWidget>

namespace Ui {
class exercise;
}

class exercise : public QWidget
{
    Q_OBJECT

signals:
    void backtokeshihua();
    void startDati();



public:
    explicit exercise(QWidget *parent = 0);
    ~exercise();
    QList<QString> gen_timu(QString code);
    QString code;
    QList<QString> timuku;
    QList<int> timukuIndex;
    void next_exercise();

private slots:
    void on_pushButton_3_clicked();
//    void on_pushButton_4_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::exercise *ui;
    int haveDone=0;
    int rightScore=0;
    QString currentAnswer;
    QString currentTiMu;
    bool use_hind=0;

};

#endif // EXERCISE_H
