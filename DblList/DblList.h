//
// Created by 莫道 on 2018/10/2.
//

#ifndef DBLLIST_DBLLIST_H
#define DBLLIST_DBLLIST_H

#include <iostream>
using namespace std;
template <class T>
struct DblNode
{
    T data;
    DblNode<T>* lLink, *rLink;
    DblNode(DblNode<T>* left = NULL, DblNode<T>* right = NULL):lLink(left), rLink(right){}
    DblNode(T value, DblNode<T>* left = NULL, DblNode<T>* right = NULL)
    :data(value), lLink(left), rLink(right){}
};
template <class T>
class DblList
{
private:
    DblNode<T>* first;
public:
    DblList()
    {
        first = new DblNode<T>;
        first -> rLink = first -> lLink = first;
    }
    ~DblList()
    {}
    int Length()const
    {
        DblNode<T>* current = first -> rLink;
        int count = 0;
        while(current != first)
        {
            current = current -> rLink;
            count++;
        }
        return count;
    }
    bool IsEmpty()
    {
        return first -> rLink == first;
    }
    DblNode<T>* getHead()const
    {
        return first;
    }
    void setHead(DblNode<T>* ptr)
    {
        first = ptr;
    }
    DblNode<T>* Search(const T& x)
    {
        DblNode<T>* current = first -> rLink;
        while(current != first && current -> data != x)
            current = current ->rLink;
        if(current != first)return current;
        else return NULL;
    }
    DblNode<T>* Locate(int i, int d)
    {
        if(first -> rLink == first || i == 0)return false;
        DblNode<T>* current;
        if(d == 0)current = first -> lLink;
        else current = first -> rLink;
        for(int j = 1; j < i; j++)
            if(current == first)break;
            else if(d == 0)current = current -> lLink;
            else current = current -> rLink;
        if(current != first)return current;
        else return NULL;
    }
    bool Insert(int i, const T& x, int d)
    {
        DblNode<T>* current = Locate(i, d);
        if(current == NULL)return false;
        DblNode<T>* newNode = new DblNode<T>(x);
        if(d == 0)
        {
            newNode -> lLink = current -> lLink;
            current -> lLink = newNode;
            newNode -> lLink -> rLink = newNode;
            newNode -> rLink = current;
        }
        else
        {
            newNode -> rLink = current -> rLink;
            current -> rLink = newNode;
            newNode -> rLink -> lLink = newNode;
            newNode -> lLink = current;
        }
        return true;
    }
    bool Remove(int i, const T& x, int d)
    {
        DblNode<T>* current = Locate(i, d);
        if(current == NULL)return false;
        current -> rLink -> lLink = current -> lLink;
        current -> lLink -> rLink = current -> rLink;
        x = current -> data;
        delete current;
        return true;
    }
    void input(T endTag, int d)
    {
        cout << "输入链表的结点的值，直到输入" << endTag << "停止" << endl;
        T a;
        cin >> a;
        if (d == 0)
        {
            DblNode<T> *current = first;
            while (a != endTag)
            {
                DblNode<T> *newNode = new DblNode<T>(a);
                newNode->lLink = current->lLink;
                current->lLink = newNode;
                newNode->lLink->rLink = newNode;
                newNode->rLink = current;
                current = newNode;
                cin >> a;
            }
        }
        else
        {
            DblNode<T> *current = first;
            while (a != endTag)
            {
                DblNode<T> *newNode = new DblNode<T>(a);
                newNode->rLink = current->rLink;
                current->rLink = newNode;
                newNode->rLink->lLink = newNode;
                newNode->lLink = current;
                current = newNode;
                cin >> a;
            }
        }
    }
    void output(int d)
    {
        if(d == 0)
        {
            int n = 1;
            DblNode<T>* current = first -> lLink;
            while(current != first)
            {
                T a = current -> data;
                cout << n++ << ":" << a << endl;
                current = current -> lLink;
            }
        }
        else
        {
            int n = 1;
            DblNode<T>* current = first -> rLink;
            while (current != first)
            {
                T a = current -> data;
                cout << n++ << ":" << a << endl;
                current = current -> rLink;
            }
        }
    }
};
#endif //DBLLIST_DBLLIST_H
