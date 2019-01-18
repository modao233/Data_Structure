#include <iostream>
#include "HashTable2.h"
using namespace std;
int main()
{
    HashTable<int, int> m(19, 19);
    cin >> m;
    cout << m;
    return 0;
}