#include "exercise.h"
#include "ui_exercise.h"
#include <QDebug>
#include <QTime>
#include <QMessageBox>


exercise::exercise(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::exercise)
{
    ui->setupUi(this);
    setWindowTitle("练习区");
//    emit startDati();
//    // 初始化题库、分割题目
    qDebug()<<code;
//    QString code_ = this->code;
//    this->ui->textBrowser->setText(code_);
//    QRegExp reg("/n[^\\x4e00-\\x9fa5]+;");
//    reg.setMinimal(true);
//    for(int pos=0;pos=reg.indexIn(code_,pos),pos>=0; pos+=reg.matchedLength())
//    {
//       QString timu;
//       QString answer;
//       timu = code_.replace(pos,reg.pos(0).length(),"/n*****请填空*******");
//       answer = reg.cap(0).trimmed();
//       qDebug()<<timu; //返回查找到序号
//       qDebug()<<answer;//返回匹配到的字串
//       timuku.insert(timu,answer);
//    }
    
}

void exercise::next_exercise(){
    //1.生成随机数
    int l = timuku.length();
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int r = qrand()%l;

    //2.随机取一个模式
    QString timu = timuku[r];
    QString tempCode = code;
    QString TiMuCode = tempCode.replace(timukuIndex[r],timu.length(),"*******题目在此，请在答题区作答*********");


    //3.保存及显示
    currentTiMu = r;
    currentAnswer = timu;
    ui->textBrowser->setText(TiMuCode);


    qDebug()<< currentAnswer;

//    it  = timuku.begin();
//    it += r;
//    currentTiMu = it->first;
//    currentAnswer = it->second;
//    this->ui->textBrowser->setText(currentTiMu);
}

exercise::~exercise()
{
    delete ui;
}

void exercise::on_pushButton_3_clicked()
{
    emit backtokeshihua();
    this->ui->pushButton_4->setDisabled(false);
    currentAnswer="";
    currentTiMu= -1;
    this->ui->textBrowser->setText("");
    this->ui->label->setText("您当前累计答题0道，其中答对0道，加油~！");
    haveDone = 0;
    rightScore = 0;
    use_hind = 0;
}

#include <QRegExp>

QList<QString> exercise::gen_timu(QString code){
  //出题，匹配一个 "/nxxx;"的模式，并且生成一段遮挡住的字符串和对应的答案;

   //1.匹配模式，找到出题的点

//   QRegExp reg("/n[^\\x4e00-\\x9fa5]+;");
//   reg.setMinimal(true);

   //2.生成题目（出题的行用*挡住）


   //3.记录答案


   //4.放回题目和答案
}

//void exercise::on_pushButton_4_clicked()
//{
    
    
////    this->ui->textBrowser->setText(this->code);

//}

void exercise::on_pushButton_4_clicked()
{
    ui->pushButton_4->setDisabled(true);
    ui->textBrowser->setText(code);
//    QRegExp reg("/n[^\\x4e00-\\x9fa5]+;");
//    QString code = "/n123;/n456;";
    QRegExp reg("\n[^\\x4e00-\\x9fa5]+;");
    reg.setMinimal(true);
    qDebug()<<code;
    for(int pos=0;pos=reg.indexIn(code,pos),pos>=0; pos+=reg.matchedLength())
    {
//       timu = code.replace(pos,reg.pos(0).length(),"/n*****请填空*******");
//       answer = reg.cap(0).trimmed();
       qDebug()<<pos; //返回查找到序号
       qDebug()<<reg.cap(0);//返回匹配到的字串
//       timuku.append();
       timuku.append(reg.cap(0));
       timukuIndex.append(pos);
    }
    next_exercise();

}

void exercise::on_pushButton_clicked()
{
    //1.提交的答案
    QString HandInAnswer = ui->plainTextEdit->toPlainText();
    qDebug()<< HandInAnswer;
    qDebug()<< currentAnswer;

    //2.提交和答案对比
    int res = 0; //1代表没有用提示答对，2代表答错，3代表答对但是用了提示
    if(HandInAnswer.simplified()==currentAnswer.simplified()){
        //匹配成功
        if(!use_hind){
            res = 1;
        }else{
            res = 3;
        }
    }
    else{
        res = 2;
    }

    //3.将结果记录下来，更新成就区
    if(res==1){
        rightScore++;
        QMessageBox message(QMessageBox::NoIcon, " 恭喜你", "恭喜你，答对了！自动进入下一道题");
        message.exec();
    }else if(res==2){
        QMessageBox message(QMessageBox::NoIcon, "很遗憾", "很遗憾，您的作答有误，请重新尝试");
        message.exec();
        return;
    }else{
        QMessageBox message(QMessageBox::NoIcon, "恭喜你", "您在提示的帮助下成功作答！自动进入下一道题");
        message.exec();
    }

    // 成就区
    haveDone++;
    QString tishi = "您当前累计答题"+QString::number(haveDone)+"道，其中答对"+QString::number(rightScore)+"道，加油~！";
    this->ui->label->setText(tishi);

    //4.进入下一道题
    use_hind=0;
    next_exercise();
    this->ui->plainTextEdit->setPlainText("");
}

void exercise::on_pushButton_2_clicked()
{
    use_hind=1;
    this->ui->plainTextEdit->setPlainText(this->currentAnswer);
}
