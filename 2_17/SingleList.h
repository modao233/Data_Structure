//
// Created by 莫道 on 2018/9/26.
//

#ifndef INC_2_17_SINGLELIST_H
#define INC_2_17_SINGLELIST_H

#include <iostream>
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
        data = item;
        link = ptr;
    }
};
template <class T>
class List
{
protected:
    LinkNode<T>* first;
public:
    List()
    {
        first = new LinkNode<T>;
    }
    List(const T& x)
    {
        first = new LinkNode<T>(x);
    }
    List(List<T>& x)
    {
        first = new LinkNode<T>(x);
    }
    ~List()
    {
        makeEmpty();
    }
    void makeEmpty()
    {
        LinkNode<T>* q;
        while(first -> link != NULL)
        {
            q = first -> link;
            first -> link = q -> link;
            delete(q);
        }
    }
    void inputRear(T endTag)
    {
        LinkNode<T>* newNode, *last;
        T val;
        makeEmpty();
        cin >> val;
        last = first;
        while(val != endTag)
        {
            newNode = new LinkNode<T>(val);
            last -> link = newNode;
            last = newNode;
            cin >> val;
        }
    }
    void output1()
    {
        LinkNode<T> *current = first -> link;
        int count = 1;
        while (current != NULL)
        {
            cout << count++ << " : ";
            cout << current->data << endl;
            current = current->link;
        }
    }
    void output2()
    {
        LinkNode<T> *current = first;
        int count = 1;
        while (current != NULL)
        {
            cout << count++ << " : ";
            cout << current->data << endl;
            current = current->link;
        }
    }
    void Reverse()
    {
        LinkNode<T>* current = first;
        moveptr(current);
        current -> link = NULL;
        current -> data = 0;
    }
    void moveptr(LinkNode<T> *current)
    {
        if(current -> link -> link == NULL)
        {
            first = current -> link;
            current -> link -> link = current;
        }
        else
        {
            moveptr(current -> link);
            current -> link -> link = current;
        }
    }

    /*void Reverse()
    {
        LinkNode<T> *p, *q, *r;
        p = first;
        q = p->link;
        r = q->link;
        first->link = NULL;
        first->data = 0;
        while (r)
        {
            q->link = p;
            p = q;
            q = r;
            r = r->link;
        }
        q->link = p;
        first = q;
    }*/
};
#endif //INC_2_17_SINGLELIST_H
