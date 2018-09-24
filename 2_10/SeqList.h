//
// Created by 莫道 on 2018/9/23.
//

#ifndef INC_2_10_SEQLIST_H
#define INC_2_10_SEQLIST_H
#include <iostream>
#include <stdlib.h>
using namespace std;
const int defaultSize = 100;
template <class T>
class SeqList
{
protected:
    T* data;
    int maxsize;
    int last;
public:
    SeqList(int sz = defaultSize):maxsize(sz),last(-1)
    {
        if(sz != 0)
            data = new T[maxsize];
    }
    SeqList(SeqList<T>& L)
    {
        maxsize = L.Size();
        last = L.Length() - 1;
        T value;
        data = new T[maxsize];
        for(int i = 1; i <= last + 1; i++)
        {
            L.getData(i, value);
            data[i - 1] = value;
        }
    }
    ~SeqList()
    {
        delete[] data;
    }
    int Size()const
    {
        return maxsize;
    }
    int Length()const
    {
        return last + 1;
    }
    int Search(T& x) const
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
    void Insert(int i, T& x)
    {
        if(last == maxsize - 1 || i <= 0 || i > last + 1)
        {
            cout << "ERROR" << endl;
            return;
        }
        for(int j = last; j >= i - 1; j--)
            data[j + 1] = data[j];
        data[i - 1] = x;
        last++;
    }
    T Remove(int i)
    {
        if(last == -1 || i < 1 || i > last + 1)
        {
            cout << "ERROR" << endl;
            return 0;
        }
        T x = data[i - 1];
        for(int j = i; j <= last; j++)
            data[j - 1] = data[j];
        last--;
        return x;
    }
    void Remove(T& x,int c)
    {
        int a = last + 1;
        while(a--)
        {
            int i = Search(x);
            if(i != 0)T a = Remove(i);
        }

    }
    T RemoveMin()
    {
        T x = data[0];
        int min = 0;
        for(int i = 1; i <= last; i++)
        {
            if(data[i] < x)min = i;
        }
        x = Remove(min + 1);
        T y = Remove(last + 1);
        Insert(min + 1, y);
        return x;
    }
    void Remove_s_to_t(T& s, T& t)
    {
        if(s > t || last == -1)
        {
            cout << "ERROR" << endl;
            return;
        }
        for(int i = 0; i <= last;)
        {
            if(data[i] >= s && data[i] <= t)Remove(i + 1);
            else i++;
        }
        cout << "删除s ~ t成功" << endl;
    }
    T* Merge(SeqList<T>& L)
    {
        int mergeSize = maxsize + L.Size();
        int mergeLast = last + L.Length();
        T value;
        T* mergeData = new T[mergeSize];

        for(int i = 1; i <= last + 1; i++)
        {
            getData(i, value);
            mergeData[i - 1] = value;
        }
        for(int i = last + 2, j = 1; i <= mergeLast + 1 && j <= L.Length() + 1; i++, j++)
        {
            L.getData(j, value);
            mergeData[i - 1] = value;
        }
        data = mergeData;
        maxsize = mergeSize;
        last = mergeLast;
        cout << "合并成功" << endl;
        return data;
    }
    void input()
    {
        cout << "开始建立顺序表，请输入表中元素个数减1：";
        while(1)
        {
            cin >> last;
            if(last <= maxsize - 1)break;
            cout << "表中元素个数输入有误，范围不能超过" << maxsize - 1<< ":";
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
    void RemoveRepeat()     //删除重复的元素
    {
        for(int i = 0; i < last; i++)
        {
            for(int j = i + 1; j <= last;)
                if(data[i] == data[j])Remove(j + 1);
                else j++;
        }
        cout << "删除重复" << endl;
    }
};
#endif //INC_2_10_SEQLIST_H
