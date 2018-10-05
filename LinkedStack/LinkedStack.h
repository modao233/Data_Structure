//
// Created by 莫道 on 2018/10/5.
//

#ifndef LINKEDSTACK_LINKEDSTACK_H
#define LINKEDSTACK_LINKEDSTACK_H
#include <iostream>
#include <assert.h>
using namespace std;

template <class T>
struct LinkNode
{
    T data;
    LinkNode<T>* link;
    LinkNode(LinkNode<T>* ptr = NULL)
    {
        link = ptr;
    }
    LinkNode(const T& item, LinkNode<T>* ptr = NULL)
    {
        link = ptr;
        data = item;
    }
};
template <class T>
class LinkedStack
{
private:
    LinkNode<T>* top;       //栈顶指针
public:
    LinkedStack():top(NULL){}       //构造函数，置空栈
    ~LinkedStack()
    {
        makeEmpty();
    }
    void Push(const T& x)
    {
        //将元素值x插入到链式栈的栈顶，即链头
        top = new LinkNode<T>(x, top);
        assert(top != NULL);
    }
    bool Pop(T& x)
    {
        //删除栈顶结点，返回被删除栈顶元素的值
        if (IsEmpty())return false;
        LinkNode<T>* p = top;
        top = top -> link;
        x = p -> data;
        delete p;
        return true;
    }
    bool getTop(T& x)const
    {
        if (IsEmpty())return false;
        x = top -> data;
        return true;
    }
    bool IsEmpty()const
    {
        return (top == NULL) ? true : false;
    }
    int getSize()const
    {
        LinkNode<T>* p = top;
        int k = 0;
        while (p != NULL)
        {
            p = p -> link;
            k++;
        }
        return k;
    }
    void makeEmpty()
    {
        //逐次删去链式栈中的元素直至栈顶指针为空
        LinkNode<T>* p;
        while (top != NULL)
        {
            p = top;
            top = top -> link;
            delete p;
        }
    }
    friend ostream& operator << (ostream& os, LinkedStack<T>& s)
    {
        os << "栈中元素个数=" << s.getSize() << endl;
        LinkNode<T>* p = s.top;
        int i = 0;
        while (p != NULL)
        {
            os << ++i << ":" << p -> data << endl;
            p = p -> link;
        }
        return os;
    }
};
#endif //LINKEDSTACK_LINKEDSTACK_H
