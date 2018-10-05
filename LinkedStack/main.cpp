#include <iostream>
#include "LinkedStack.h"
using namespace std;
int main()
{
    LinkedStack<int> test;
    int data;
    cin >> data;
    while (data)
    {
        test.Push(data);
        cin >> data;
    }
    cout << "The LinkedStack is :" << test;
    cout << "The stack's size is: " << test.getSize() << endl;
    test.Pop(data);
    cout << "pop the stack:" << data << endl;
    cout << "Now the SeqStack is: " << test;
    return 0;
}