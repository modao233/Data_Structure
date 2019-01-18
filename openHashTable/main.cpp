#include <iostream>
#include "HashTable.h"
using namespace std;
int main()
{
    HashTable<int, int> m(19, 20);
    cin >> m;
    cout << m;
    return 0;
}