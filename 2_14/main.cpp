#include <iostream>
#include "SingleList.h"
using namespace std;

int main()
{
    List<int> test;
    test.inputRear(0);
    test.output();
    LinkNode<int>* test2 = test.locate(5);
    cout << test2 -> data << endl;
    test.max();
    int num = test.number(3);
    cout << "出现3的次数为" << num << endl;
    int a[10] = {1, 2, 3, 4, 5, 6, 6, 6, 9, 10};
    test.creat(a, 10);
    cout << "用数组的值建立表单：" << endl;
    test.output();
    cout << "删除相同结点：" << endl;
    test.tidyup();
    test.output();
    return 0;
}