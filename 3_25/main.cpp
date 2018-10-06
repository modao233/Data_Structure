#include <iostream>
#include "CircList.h"
using namespace std;
int main()
{
    CircList<int> test;
    int val,n = 0;
    cin >> val;
    while (val)
    {
        test.EnQueue(val);
        cin >> val;
        n++;
    }
    cout << "删除前:" << endl;
    test.output();
    cout << "第一次删除后:" << endl;
    test.DeQueue();
    test.output();
    cout << "第二次删除后:" << endl;
    test.DeQueue();
    test.output();
    return 0;
}