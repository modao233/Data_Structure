//
// Created by 莫道 on 2018/11/15.
//

#ifndef TEST_MINHEAP_MINHEAP_H
#define TEST_MINHEAP_MINHEAP_H

#include <iostream>
#include <cassert>
using namespace std;
const int DefaultSize = 50;

template <class T>
class MinHeap
{
private:
    T* heap;
    int currentSize;
    int maxHeapSize;
    void siftDown(int start, int m)
    {
        int i = start, j = 2 * i + 1;
        T temp = heap[i];
        while (j <= m)
        {
            if (j < m && heap[j] > heap[j + 1])j++;
            if (temp <= heap[j])break;
            else
            {
                heap[i] = heap[j];
                i = j;
                j = 2 * i + 1;
            }
        }
        heap[i] = temp;
    }
    void siftUp(int start)
    {
        int j = start, i = (j - 1) / 2;
        T temp = heap[j];
        while (j > 0)
        {
            if (heap[i] <= temp)break;
            else
            {
                heap[j] = heap[i];
                j = i;
                i = (j - 1) / 2;
            }
        }
        heap[j] = temp;
    }

public:
    MinHeap(int sz = DefaultSize)
    {
        maxHeapSize = (DefaultSize < sz) ? sz : DefaultSize;
        heap = new T[maxHeapSize];
        assert(heap);
        currentSize = 0;
    }
    MinHeap(T arr[], int n)
    {
        maxHeapSize = (DefaultSize < n) ? n : DefaultSize;
        heap = new T[maxHeapSize];
        assert(heap);
        for (int i = 0; i < n; i++)
        {
            heap[i] = arr[i];
        }
        currentSize = n;
        int currentPos = (currentSize - 2) / 2;
        while (currentPos >= 0)
        {
            siftDown(currentPos, currentSize - 1);
            currentPos--;
        }
    }
    ~MinHeap()
    {
        delete []heap;
    }
    bool Insert(const T& x)
    {
        if (currentSize == maxHeapSize)
        {
            cerr << "Heap Full" << endl;
            return false;
        }
        heap[currentSize] = x;
        siftUp(currentSize);
        currentSize++;
        return true;
    }
    bool RemoveMin(T& x)
    {
        if (!currentSize)
        {
            cout << "Heap empty" << endl;
            return false;
        }
        x = heap[0];
        heap[0] = heap[currentSize - 1];
        currentSize--;
        siftDown(0, currentSize - 1);
        return true;
    }
    void output(int M)
    {
        if (M <= currentSize)
            cout << heap[M];
        if (2 * M + 1 < currentSize)
        {
            cout << "(";
            output(2 * M + 1);
            if (2 * M + 1 == currentSize - 1)cout << ",)";
        }
        if (2 * M + 2 < currentSize)
        {
            cout << ",";
            output(2 * M + 2);
            cout << ")";
        }
    }
};
#endif //TEST_MINHEAP_MINHEAP_H
