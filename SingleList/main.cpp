#include <iostream>
#include "SingleList.h"
using namespace std;
int main()
{
    List<int> test(5);
    int x = 0;
    test.inputFront(0);
    test.output();
    test.max();
    test.Remove(4,x);
    cout << endl << "删除的数是" << x << endl << "删除后的链表为：" << endl;
    test.output();
    /*try
    {
        int* a = new int(500000000);
        cout << *a;
    }
    catch (const bad_alloc & e)
    {
        cout << "输出错误" << endl;
        return -1;
    }
    //cout << *a << endl;*/
    return 0;
}