#include "keshihua.h"
#include "ui_keshihua.h"
#include "customscene.h"
#include "customview.h"
#include "customitem.h"
#include <QApplication>
#include <QTime>
#include <QPaintEvent>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QtDebug>
//#include SeqList_h
#include "seqlist.h"



keshihua::keshihua(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::keshihua)
{
    ui->setupUi(this);
    //初始化数据
    listx = -500;
    listy = -500;
//    scene.setSceneRect(443,286 ,695 ,492 );
//    for(int i = 0; i < 5; ++i) {
//        CustomItem *item = new CustomItem;
//        item->setPos(i , 10);
//        scene.addItem(item);
//    }

//    item->setPos(12,12);
//    scene.addItem(item);
//    view->setScene(&scene);
//    view->show();
    setWindowTitle("可视化学习区");
    //view生成和绑定窗口
    view  = ui->graphicsView;
    connect(&e,&exercise::backtokeshihua,this,&keshihua::backtoKeshi);
    connect(&e,&exercise::startDati,this,&keshihua::PassCodeToEx);
    // connect(this ,&keshihua::donghuaDEBUG,this,&keshihua::donghuatest);
    // 加场景
    scene = new QGraphicsScene;
    scene->setSceneRect(-500,-500,1000,1000);

    // 通过view把场景显示出来
    view->setScene(scene);
    view->setMinimumSize(1000,1000);
}



void keshihua::PassCodeToEx(){
    e.code = this->code;
}



void keshihua::backtoKeshi(){
    this->show();
    e.hide();
}

keshihua::~keshihua()
{
    delete ui;
}

void keshihua::view_show(){
    view->show();
}

void keshihua::view_hide(){
    view->hide();
}


void keshihua::slotClear()        	//清除场景中所有的图元
{
    listx = -500;
    listy = -500;
//    seqlist.ClearList(&seqlist);
    QList<QGraphicsItem*> listItem = scene->items();
    while(!listItem.empty())
    {
        scene->removeItem(listItem.at(0));
        listItem.removeAt(0);
    }
}

void keshihua::AddListItem(QString text){
    slotAddRectItem(text);
}

void keshihua::slotAddTextItem(QString text)  		//在场景中加入一个文字图元
{
    QGraphicsTextItem* item = gen_List_Text_Item(text);
//    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setDefaultTextColor(QColor(qrand()%256,qrand()%256,qrand ()%256));
    scene->addItem(item);
    item->setPos(listx+15,listy+15);
}


QGraphicsTextItem* keshihua::gen_List_Text_Item(QString text){
    QFont font("Times",16);
    QGraphicsTextItem *item = new QGraphicsTextItem(text);
//    QColor const q(1,0,0);
//    item->defaultTextColor(q);
    item->setFont(font);
    return item;
}

