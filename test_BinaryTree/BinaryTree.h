//
// Created by 莫道 on 2018/11/8.
//

#ifndef TEST_BINARYTREE_BINARYTREE_H
#define TEST_BINARYTREE_BINARYTREE_H

#include <iostream>
#include <string>
#include <cassert>
#include "LinkedStack.h"
#include "LInkedQueue.h"
using namespace std;

template <class T>
struct BinTreeNode
{
    T data;
    BinTreeNode<T>* leftChild;
    BinTreeNode<T>* rightChild;

    BinTreeNode():leftChild(NULL), rightChild(NULL){}
    BinTreeNode(T x, BinTreeNode<T>* l = NULL, BinTreeNode<T>* r = NULL)
        :leftChild(l), rightChild(r)
    {
        data = x;
    }
};
template <class T>
struct stkNode
{
    BinTreeNode<T>* ptr;
    int tag;
    stkNode(BinTreeNode<T>* N = NULL):ptr(N), tag(0){}
};
template <class T>
class BinaryTree
{
protected:
    BinTreeNode<T>* root;
    T RefValue;
    void CreateBinTree(istream& in, BinTreeNode<T>* &subTree)
    {
        T item;
        if (in >> item)
        {
            if (item != RefValue)
            {
                subTree = new BinTreeNode<T>(item);
                assert(subTree);
                CreateBinTree(in, subTree -> leftChild);
                CreateBinTree(in, subTree -> rightChild);
            }
            else
            {
                subTree = NULL;
            }
        }
    }
    void CreateCompBinTree(T* CBT, int num, int rt, BinTreeNode<T>* &subTree)
    {
        if (rt >= num)
        {
            subTree = NULL;
        }
        else
        {
            subTree = new BinTreeNode<T>(CBT[rt]);
            assert(subTree);
            CreateCompBinTree(CBT, num, 2*rt+1, subTree -> leftChild);
            CreateCompBinTree(CBT, num, 2*rt+2, subTree -> rightChild);
        }
    }
    void printBinTree(BinTreeNode<T>* subTree, ostream& out)
    {
        if (subTree)
        {
            out << subTree -> data;
            if (subTree -> leftChild || subTree -> rightChild)
            {
                out << "(";
                printBinTree(subTree -> leftChild, out);
                if (subTree -> rightChild)
                    out << ",";
                printBinTree(subTree -> rightChild, out);
                out << ")";
            }
        }
    }
    void Output(BinTreeNode<T>* subTree, string str, ostream& out)
    {
        if (!subTree)return;
        out << str << subTree -> data;
        if (subTree -> leftChild)
        {
            out << "─┐" << endl;
            if (subTree -> rightChild)
            {
                Output(subTree -> leftChild, str + "│　", out);
            }
            else
            {
                Output(subTree -> leftChild, str + "　　", out);
            }
        }
        if (subTree -> rightChild)
        {
            out << endl << str << "└─┐" << endl;
            Output(subTree -> rightChild, str + "　　", out);
        }
    }
    bool Insert(BinTreeNode<T>* &subTree, T& x)
    {
        if (!subTree)
        {
            subTree = new BinTreeNode<T>(x);
            assert(subTree);
            return true;
        }
        else
        {
            return Insert(subTree -> leftChild, x) || Insert(subTree -> rightChild, x);
        }
    }
    void destroy(BinTreeNode<T>* &subTree)
    {
        if (subTree != NULL)
        {
            destroy(subTree -> leftChild);
            destroy(subTree -> rightChild);
            delete subTree;
        }
    }
    bool Find(BinTreeNode<T>* subTree, T& x)
    {
        if (!subTree)
            return false;
        if (subTree -> data == x)
            return true;
        bool p = false;
        p = Find(subTree -> leftChild, x);
        if (p)
            return true;
        else
            return Find(subTree -> rightChild, x);
    }
    BinTreeNode<T>* Copy(BinTreeNode<T>* r)
    {
        if (!r)return NULL;
        BinTreeNode<T>* p = new BinTreeNode<T>(r -> data);
        p -> leftChild = Copy(r -> leftChild);
        p -> rightChild = Copy(r -> rightChild);
        return p;
    }
    int Height(BinTreeNode<T>* subTree)const
    {
        if (subTree == NULL)
            return 0;
        else
        {
            int i = Height(subTree -> leftChild);
            int j = Height(subTree -> rightChild);
            return (i < j) ? j + 1 : i + 1;
        }
    }
    int Size(BinTreeNode<T>* subTree)const
    {
        if (subTree == NULL)
            return 0;
        else
            return 1 + Size(subTree -> leftChild) + Size(subTree -> rightChild);
    }
    BinTreeNode<T>* Parent(BinTreeNode<T>* subTree, BinTreeNode<T>* t)
    {
        if (subTree == NULL)
            return NULL;
        if (subTree -> leftChild == t || subTree -> rightChild == t)
            return subTree;
        BinTreeNode<T>* p;
        if (p = Parent(subTree -> leftChild, t) != NULL)
            return p;
        else
            return Parent(subTree -> rightChild, t);
    }
    void Traverse(BinTreeNode<T>* subTree, ostream& out)
    {
        if (subTree)
        {
            out << subTree -> data << ' ';
            Traverse(subTree -> leftChild, out);
            Traverse(subTree -> rightChild, out);
        }
    }
    void PreOrder(BinTreeNode<T>* subTree, void (*visit)(BinTreeNode<T>* t))
    {
        if (subTree)
        {
            visit(subTree);
            PreOrder(subTree -> leftChild, visit);
            PreOrder(subTree -> rightChild, visit);
        }
    }
    void InOrder(BinTreeNode<T>* subTree, void (*visit)(BinTreeNode<T>* t))
    {
        if (subTree)
        {
            InOrder(subTree -> leftChild, visit);
            visit(subTree);
            InOrder(subTree -> rightChild, visit);
        }
    }
    void PostOrder(BinTreeNode<T>* subTree, void (*visit)(BinTreeNode<T>* t))
    {
        if (subTree)
        {
            PostOrder(subTree -> leftChild, visit);
            PostOrder(subTree -> rightChild, visit);
            visit(subTree);
        }
    }

public:
    BinaryTree():root(NULL){}
    BinaryTree(T value):root(NULL)
    {
        RefValue = value;
    }
    BinaryTree(BinaryTree<T>& s)
    {
        if (this != &s)
        {
            root = Copy(s.root);
        }
    }
    ~BinaryTree()
    {
        destroy(root);
    }
    bool IsEmpty()
    {
        return root == NULL;
    }
    bool Find(T& x)
    {
        return Find(root, x);
    }
    int Height()
    {
        return Height(root);
    }
    int Size()
    {
        return Size(root);
    }
    BinTreeNode<T>* Parent(BinTreeNode<T>* t)
    {
        return (root == NULL || root == t) ? NULL : Parent(root, t);
    }
    BinTreeNode<T>* LeftChild(BinTreeNode<T>* t)
    {
        return (t != NULL) ? t -> leftChild : NULL;
    }
    BinTreeNode<T>* RightChild(BinTreeNode<T>* t)
    {
        return (t != NULL) ? t -> rightChild : NULL;
    }
    BinTreeNode<T>* getRoot()const
    {
        return root;
    }
    void PreOrder(void (*visit)(BinTreeNode<T>* t))
    {
        PreOrder(root, visit);
    }
    void InOrder(void (*visit)(BinTreeNode<T>* t))
    {
        InOrder(root, visit);
    }
    void PostOrder(void (*visit)(BinTreeNode<T>* t))
    {
        PostOrder(root, visit);
    }
    bool Insert(T item)
    {
        return Insert(root, item);
    }
    void CreateCompBinTree(T *CBT, int num){//建立完全二叉树
        CreateCompBinTree(CBT, num, 0, root);
    }
    //for E530
    void printBinTree(ostream &out = cout){//按广义表打印
        printBinTree(root, out);
    }
    void Output(ostream &out = cout){//按缩格文本输出
        out << "The structure of the binary tree is:\n";
        Output(root, string(" "), out);
        out << endl;
    }
    void levelOrder(void (*visit)(BinTreeNode<T>* t))
    {
        if (root == NULL)return;
        LinkedQueue<BinTreeNode<T>*> Q;
        BinTreeNode<T>* p = root;
        visit(p);
        Q.EnQueue(p);
        while (!Q.IsEmpty())
        {
            Q.DeQueue(p);
            if (p -> leftChild != NULL)
            {
                visit(p -> leftChild);
                Q.EnQueue(p -> leftChild);
            }
            if (p -> rightChild != NULL)
            {
                visit(p -> rightChild);
                Q.EnQueue(p -> rightChild);
            }
        }
    }
    void PreOrder1(void (*visit)(BinTreeNode<T>* t))
    {
        LinkedStack<BinTreeNode<T>*> S;
        BinTreeNode<T>* p = root;
        S.Push(NULL);
        while (p != NULL)
        {
            visit(p);
            if (p -> rightChild != NULL)S.Push(p -> rightChild);
            if (p -> leftChild != NULL)p = p -> leftChild;
            else S.Pop(p);
        }
    }
    void InOrder1(void (*visit)(BinTreeNode<T>* t))
    {
        LinkedStack<BinTreeNode<T>*> S;
        BinTreeNode<T>* p = root;
        do
        {
            while (p != NULL)
            {
                S.Push(p);
                p = p -> leftChild;
            }
            if (!S.IsEmpty())
            {
                S.Pop(p);
                visit(p);
                p = p -> rightChild;
            }
        }while (p != NULL || !S.IsEmpty());
    }
    void PostOrder1(void (*visit)(BinTreeNode<T>* t))
    {
        LinkedStack<stkNode<T>> S;
        stkNode<T> w;
        BinTreeNode<T>* p = root;
        do
        {
            while (p != NULL)
            {
                w.ptr = p;
                w.tag = 0;
                S.Push(w);
                p = p -> leftChild;
            }
            int continue1 = 1;
            while (continue1 && !S.IsEmpty())
            {
                S.Pop(w);
                p = w.ptr;
                switch (w.tag)
                {
                    case 0: w.tag = 1;S.Push(w);
                        continue1 = 0;
                        p = p -> rightChild;
                        break;
                    case 1: visit(p);
                        break;
                }
            }
        }while (!S.IsEmpty());
        cout << endl;
    }

    friend istream& operator >> (istream& in, BinaryTree<T>& Tree)
    {
        Tree.CreateBinTree(in, Tree.root);
        return in;
    }
    friend ostream& operator << (ostream& out, BinaryTree<T>& Tree)
    {
        Tree.printBinTree(out);
        out << endl;
        return out;
    }
};
#endif //TEST_BINARYTREE_BINARYTREE_H
