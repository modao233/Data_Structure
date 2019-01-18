#pragma once
#ifndef HAFFMANTREE_H
#define HAFFMANTREE_H
#include "MinHeap.h"
#include <iostream>
#include <string>
using namespace std;

template <class T, class E>
struct HuffmanNode {
    E data;
    HuffmanNode<T, E> *leftChild, *rightChild, *parent;
    HuffmanNode() :leftChild(NULL), rightChild(NULL), parent(NULL) {}
    HuffmanNode(E elem, HuffmanNode<T, E> *left, HuffmanNode<T, E> *right, HuffmanNode<T, E> *pr)
            :data(elem), parent(pr), leftChild(left), rightChild(right) {}
    bool operator > (HuffmanNode<T, E> right) {
        return data > right.data;
    }
    bool operator >= (HuffmanNode<T, E> right) {
        return data >= right.data;
    }
    bool operator < (HuffmanNode<T, E> right) {
        return data < right.data;
    }
    bool operator <= (HuffmanNode<T, E> right) {
        return data <= right.data;
    }
    bool operator == (HuffmanNode<T, E> right) {
        return data == right.data;
    }
};

template <class T, class E>
class HuffmanTree {
public:
    HuffmanTree(E w[], int n);
    ~HuffmanTree() {
        deleteTree(root);
    }
    HuffmanNode<T, E>* getRoot() {
        return root;
    }
    void output(HuffmanNode<T, E> *t, string str, ostream &out);
protected:
    HuffmanNode<T, E> *root;
    void deleteTree(HuffmanNode<T, E> *t);
    void mergeTree(HuffmanNode<T, E> *ht1, HuffmanNode<T, E> *ht2, HuffmanNode<T, E>* &parent);
};

template <class T, class E>
void HuffmanTree<T, E>::deleteTree(HuffmanNode<T, E> *t) {
    if (t != NULL) {
        deleteTree(t->leftChild);
        deleteTree(t->rightChild);
        delete t;
    }
}

template <class T, class E>
void HuffmanTree<T, E>::output(HuffmanNode<T, E> *t, string str, ostream &out) {
    if (!t) {
        return;
    }
    out << str << t->data;
    if (t->leftChild) {
        out << "©¤©´" << endl;
        if (t->rightChild) {
            output(t->leftChild, str + "©¦¡¡", out);
        }
        else {
            output(t->leftChild, str + "¡¡¡¡", out);
        }
    }
    if (t->rightChild) {
        out << endl << str << "©¸©¤©´" << endl;
        output(t->rightChild, str + "¡¡¡¡", out);
    }
}

template <class T, class E>
HuffmanTree<T, E>::HuffmanTree(E w[], int n) {
    MinHeap<T, HuffmanNode<T, E>> hp;
    HuffmanNode<T, E> *parent = NULL, *first, *second, temp;
    HuffmanNode<T, E> *NodeList;
    int i;
    for (i = 0; i < n; i++) {
        NodeList = new HuffmanNode<T, E>;
        NodeList->data = w[i + 1];
        NodeList->leftChild = NULL;
        NodeList->rightChild = NULL;
        NodeList->parent = NodeList;
        hp.Insert(*NodeList);
    }
    for (i = 0; i < n - 1; i++) {
        hp.RemoveMin(temp);
        first = temp.parent;
        hp.RemoveMin(temp);
        second = temp.parent;
        mergeTree(first, second, parent);
        hp.Insert(*parent);
    }
    root = parent;
    cout << "       root = " << root->data << endl;
    output(root, string(), cout);
}

template <class T, class E>
void HuffmanTree<T, E>::mergeTree(HuffmanNode<T, E> *bt1, HuffmanNode<T, E> *bt2, HuffmanNode<T, E> *& parent) {
    parent = new HuffmanNode<T, E>;
    parent->leftChild = bt1;
    parent->rightChild = bt2;
    parent->parent = parent;
    parent->data = bt1->data + bt2->data;
    bt1->parent = bt2->parent = parent;
    cout << bt1->data << " and " << bt2->data << " union to; " << parent->data << endl;
}
#endif