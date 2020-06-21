#ifndef SeqList_h
#define SeqList_h
#include <iostream>
using namespace std;
const int MAXSIZE = 1000;



class  SeqList{
public:
    SeqList(){length = 0;}  //初始化
    SeqList(const int a[], int n); //初始化
    int GetLength(){return length;}  //获取长度
    void PrintList();  //打印
    void Insert(int i, int x);  //插入
    void append(int  x);  //末尾插入
    int  pop();
    int Delete(int i); //删除
    int  Get(int i);  //获取
    int Locate(int  x);  //按值查找
private:
    int length;
    int data [MAXSIZE];
};

#endif /* SeqList_h */
