//
// Created by 莫道 on 2018/12/1.
//

#ifndef OPENHASHTABLE_HASHTABLE_H
#define OPENHASHTABLE_HASHTABLE_H
#include <iostream>
#include <assert.h>
using namespace std;
const int defaultSize = 100;
template <typename E, typename K>
struct ChainNode {
    E data;
    ChainNode<E, K>* link;
};

template <typename E, typename K>
class HashTable {
public:
    HashTable(int d = 0, int sz = defaultSize);
    ~HashTable() {
        delete []ht;
    }
    bool Search(const K k1, E& e1);
    bool Insert(const E& e1);
    bool Remove(const K k1, E& e1);
    friend ostream& operator << (ostream &out, HashTable<E,K> &ht2){
        for(int i = 0; i < ht2.TableSize; i++){
            if(ht2.ht[i] != NULL){
                out << "#" << i << ":\t";
            }
            ChainNode<E, K>* current = ht2.ht[i];
            while (current) {
                out << current->data;
                current = current -> link;
                out << endl;
            }
        }
        return out;
    }
    friend istream& operator >> (istream &in, HashTable<E,K> &ht2){
        E data;
        in >> data;
        while (data != 0){
            ht2.Insert(data);
            assert(in >> data);
        }
        return in;
    }
private:
    int divisor;    // 除数，必须是质数
    int TableSize;      //容量，桶的个数
    ChainNode<E, K>** ht;       //散列表定义
    ChainNode<E, K>* FindPos(const K k1);       //散列
};

template <typename E, typename K>
HashTable<E, K>::HashTable(int d, int sz){
    divisor = d;
    TableSize = sz;
    ht = new ChainNode<E, K>* [sz];
    assert(ht != NULL);
}

template <typename E, typename K>
ChainNode<E, K>* HashTable<E, K>::FindPos(const K k1) {
    //在散列表ht中搜索关键码为k1的元素。函数返回一个指向散列表中某位置的指针；
    //若元素不存在，则返回NULL
    int j = k1 % divisor;
    ChainNode<E, K>* p = ht[j];
    while (p != NULL && p -> data != k1){
        p = p -> link;
    }
    return p;
}

template <typename E, typename K>
bool HashTable<E, K>::Search(const K k1, E &e1) {
    if (FindPos(k1) != NULL)
        e1 = FindPos(k1) -> data;
    return FindPos(k1) != NULL;
}

template <typename E, typename K>
bool HashTable<E, K>::Insert(const E &e1) {
    K k1 = e1;
    ChainNode<E, K>* p = ht[k1 % divisor];
    if (p == NULL) {
        ht[k1 % divisor] = new ChainNode<E, K>;
        ht[k1 % divisor] -> data = e1;
        ht[k1 % divisor] -> link = NULL;
    }
    else {
        while (p -> link != NULL){
            p = p -> link;
        }
        p -> link = new ChainNode<E, K>;
        p ->link ->data = e1;
        p -> link -> link = NULL;
    }
    return true;
}

template <typename E, typename K>
bool HashTable<E, K>::Remove(const K k1, E &e1) {
    ChainNode<E, K>* p = FindPos(k1);
    ChainNode<E, K>* current = ht[k1 % divisor];
    ChainNode<E, K>* deletePtr = NULL;
    if (ht[k1 % divisor] == p) {
        deletePtr = ht[k1 % divisor];
        if (ht[k1 % divisor] -> link)ht[k1 % divisor] = ht[k1 % divisor] -> link;
        delete deletePtr;
    }
    while (1) {
        if (current -> link == p) {
            current -> link = current -> link -> link;
            delete current -> link;
            break;
        }
        current = current -> link;
    }
    return true;
}
#endif //OPENHASHTABLE_HASHTABLE_H
