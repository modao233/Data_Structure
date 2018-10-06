#include <iostream>
#include "SingleList.h"
using namespace std;
template <class T>
T maxm(LinkNode<T>* current)
{
    T max = current -> data;
    if (current -> link == NULL)max = current -> data;
    else max = max > maxm(current -> link) ? max : maxm(current -> link);
    return max;
}
template <class T>
int num1(LinkNode<T>* current)
{
    int n = 1;
    if (current == NULL);
    else n += num1(current -> link);
    return n;
}
template <class T>
T summ(LinkNode<T>* current)
{
    int sum = current -> data;
    if (current -> link == NULL);
    else sum += summ(current -> link);
    return sum;
}
int main()
{
    List<int> test(5);
    test.inputFront(0);
    test.output();
    cout << "The max is " << maxm(test.getHead() -> link) << endl;
    cout << "The num of List's Node(包括附加头结点) is " << num1(test.getHead() -> link) << endl;
    cout << "The sum of List is " << summ(test.getHead() -> link) << endl;
    return 0;
}