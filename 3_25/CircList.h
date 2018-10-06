//
// Created by 莫道 on 2018/10/6.
//

#ifndef INC_3_25_CIRCLIST_H
#define INC_3_25_CIRCLIST_H
#include <iostream>
using namespace std;
template <class T>
struct CircLinkNode
{
    T data;
    CircLinkNode<T>* link;
    CircLinkNode(CircLinkNode<T>* next = NULL):link(next){}
    CircLinkNode(T d, CircLinkNode<T>* next = NULL):data(d), link(next){}
};
template <class T>
class CircList
{
private:
    CircLinkNode<T> *first, *last;
public:
    CircList()
    {
        last = first = new CircLinkNode<T>;
        first->link = first;
    }

    CircList(const T &x)
    {
        last = first = new CircLinkNode<T>(x);
        first->link = first;
    }

    ~CircList()
    {
        makeEmpty();
        delete first;
    }

    void makeEmpty()
    {
        CircLinkNode<T> *q;
        while (first->link != first)
        {
            q = first->link;
            first->link = q->link;
            delete q;
        }
        last = first;
    }

    void DeQueue()
    {
        if (first == last)cout << "链表已空" << endl;
        CircLinkNode<T>* current = first -> link;
        first -> link = current -> link;
        delete current;
    }

    void EnQueue(T val)
    {
        last -> link = new CircLinkNode<T>(val);
        last = last -> link;
        last -> link = first;
    }
    void output()
    {
        CircLinkNode<T> *current = first->link;
        while (current != first)
        {
            cout << current->data << endl;
            current = current->link;
        }
    }
};
#endif //INC_3_25_CIRCLIST_H
