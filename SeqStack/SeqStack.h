//
// Created by 莫道 on 2018/10/5.
//

#ifndef SEQSTACK_SEQSTACK_H
#define SEQSTACK_SEQSTACK_H

#include <assert.h>
#include <iostream>
using namespace std;
const int stackIncreament = 20;
template <class T>
class SeqStack
{
private:
    T* elements;        //栈数组
    int top;        //栈顶指针
    int maxSize;        //栈最大容纳的元素个数
    void overflowProcess()     //栈的溢出处理
    {
        T* newArray = new T[maxSize + stackIncreament];
        for (int i = 0; i <= top; i++)
            newArray[i] = elements[i];
        maxSize = maxSize + stackIncreament;
        delete []elements;
        elements = newArray;
    }
public:
    SeqStack(int sz = 50)       //建立空栈
    {
        top = -1;
        maxSize = sz;
        elements = new T[maxSize];
        assert(elements != NULL);
    }
    ~SeqStack()     //析构函数
    {
        delete []elements;
    }
    void Push(const T& x)  //如果IsFull（），则溢出处理，否则把x插入到栈顶
    {
        if (IsFull() == true)
            overflowProcess();
        elements[++top] = x;
    }
    bool Pop(T& x)
    //如果IsEmpty()。则不执行退栈，返回false；否则退掉位于栈顶的元素，返回true，
    //退出的元素值通过引用型参数x返回
    {
        if (IsEmpty() == true)
            return false;
        x = elements[top--];
        return true;
    }
    bool getTop(T& x)
    //如果IsEmpty()。则不执行退栈，返回false；否则返回true,并通过引用型参数x得到栈顶元素的值
    {
        if (IsEmpty() == true)
            return false;
        x = elements[top];
        return true;
    }
    bool IsEmpty()const
    {
        //如果栈中元素个数等于0，返回true，否则返回false。
        return (top == -1) ? true : false;
    }
    bool IsFull()const
    {
        //如果栈中元素个数等于maxSize，返回true，否则返回false。
        return (top == maxSize - 1) ? true : false;
    }
    int getSize()const
    {
        //返回栈中元素个数
        return top + 1;
    }
    void MakeEmpty()
    {
        //清空栈中元素
        top = -1;
    }
    friend ostream& operator << (ostream& os, SeqStack<T>& x)
    {
        os << "top = " << x.top << endl;
        for (int i = 0; i <= x.top; i++)
            os << i << ":" << x.elements[i] << endl;
        return os;
    }
};
#endif //SEQSTACK_SEQSTACK_H
