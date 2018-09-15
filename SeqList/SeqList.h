//
// Created by 莫道 on 2018/9/14.
//

#ifndef SEQLIST_2_SEQLIST_H
#define SEQLIST_2_SEQLIST_H

#include <iostream>
#include <stdlib.h>
using namespace std;
const int defaultSize = 100;
template <class T>
class SeqList
{
protected:
    T* data;
    int maxSize;
    int last;
    void reSize(int newSize)
    {
        if(newSize <= 0)
        {
            std::cerr << "无效的数组大小" << endl;
            exit(1);
        }
        if(newSize != maxSize)
        {
            T* newarray = new T[newSize];
            /*if(newarray == NULL)
            {
                std::cerr << "储存分配错误" << endl;
                exit(1);
            }*/
            int n = last + 1;
            while(n--) *newarray++ = *data++;
            delete[] data;
            data = newarray;
            maxSize = newSize;
        }
    }

public:
    SeqList(int sz = defaultSize):maxSize(sz),last(-1)
    {
        if(sz != 0)
            data = new T(maxSize);
        if(data == NULL)
        {
            std::cerr << "储存分配错误！" << endl;
            exit(1);
        }
    }
    SeqList(SeqList<T>& L)
    {
        maxSize = L.Size();last = L.Length() - 1;
        T value;
        data = new T[maxSize];
        if(data == NULL)
        {
            std::cerr << "储存分配错误！" << endl;
            exit(1);
        }
        for(int i = 1; i <= last + 1; i++)
        {
            L.getData(i, value);
            data[i - 1] = value;
        }
    }
    ~SeqList(){delete[] data;}
    int Size()const{return maxSize;}
    int Length()const{return last + 1;}
    int Search(T& x)const
    {
        for(int i = 0; i <= last; i++)
            if(data[i] == x)return i + 1;
        return 0;
    }
    int locate(int i)const
    {
        if(i >= 1 && i <= last + 1)return i;
        else return 0;
    }
    bool getData(int i, T& x)const
    {
        if(i > 0 && i <= last + 1)
        {
            x = data[i - 1];
            return true;
        }
        else return false;
    }
    void setData(int i, T& x)
    {
        if(i > 0 && i <= last + 1)
        {
            data[i - 1] = x;
        }
    }
    bool Insert(int i, T& x)
    {
        if(last == maxSize - 1 || i < 0 || i > last + 1)return false;
        for(int j = last; j >= i; j--)
            data[j + 1] = data[j];
        data[i] = x;
        last++;
        return true;
    }
    bool Remove(int i, T& x)
    {
        if(last == -1 || i < 1 || i > last + 1)return false;
        x = data[i - 1];
        for(int j = i; j <= last; j++)
            data[j - 1] = data[j];
        last--;
        return true;
    }
    bool IsEmpty(){return last == -1;}
    bool IsFull(){return last == maxSize - 1;}
    void input()
    {
        cout << "开始建立顺序表，请输入表中元素个数减1：";
        while(1)
        {
            cin >> last;
            if(last <= maxSize - 1)break;
            cout << "表中元素个数输入有误，范围不能超过" << maxSize - 1<< ":";
        }
        for(int i = 0; i <= last; i++)
        {
            cout << i + 1 << endl;
            cin >> data[i];
        }
    }
    void output()
    {
        cout << "顺序表当前元素最后位置为：" << last << endl;
        for(int i = 0; i <= last; i++)
            cout << "#" << i + 1 << ":" << data[i] << endl;
    }
    SeqList<T> operator=(SeqList<T>& L)
    {
        if(this != &L)
        {
            T* array = new T[L.maxSize];
            maxSize = L.maxSize;
            last = L.last;
            delete[] data;
            data = array;
            memcpy(data, &L, sizeof(T) * maxSize);
        }
        return *this;
    }
};
#endif //SEQLIST_2_SEQLIST_H
