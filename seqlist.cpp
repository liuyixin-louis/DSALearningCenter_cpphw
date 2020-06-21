#include "SeqList.h"
using namespace std;


SeqList::SeqList(const int a[], int n){
    if(n>MAXSIZE){
        throw "数组长度超过顺序表的最大长度";
    }
    for(int i = 0;i<n;i++){
        data[i] = a[i];
    }
    length = n;
}

void SeqList::PrintList(){
    cout<<"按序号依次遍历线性表中的各个数据元素："<<endl;
    for(int i = 0;i<length;i++){
        cout << data[i] <<" ";
    }
    cout << endl;
}

void SeqList::Insert(int i, int x){
    // """i对应的是索引"""
    if(length>MAXSIZE) throw "上溢异常";
    if(i<0 || i>length) throw "位置异常";
    for(int j = length; j>=i; j--){
        data[j] = data[j-1];
    }
    data[i] = x;
    length ++;
}

void SeqList::append(int x){
    if(length>MAXSIZE) throw "上溢异常";
    data[length++] = x;
}


int SeqList::Delete(int i){
    if(length == 0) throw "下溢异常";
    if(i<0 || i>=length){
        throw "位置异常";
    }
    int x = data[i];
    for(int j = i;j<length-1;j++){
        data[j]= data[j+1];
    }
    length --;
    return x;
}

int SeqList::pop(){
    if(length == 0) throw "下溢异常";
    return data[--length];
}

int  SeqList::Get(int i){
    if(0 == length) throw"上溢异常";
    if(i<0 || i>=length){
        throw "查找位置非法";
    }
    return data[i];
}

int SeqList::Locate(const int x){
    for(int i = 0;i<length;i++){
        if(x == data[i])
            return i;
    }
    return 0;
}
