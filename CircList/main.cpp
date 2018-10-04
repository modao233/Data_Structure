#include <iostream>
#include "CircList.h"
using namespace std;

int main()
{
    CircList<int> test;
    test.inputRear(0);
    int a = 0;
    test.getData(5, a);
    cout << a << endl;
    test.output();
    /*test.Reverse();
    test.output();*/
    return 0;
}