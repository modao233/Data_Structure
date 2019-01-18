//
// Created by 莫道 on 2018/11/25.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include <iostream>
#include <cassert>
using namespace std;
const int DefaultSize = 100;
enum KindOfStatus {Active, Empty, Deleted};             //元素分类（活动/空/删）
template <class E, class K>
class HashTable{
public:
    HashTable(const int d, int sz = DefaultSize);
    ~HashTable(){
        delete []ht;
        delete []info;
    }
    HashTable<E, K>& operator = (const HashTable<E, K>& ht2);
    bool Search(const K k1, E& e1)const;
    bool Insert(const E& e1);
    bool Remove(const K k1, E& e1);
    void makeEmpty();
    void output();  //输出
//	HashTable<E,K>& operator = (const HashTable<E,K> &ht2);
    friend ostream& operator << (ostream &out, HashTable<E,K> &ht2){
        for(int i = 0; i < ht2.TableSize; i++){
            if(ht2.info[i] == Active){
                out << "#" << i << ":\t"<< ht2.ht[i] << endl;
            }
            else if (ht2.info[i] == Empty){
                out << "#" << i << ":\tEmpty!" << endl;
            }
            else if (ht2.info[i] == Deleted){
                out << "#" << i << ":\tDeleted!" << endl;
            }
        }
        return out;
    }
    friend istream& operator >> (istream &in, HashTable<E,K> &ht2){
        E data;
        in >> data;
        while (data != 0 && ht2.CurrentSize < ht2.TableSize){
            ht2.Insert(data);
            assert(in >> data);
        }
        return in;
    }
private:
    int divitor;
    int CurrentSize, TableSize;
    E *ht;
    KindOfStatus *info;
    int FindPos(const K k1)const;
    int operator == (E& e1){
        return *this == e1;
    }
    int operator != (E& e1){
        return *this != e1;
    }
};

template <class E, class K>
HashTable<E, K>::HashTable(const int d, int sz) {
    divitor = d;
    TableSize = sz;
    CurrentSize = 0;
    ht = new E[TableSize];
    info = new KindOfStatus[TableSize];
    for (int i = 0; i < TableSize; i++){
        info[i] = Empty;
    }
}

template <class E, class K>
void HashTable<E, K>::makeEmpty() {
    for (int i = 0; i < TableSize; i++){
        info[i] = Empty;
        CurrentSize = 0;
    }
}

template <class E, class K>
HashTable<E, K>& HashTable<E, K>::operator = (const HashTable<E, K> &ht2) {
    if (this != &ht2){
        delete []ht;
        delete []info;
        ht = new E[ht2.TableSize];
        info = new KindOfStatus[ht2.TableSize];
        for (int i = 0; i < ht2.TableSize; i++){
            ht[i] = ht2.ht[i];
            info[i] = ht2.info[i];
        }
        CurrentSize = ht2.CurrentSize;
    }
    return *this;
}

template <class E, class K>
int HashTable<E, K>::FindPos(const K k1) const {
    //搜索在一个散列表中关键码与k1匹配的元素，搜素成功，则函数返回该元素的位置，否则返回插入点（如果有足够的空间）
    int i = k1 % divitor;       //计算初始桶号
    int j = i;          //j是检查下一空桶下标
    do{
        if (info[j] == Empty || info[j] == Active && ht[j] == k1)return j;      // 找到
        j = (j + 1) % TableSize;                                    //当做循环表处理，找到下一个空桶
    }while (j != i);
    return j;                                   //转一圈回到开始点，表已满，失败
}
template <class E, class K>
bool HashTable<E, K>::Search(const K k1, E &e1) const {
    //使用线性探查法在散列表ht（每个桶容纳一个元素）中搜索k1.如果k1在表中存在，
    //则函数返回true，并且引用参数e1返回找到的元素；如果k1不在表中，则返回false。
    int i = FindPos(k1);
    if (info[i] != Active || ht[i] != k1)return false;
    e1 = ht[i];
    return true;
}

template <class E, class K>
bool HashTable<E, K>::Insert(const E &e1) {
    //在ht表中搜索e1,。若找到则不再插入，若未找到，但表已满，则不再插入，返回false；
    //若找到位置的标志是Empty或Deleted，不论表是否已满，x插入，返回true
    K k1 = e1;              //重载函数：抽取关键码
    int i = FindPos(k1);        //用散列函数计算桶号
    if (info[i] != Active){
        ht[i] = e1;
        info[i] = Active;
        CurrentSize++;
        return true;
    }
    if (info[i] == Active && ht[i] == e1){
        cout << "表中已有此元素，不能插入！" << endl;
        return false;
    }
    cout << "表已满，不能插入！" << endl;
    return false;
}

template <class E, class K>
bool HashTable<E, K>::Remove(const K k1, E &e1) {
    //在ht表中删除元素k1。若表中找不到k1，或虽然找到k1，但它已经逻辑删除过
    //则返回false，否则在表中删除元素k1，返回true，并在引用参数e1中得到它
    int i = FindPos(k1);
    if (info[i] == Active && ht[i] == k1){
        e1 = ht[i];
        info[i] = Deleted;
        CurrentSize--;
        return true;
    }
    else return false;
}

template <typename E, typename K>
void HashTable<E,K>::output(){
    for(int i = 0; i<TableSize; i++)	{
        if(info[i] == Active){
            cout << "#" << i << ":\t"<< ht[i] << endl;
        }
        else if (info[i] == Empty){
            cout << "#" << i << ":\tEmpty!" << endl;
        }
        else if (info[i] == Deleted){
            cout << "#" << i << ":\tDeleted!" << endl;
        }
    }
}

#endif //HASHTABLE_HASHTABLE_H
