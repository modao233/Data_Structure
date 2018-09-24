#include <iostream>
#include "SeqList.h"

using namespace std;
int main()
{
    SeqList<int> test(15);
    test.input();
    test.output();
    test.RemoveMin();
    test.output();
    int a = test.Remove(2);
    cout << a << endl;
    int b = 666;
    test.Insert(2, b);
    test.output();
    int c = 666;
    test.Remove(c,c);
    test.output();
    int d = 1, e = 5;
    test.Remove_s_to_t(d, e);
    test.output();
    SeqList<int> test2(15);
    test2.input();
    test2.output();
    test.Merge(test2);
    test.output();
    test.RemoveRepeat();
    test.output();
    return 0;
}