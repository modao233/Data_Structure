#include <iostream>
#include "SeqQueue.h"
using namespace std;
int main()
{
    SeqQueue<int> test(5);
    int a;
    cin >> a;
    while(a)
    {
        test.EnQueue(a);
        cin >> a;
    }
    cout << test;
    test.DeQueue(a);
    cout << "DeQueue is :" << a << endl;
    test.getFront(a);
    cout << "The front is " << a << endl;
    cout << "Print the queue :" << endl;
    cout << test;
    return 0;
}