QGraphicsRectItem* keshihua::gen_List_Rect_Item(){
    QGraphicsRectItem *item = new QGraphicsRectItem(QRectF(0,0, 60,60));
    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setPen(pen);
    item->setBrush(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    return item;
}


void keshihua::slotAddRectItem(QString text)          //在场景中加入一个长方形图元
{
    // 修改Qlist内容
//    seqlist.InsertElement(text.toInt());
    // 修改动画
    QGraphicsRectItem *item = gen_List_Rect_Item();
    item->setPos(listx,listy);
    scene->addItem(item);
    slotAddTextItem(text);
    listx+=60;
//    // 修改Qlist内容
//    list->append(1);
//    listx +=60;
//    // 修改动画
//    for(int i=0;i<list->length();i++){
//        QGraphicsRectItem *item = new QGraphicsRectItem(QRectF(0,0, 60,60));
//        QPen pen;
//        pen.setWidth(3);
//        pen.setColor(QColor(qrand()%256,qrand()%256,qrand()%256));
//        item->setPen(pen);
//        item->setBrush(QColor(qrand()%256,qrand()%256,qrand()%256));
//        item->setFlag(QGraphicsItem::ItemIsMovable);
//        scene->addItem(item);
//        item->setPos((qrand()%int(scene->sceneRect().width()))-200,
//                     (qrand()%int(scene->sceneRect().height()))-200);
//    };
}

//void keshihua::paintEvent(QPaintEvent *event){
//    QWidget::paintEvent(event);
//    QPainter painter(this);
//    QPen pen;
//    pen.setColor(Qt::black);
//    pen.setWidth(1);
//    painter.setPen(pen);
//    int x =28,y = 169;
//    for(int i=0;i<=10;i++){
//        painter.drawRect(x,y,20,20);
//        x += 20;
//    }
//    this->update();
//}

void keshihua::on_pushButton_clicked()
{
    emit backToMain();
}



void keshihua::on_pushButton_17_clicked()
{

//    slotClear();
//     slotAddRectItem();
}

void keshihua::on_pushButton_15_clicked()
{
//    qDebug()<<"进入!";
    QString function_name = ui->apiList->currentText();
    QString args = ui->args->text();
    // 验证输入参数合法性
    //    QRegExp rx("(/d+,)*/d+");
    //    QRegExpValidator v(rx, 0);
    // 验证成功
    QStringList argsList = args.split(",");
    if (currentType=="List"){
//        this->seqlist = new SeqList<int>();
        QList<int> argsIntList;
        for(int i=0;i<argsList.length();i++){
            argsIntList.append(argsList[i].toInt());
//            qDebug() << argsList[i].toInt();
        }
//        if(function_name=="Insert" && args=="debug"){
//            try{
//                qDebug()<<"debug mode";
//                // 记录下items列表
//                QList<QGraphicsItem*> OldlistItem = scene->items();

////                qDebug()<<OldlistItem.length();

//                // 清除场景的items
//                for(int j = 0;j<OldlistItem.length();j++){
//                    scene->removeItem(OldlistItem[j]);
//                }

////                qDebug()<<OldlistItem.length();
//                // 场景反向
////                for(int j =0; j<OldlistItem.length();j++){
////                    scene->addItem(OldlistItem[j]);
////                }
//                // 在制定位置加上两个物体


//                // 场景复原
//                for(int j =OldlistItem.length()-1; j>=0;j--){
//                    scene->addItem(OldlistItem[j]);
//                }
//            }catch(...){
//                qDebug()<<"出问题了~";
//            }
//        }


        if(function_name=="Insert"&& args!="debug"){
            //void Insert(int i, T x);  //插入
            try{
                  //测试失败，对listItem对象进行插入操作时无法影响到实际scene的items数组
//                QList<QGraphicsItem*> listItem = scene->items();
//                QGraphicsRectItem *rect = gen_List_Rect_Item();
//                rect->setPos(-500,-500);
//                listItem.insert(0,rect);
//                if(listItem.length()!=0){
//                    qDebug()<<listItem[listItem.length()-1]->type();
//                }
//                qDebug()<<listItem.length()<<endl;
                //remove后还可不可以加回来？——可以的！
//                   QGraphicsRectItem *rect = gen_List_Rect_Item();
//                   rect->setPos(-500,-500);
//                   scene->addItem(rect);
//                   QList<QGraphicsItem*> listItem = scene->items();
//                   scene->removeItem(rect);
//                   scene->addItem(listItem[0]);


//              方案2：保存插入前的scene->items()，然后clear后再重新构造一遍。

                // 预处理
                int length = this->seqlist->GetLength(); //未经修改前的顺序表长度
                this->seqlist->Insert(argsIntList[0],argsIntList[1]); //调用后台数据结构对应的函数
                int i = argsIntList[0];
                int x = 2*length -1 -2*i;   //i映射后的物理存储索引
                int posx;

//                qDebug()<<posx;
                if(length==0){
                    //平凡情况
//                    QGraphicsRectItem *rect = gen_List_Rect_Item();
//                    rect->setPos(-500,-500);
//                    scene->addItem(rect);
                    AddListItem(argsList[1]);
                }
                else{
                    // 一般情况
                    //确定插入位置
                    posx = i*(listx+500)/(length)-500;


                    // 记录下items列表
                    QList<QGraphicsItem*> OldlistItem = scene->items();

                    // 清除场景的items
                    for(int j = 0;j<OldlistItem.length();j++){
                        scene->removeItem(OldlistItem[j]);
                    }

                    // 创建对应的两个对象，调整保存下来的items列表
                    QGraphicsRectItem *rect = gen_List_Rect_Item();
                    QGraphicsTextItem *text = gen_List_Text_Item(argsList[1]);

                    // 修正0~x处的item的坐标
                        for(int j=x;j>0;j-=2){
                            qDebug()<<"对象移动~";
                            OldlistItem[j]->setPos(OldlistItem[j]->x()+60,-500);
                            OldlistItem[j-1]->setPos(OldlistItem[j-1]->x()+60,-500+15);
                        };

                    //插入新item到对应的位置
//                    Qlist<QGraphicsItem*> NewListItem;
                    OldlistItem.insert(x+1,rect);
                    OldlistItem.insert(x+1,text);//注意，两个都插在x-1
                    qDebug()<<posx;
                    rect->setPos(posx,-500);
                    text->setPos(posx+15,-500+15);

                    // 重新添加一遍场景的items
                    for(int j=OldlistItem.length()-1;j>=0;j--){
                       qDebug()<<"场景复原~";
                       scene->addItem(OldlistItem[j]);
                    }


                    // 更新坐标
                    listx += 60;

                }




//                // 创建两个item对象：文字和矩形。并将他们插到指定的位置
//                int i = argsIntList[0];
//                int x = 2*length -1 -2*i;   //计算逻辑上的i位置在存储中的位置
//                QGraphicsRectItem *rect = gen_List_Rect_Item();
//                QGraphicsTextItem *text = gen_List_Text_Item(argsList[1]);
//                qreal x_ = i*(listx+500)/(length-1)-500;
//                rect->setPos(x_,-500);
//                text->setPos(x_,-500+15);
////                QGraphicsItem* rectinsert = rect;
////                QGraphicsItem* textinsert = text;
//                // 从插入位置（不包括插入的两个）向后，遍历listItem，修改后面Item的坐标
//                for(int k=x-2;k>0;k-=2){
//                    listItem[k]->setPos(listItem[k]->x()+60,-500);
//                    listItem[k-1]->setPos(listItem[k-1]->x()+60,-500+15);
//                }
//                //插入对应listitem
//                listItem.insert(x,rect);
//                listItem.insert(x-1,text);
//                // 更新最新的listx,listy
//                listx+=60;
            }catch(...){
                QMessageBox message(QMessageBox::NoIcon, "参数有误", "请检查您的参数输入");
                message.exec();
            }

        }
        else if (function_name=="append"){
            // void append(T x);  //末尾插入
            try{
                this->seqlist->append(argsIntList[0]);
                AddListItem(argsList[0]);

            }catch(...){
                QMessageBox message(QMessageBox::NoIcon, "参数有误", "请检查您的参数输入");
                message.exec();
            }

        }else if (function_name=="Delete"){
            // T Delete(int i); //删除
            try{
                int length = this->seqlist->GetLength(); //未经修改前的顺序表长度
                this->seqlist->Delete(argsIntList[0]);
                QList<QGraphicsItem*> listItem = scene->items();
                // 删除对应位置的item
                int i = argsIntList[0];
                int x = 2*length -1 -2*i;
                scene->removeItem(listItem[x]);
                scene->removeItem(listItem[x-1]);
                // 对后面的item元素位置做调整
                for(int k=x-2;k>0;k-=2){
                    listItem[k]->setPos(listItem[k]->x()-60,-500);
                    listItem[k-1]->setPos(listItem[k-1]->x()-60,-500+15);
                }
//                for(int j= x;x<)
                // 更新最新的listx,listy
                listx -=60;
            }catch(...){
                QMessageBox message(QMessageBox::NoIcon, "参数有误", "请检查您的参数输入");
                message.exec();
            }

        }else if (function_name=="pop"){
            //   T pop();
            try{this->seqlist->pop();
                QList<QGraphicsItem*> listItem = scene->items();
                // 删除最后那个位置对应的item
                scene->removeItem(listItem[0]);
                scene->removeItem(listItem[1]);
                // 更新最新的listx,listy
                listx-=60;
            }catch(...){
                QMessageBox message(QMessageBox::NoIcon, "调用错误", "数组此时未空！");
                message.exec();
            }
        }
        this->seqlist->PrintList();
        QList<QGraphicsItem*> listItem = scene->items();
        for(int i = 0;i<listItem.length();i++){
            qDebug()<< listItem[i]->type() << " ";;
        }

    }
//    if (function_name=="append"){
//        slotAddRectItem(arg_name);
//    }

//    slotAddRectItem();
}

//void keshihua::on_comboBox_11_currentTextChanged(const QString &arg1)
//{
//    QString listcode = QString("int main;");
//    if(arg1=="List"){
//        ui->textBrowser->setText(listcode);
//    }
//}

//void keshihua::on_comboBox_11_activated(const QString &arg1)
//{
//    QString code;
//    if(arg1=="List"){
//        QFile file_h("./seqlist.h");
//        if(file_h.open(QIODevice::ReadOnly)){
//            char buffer[2048];
//            qint64 lineLen = file.readLine(buffer,sizeof(buffer));
//            if(lineLen != -1){
//                code = QString(buffer);
//            }
//            QString header = "/seqlist.h\n";
//            code = header+file_h.readAll();
//        }
//        QFile file_cpp("./seqlist.cpp");
//        if(file_cpp.open(QIODevice::ReadOnly)){
//            char buffer[2048];
//            qint64 lineLen = file.readLine(buffer,sizeof(buffer));
//            if(lineLen != -1){
//                code = QString(buffer);
//            }
//            QString header2 = "\n/seqlist.cpp\n";
//            code = code + header2 + file_cpp.readAll();
//        }
//        ui->textBrowser->setText(code);
//    }
//}

//void keshihua::on_comboBox_11_activated(const QString &arg1)
//{

//}

void keshihua::on_comboBox_11_currentTextChanged(const QString &arg1)
{
    QString code_temp;
    currentType = arg1;
    if(arg1=="List"){
        // 读取头文件和CPP文件显示在TEXT浏览器上
        QFile file_h("C:\\Users\\Administrator\\Desktop\\cpp_shixun_project\\dsa_learning_hleper\\seqlist.h");
        if(file_h.open(QIODevice::ReadOnly)){
            QString header = "/seqlist.h\n";
            code_temp = header+file_h.readAll();
        }
        QFile file_cpp("C:\\Users\\Administrator\\Desktop\\cpp_shixun_project\\dsa_learning_hleper\\seqlist.cpp");
        if(file_cpp.open(QIODevice::ReadOnly)){
            QString header2 = "\n/seqlist.cpp\n";
            code_temp = code_temp + header2 + file_cpp.readAll();
        }
        this->code = code_temp;
        ui->textBrowser->setText(code_temp);


        //设置可以调用的函数列表
        ui->apiList->clear();
        QList<QString> apixuanze;
        apixuanze.append("Insert");
        apixuanze.append("append");
        apixuanze.append("Delete");
        apixuanze.append("pop");
        QStringList items(apixuanze);
        ui->apiList->addItems(items);


        // 在内存中初始化对应的数据结构
        this->seqlist = new SeqList();
        QMessageBox message(QMessageBox::NoIcon, "切换成功", "成功地切换为了"+arg1);
        message.exec();
    }
    else if(arg1==""){
        ui->textBrowser->setText("");
        ui->apiList->clear();
        this->slotClear();
    }
}

void keshihua::on_pushButton_16_clicked()
{
    if(this->currentType==""){
        QMessageBox message(QMessageBox::NoIcon, "提醒", "请先选择对应的练习代码");
        message.exec();
        return ;
    }
    this->hide();
    e.show();
    e.code = this->code;
}
