#include <iostream>
using namespace std;
int max(int* a, int n)
{
    int max1 = a[n];
    if (n == 1)max1 = max1 > a[n - 1] ? max1 : a[n - 1];
    else max1 = max1 > max(a, n -1) ? max1 : max(a, n - 1);
    return max1;
}
int sum(int* a, int n)
{
    int sum1 = a[n - 1];
    if (n == 1);
    else sum1 += sum(a, n - 1);
    return sum1;
}
int main()
{
    int n;
    cout << "输入数组大小:" ;
    cin >> n;
    int A[n];
    cout << "输入数组数据:" << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "The max is :" << max(A, n) << endl;
    cout << "The sum is :" << sum(A, n) << endl;
    cout << "The average is :" << sum(A, n) / n << endl;
    return 0;
}
