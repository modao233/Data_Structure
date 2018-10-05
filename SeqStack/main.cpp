#include <iostream>
#include "SeqStack.h"
using namespace std;

int main()
{
    SeqStack<int> test;
    int data;
    cin >> data;
    while (data)
    {
        test.Push(data);
        cin >> data;
        if (test.IsFull())break;
    }
    cout << "The SeqStack is: " << test;
    cout << "The stack's size is: " << test.getSize() << endl;
    test.Pop(data);
    cout << "pop the stack:" << data << endl;
    cout << "Now the SeqStack is: " << test;
    return 0;
}