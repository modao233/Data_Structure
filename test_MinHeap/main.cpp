#include <iostream>
#include "MinHeap.h"
using namespace std;
int main(){
    int n;
    cout << "输入结点数：";
    cin >> n;
    int * a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "There are " << n << " nodes in the file.\n";
    cout << "The value of each node is:\n";
    for(int i = 0; i < n; i++)
    {
        cout << "node[" << i << "]: " << a[i] << endl;
    }

    MinHeap<int> h(a, n);
    cout<<"The MinHeap is: \n";
    h.output(0);
    cout<<"\n-----------------------------------------------------"<<endl;
    cout<<"Test bool Insert(const Item& x)"<<endl;
    cout<<"Please input a value to insert : ";
    int t;
    cin>>t;
    h.Insert(t);
    cout<<"The new Minheap is : ";
    h.output(0);
    cout<<"\n-----------------------------------------------------"<<endl;
    cout<<"Test bool RemoveMin(Item& x);"<<endl;
    h.RemoveMin(t);
    cout<<"The new heap is : ";
    h.output(0);
    cout<<"\nThe min removed is : "<<t<<endl;
    return 0;
}
