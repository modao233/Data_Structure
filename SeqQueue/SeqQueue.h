//
// Created by 莫道 on 2018/10/7.
//

#ifndef SEQQUEUE_SEQQUEUE_H
#define SEQQUEUE_SEQQUEUE_H

#include <assert.h>
#include <iostream>
using namespace std;
template <class T>
class SeqQueue
{
private:
    int rear, front;    // 队尾和队头指针
    T* elements;        //存放队列元素的数组
    int maxSize;        //队列最大可容纳元素个数
public:
    SeqQueue(int sz = 10):front(0), rear(0), maxSize(sz)
    {
        elements = new T[maxSize];
        assert(elements != NULL);
    }
    ~SeqQueue()
    {
        delete[] elements;
    }
    bool EnQueue(const T& x)
    {
        if (IsFull() == true)return false;
        elements[rear] = x;
        rear = (rear + 1) % maxSize;
        return true;
    }
    bool DeQueue(T& x)
    {
        if (IsEmpty() == true)return false;
        x = elements[front];
        front = (front + 1) % maxSize;
        return true;
    }
    bool getFront(T& x)
    {
        if (IsEmpty() == true)return false;
        x = elements[front];
        return true;
    }
    void makeEmpty()
    {
        front = rear = 0;
    }
    bool IsEmpty()const
    {
        return (front == rear) ? true : false;
    }
    bool IsFull()const
    {
        return ((rear + 1) % maxSize == front) ? true : false;
        //rear在front的前一个位置停止，表示已满，此时队列最多的个数只能是maxSize-1个
    }
    int getSize()const
    {
        return (rear - front + maxSize) % maxSize;
    }
    friend ostream& operator << (ostream& os, SeqQueue<T>& Q)
    {
        os << "front = " << Q.front << ", rear = " << Q.rear << endl;
        for (int i = Q.front; i != Q.rear; i = (i + 1) % Q.maxSize)
            os << i << ":" << Q.elements[i] << endl;
        return os;
    }
};
#endif //SEQQUEUE_SEQQUEUE_H
