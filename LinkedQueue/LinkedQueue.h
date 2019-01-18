//
// Created by 莫道 on 2018/10/7.
//

#ifndef LINKEDQUEUE_LINKEDQUEUE_H
#define LINKEDQUEUE_LINKEDQUEUE_H
#include <iostream>
using namespace std;

template <class T>
struct LinkNode
{
    T data;
    LinkNode<T>* link;
    LinkNode(LinkNode<T>* ptr = NULL){link = ptr;}
    LinkNode(const T& item, LinkNode<T>* ptr = NULL)
    {
        data = item;
        link = ptr;
    }
};
template <class T>
class LinkedQueue
{
protected:
    LinkNode<T> *front, *rear;
public:
    LinkedQueue():rear(NULL), front(NULL){}
    ~LinkedQueue()
    {
        makeEmpty();
    }
    bool EnQueue(const T& x)
    {
        if (front == NULL)
            front = rear = new LinkNode<T>(x);
        else
        {
            rear -> link = new LinkNode<T>(x);
            rear = rear -> link;
        }
    }
    bool DeQueue(T& x)
    {
        if (IsEmpty())return false;
        LinkNode<T>* p = front;
        x = p -> data;
        front = front -> link;
        delete p;
        return true;
    }
    bool getFront(T& x)const
    {
        if (IsEmpty())return false;
        x = front -> data;
        return true;
    }
    void makeEmpty()
    {
        LinkNode<T>* p;
        while (front != NULL)
        {
            p = front;
            front = front -> link;
            delete p;
        }
    }
    bool IsEmpty()const
    {
        return (front == NULL) ? true : false;
    }
    int getSize()const
    {
        LinkNode<T>* p = front;
        int k = 0;
        while (p != NULL)
        {
            p = p -> link;
            k++;
        }
        return k;
    }
    friend ostream& operator << (ostream& os, LinkedQueue<T>& Q)
    {
        os << "队列中元素个数有" << Q.getSize() << endl;
        LinkNode<T>* p = Q.front;
        int i = 0;
        while (p != NULL)
        {
            os << ++i << ":" << p -> data << endl;
            p = p -> link;
        }
    }
};
#endif //LINKEDQUEUE_LINKEDQUEUE_H
