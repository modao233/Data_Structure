#include "BinaryTree.h"
#include <iostream>
#include <cassert>
using namespace std;

void visit(BinTreeNode<int> *t)
{
    cout << t->data << "   ";
}

int main(){
    BinaryTree<int> binTree(0);
    cin >> binTree;
    cout << "The binary tree is: \n" << binTree << endl;
    binTree.Output();
    BinaryTree<int> binTree1(binTree);
    cout << "The copy binary tree is: \n" << binTree1 << endl;
    binTree1.Output();

    cout << "\nThe preorder of the binary tree is:\n";
    binTree.PreOrder(visit);
    cout << "\n\nThe inorder of the binary tree is:\n";
    binTree.InOrder(visit);
    cout << "\n\nThe postorder of the binary tree is:\n";
    binTree.PostOrder(visit);
    cout << "\n\nThe levelOrder of the binary tree is:\n";
    binTree.levelOrder(visit);
    cout << "\n\nThe height of the binary tree is:\n";
    cout<<binTree.Height();
    cout << "\n\nThe Size of the binary tree is:\n";
    cout<<binTree.Size();
    cout << endl << endl;

    cout << "Create a complete Binary tree from an array:\n";
    cout << "Input the nodes num in the binary tree: ";
    unsigned num;
    assert(cin >> num);
    int *CBT = new int[num];
    cout << "\nThe data in the array is:\n";
    for (unsigned i = 0; i < num; i++)
    {
        CBT[i] = i+1;
        cout << "   " << i+1;
    }
    cout << endl;
    BinaryTree<int> binTree2;
    binTree2.CreateCompBinTree(CBT, num);
    cout << "The binary tree is: \n" << binTree2 << endl;
    binTree2.Output();

    cout << "\nThe preorder of the binary tree is:\n";
    binTree2.PreOrder1(visit);
    cout << "\n\nThe inorder of the binary tree is:\n";
    binTree2.InOrder1(visit);
    cout << "\n\nThe postorder of the binary tree is:\n";
    binTree2.PostOrder1(visit);
    cout << "\n\nThe levelOrder of the binary tree is:\n";
    binTree2.levelOrder(visit);
    cout << endl << endl;
    delete []CBT;

    return 0;
}
