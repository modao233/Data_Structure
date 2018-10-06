//
// Created by 莫道 on 2018/9/27.
//

#ifndef CIRCLIST_CIRCLIST_H
#define CIRCLIST_CIRCLIST_H

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
        first -> link = first;
    }
    CircList(const T& x)
    {
        last = first = new CircLinkNode<T>(x);
        first -> link = first;
    }
    CircList(CircList<T>& L)
    {
        T value;
        CircLinkNode<T>* srcptr = L.first;
        CircLinkNode<T>* desptr = first = new CircLinkNode<T>;
        while(srcptr -> link != L.first)
        {
            value = srcptr -> link -> data;
            desptr -> link = new CircLinkNode<T>(value);
            desptr = desptr -> link;
            srcptr = srcptr -> link;
        }
        last = desptr;
        last -> link = first;
    }
    ~CircList()
    {
        makeEmpty();
        delete first;
    }
    void makeEmpty()
    {
        CircLinkNode<T>* q;
        while(first -> link != first)
        {
            q = first -> link;
            first -> link = q -> link;
            delete q;
        }
        last = first;
    }
    int Length()const
    {
        CircLinkNode<T>* p = first -> link;
        int count = 0;
        while(p != first)
        {
            p = p -> link;
            count++;
        }
        return count;
    }
    bool IsEmpty()
    {
        return first -> link == first ? true : false;
    }
    CircLinkNode<T>* getHead()const
    {
        return first;
    }
    void setHead(CircLinkNode<T>* p)
    {

    }
    CircLinkNode<T>* Search(T x)
    {
        CircLinkNode<T>* current = first -> link;
        while(current != first && current -> data != x)
            current = current -> link;
        if(current == first)current = NULL;
        return current;
    }
    CircLinkNode<T>* Locate(int i)
    {
        if(i < 0)
            return NULL;
        else if(i == 0)
            return first;
        CircLinkNode<T>* current = first -> link;
        int k = 1;
        while(current != first && k < i)
        {
            current = current -> link;
            k++;
        }
        if(k == i)return current;
        else return NULL;
    }
    bool getData(int i, T& x)
    {
        if(i <= 0)
            return false;
        CircLinkNode<T>* current = Locate(i);
        if(current == first || !current)
            return false;
        else
        {
            x = current -> data;
            return true;
        }
    }
    bool setData(int i, T& x)
    {
        if(i <= 0)
            return false;
        CircLinkNode<T>* current = Locate(i);
        if(current == first || !current)
            return false;
        else
        {
            current -> data = x;
            return true;
        }
    }
    bool Insert(int i, T& x)
    {
        CircLinkNode<T>* current = Locate(i);
        if(current == NULL)
            return false;
        CircLinkNode<T>* newNode = new CircLinkNode<T>(x);
        newNode -> link = current -> link;
        current -> link = newNode;
        if(last -> link != first)
        {
            last = last->link;
            last -> link = first;
        }
        return true;
    }
    bool Remove(int i, T& x)
    {
        CircLinkNode<T>* current = Locate(i - 1);
        if(current == NULL || current -> link == first)
            return false;
        CircLinkNode<T>* del = current -> link;
        if(del == last)last = current;
        current -> link = del -> link;
        x = del -> data;
        delete del;
        return true;
    }
    void inputFront(T endTag)
    {
        CircLinkNode<T>* newNode;
        T val;
        cin >> val;
        while(val != endTag)
        {
            newNode = new CircLinkNode<T>(val);
            newNode -> link = first -> link;
            first -> link = newNode;
            if(last == first)last = last -> link;
            cin >> val;
        }
        last -> link = first;
    }
    void inputRear(T endTag)
    {
        T val;
        cin >> val;
        while(val != endTag)
        {
            last -> link = new CircLinkNode<T>(val);
            last = last -> link;
            cin >> val;
        }
        last -> link = first;
    }
    void output()
    {
        CircLinkNode<T>* current = first -> link;
        while(current != first)
        {
            cout << current -> data << endl;
            current = current -> link;
        }
    }
    friend ostream& operator << (ostream& out, CircList<T>& L)
    {

    }
    friend istream& operator >> (istream& in, CircList<T>& L)
    {

    }
    /*void Reverse()
    {
        CircLinkNode<T>* p, *q, *r;
        p = first;
        q = p -> link;
        r = q -> link;
        while(r != first)
        {
            q -> link = p;
            p = q;
            q = r;
            r = r -> link;
        }
        q -> link = p;
        first -> link = q;
        first = q;
    }*/
};
#endif //CIRCLIST_CIRCLIST_H
