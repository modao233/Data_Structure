//
// Created by 莫道 on 2018/12/2.
//

#ifndef BST_BST_H
#define BST_BST_H
#include <iostream>
#include <string>
#include <cassert>
#include <stdlib.h>
using namespace std;

template <typename E, typename K>
struct BSTNode {
    E data;
    BSTNode<E, K> *left, *right;
    BSTNode():left(NULL), right(NULL) {}
    BSTNode(const E d, BSTNode<E, K>* L = NULL, BSTNode<E ,K>* R = NULL)
        :data(d), left(L), right(R) {}
    ~BSTNode() {}
    void setData(E d) {data = d;}
    E getData() {
        return data;
    }
    bool operator < (const E &x) {
        return data < x;
    }
    bool operator > (const E &x) {
        return data > x;
    }
    bool operator == (const E &x) {
        return data == x;
    }
    bool operator <= (const E &x) {
        return data <= x;
    }
    bool operator >= (const E &x) {
        return data >= x;
    }
    bool operator != (const E &x) {
        return data != x;
    }
};

template <typename E, typename K>
class BST {
public:
    BST():root(NULL) {}
    BST(K value);
    ~BST() {}
    bool Search(const K x)cosnt {
        return Search(x, root) != NULL;
    }
    BST<E, K>& operator = (const BST<E, K>& R);     //赋值
    void makeEmpty() {
        makeEmpty(root);
        root = NULL;
    }
    bool isEmpty() {
        return root == NULL;
    }
    void PrintTree()const {
        PrintTree(root);
    }
    E Min() {
        return Min(root) -> data;
    }
    E Max() {
        return Max(root) -> data;
    }
    bool Insert(const E& e1) {
        return Insert(e1, root);
    }
    bool Remove(const K x) {
        return Remove(x, root);
    }
    friend istream& operator >> (istream &in, BST<E ,K> &R) {
        E elem;
        in >> elem;
        while (elem) {
            R.Insert(elem);
            assert(in >> elem);
        }
        return in;
    }
    friend ostream& operator << (ostream &out, BST<E, K> &R) {
        out << "The structure of the Binary Search Tree is :\n";
        R.PrintTree();
        out << endl;
        return out;
    }
private:
    BSTNode<E, K> *root;
    K RefValue;
    BSTNode<E ,K>* Search(const K x, BSTNode<E, K>* ptr);
    void makeEmpty(BSTNode<E, K>* &ptr);
    void PrintTree(BSTNode<E, K>* ptr)const;
    BSTNode<E, K>* Copy(const BSTNode<E, K>* ptr);
    BSTNode<E, K>* Min(BSTNode<E, K>* ptr)const;
    BSTNode<E ,K>* Max(BSTNode<E ,K>* ptr)const;
    bool Insert(const E& e1, BSTNode<E ,K>* &ptr);
    bool Remove(const K x, BSTNode<E ,K>* &ptr);
};

template <typename E, typename K>
BST<E, K>::BST(K value) {
    E x;
    root = NULL;
    RefValue = value;
    cout << "Please input the value of the each "
}
#endif //BST_BST_H
