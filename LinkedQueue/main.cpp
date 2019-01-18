#include <iostream>
#include "LinkedQueue.h"
using namespace std;

int main()
{
    LinkedQueue<int> test;
    int a;
    cin >> a;
    while (a)
    {
        test.EnQueue(a);
        cin >> a;
    }
    test.DeQueue(a);
    test.DeQueue(a);
    cout << test;
    return 0;
}