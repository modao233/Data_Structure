#include <iostream>
#include "SeqList.h"
using namespace std;
int main()
{
    SeqList<int> test(15);
    int array = 666;
    test.input();
    test.Insert(0,array);
    cout << "链表长度为：" << test.Length() << endl;
    cout << "链表最大容量为：" << test.Size() << endl;
    test.output();
    return 0;
}