#include <iostream>
#include "SingleList.h"
using namespace std;
int main()
{
    List<int> test;
    test.inputRear(0);
    test.output1();
    cout << "逆转链表后输出（已经将0赋值给原表头结点的值）:" << endl;
    test.Reverse();
    test.output2();
    return 0;
}