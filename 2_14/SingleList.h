//
// Created by 莫道 on 2018/9/24.
//

#ifndef INC_2_14_SINGLELIST_H
#define INC_2_14_SINGLELIST_H

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
        data =item;
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
    List(List<T>& L)
    {
        T value;
        LinkNode<T>* srcptr = L.getHead();
        LinkNode<T>* desptr = first = new LinkNode<T>;
        while(srcptr -> link != NULL)
        {
            value = srcptr -> link -> data;
            desptr -> link = new LinkNode<T>(value);
            srcptr = srcptr -> link;
            desptr = desptr -> link;
        }
        desptr -> link = NULL;
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
            delete q;
        }
    }
    LinkNode<T>* locate(int i)      //第（1）小题
    {
        if(i < 1)return NULL;
        LinkNode<T>* current = first;
        int k = 0;
        while(current != NULL && k < i)
        {
            current = current -> link;
            k++;
        }
        return current;
    }
    void max()      //第（2）小题
    {
        LinkNode<T> *current = first->link;
        LinkNode<T> *maxPtr = current;
        T max = current->data;
        while (current->link != NULL)
        {
            current = current->link;
            if (max < current->data)
            {
                max = current->data;
                maxPtr = current;
            }
        }
        if (current->data > max)
        {
            max = current->data;
            maxPtr = current;
        }
        cout << "The max is :" << max << endl;
    }
    int number(T x)     //第（3）小题
    {
        LinkNode<T>* current = first -> link;
        int num = 0;
        while(current -> link != NULL)
        {
            if(current -> data == x)num++;
            current = current -> link;
        }
        return num;
    }
    void creat(T* a, int n)
    {
        makeEmpty();
        LinkNode<T>* current = first;
        for(int i = 0; i < n; i++)
        {
            current -> link = new LinkNode<T>(a[i]);
            current = current -> link;
        }
    }
    void tidyup()       //第（5）小题
    {
        LinkNode<T>* current = first -> link;
        LinkNode<T>* repeat;
        while(current -> link != NULL)
        {
            repeat = current;
            while(repeat -> link != NULL)
            {
                if(current -> data == repeat -> link -> data)
                {
                    LinkNode<T>* remove = repeat -> link;
                    repeat -> link = repeat -> link -> link;
                    delete remove;
                }
                else repeat = repeat -> link;
            }
            current = current -> link;
        }
    }
    void inputFront(T endTag)       // //  前插法建立表单
    {
        LinkNode<T>* newNode;
        T val;
        makeEmpty();
        cout << "输入链表值，输入" << endTag << "输入结束";
        cin >> val;
        while(val != endTag)
        {
            newNode = new LinkNode<T>(val);
            newNode -> link = first -> link;
            first -> link = newNode;
            cin >> val;
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
    void output()
    {
        LinkNode<T> *current = first->link;
        int count = 1;
        while (current != NULL)
        {
            cout << count++ << " : ";
            cout << current->data << endl;
            current = current->link;
        }
    }
};
#endif //INC_2_14_SINGLELIST_H
