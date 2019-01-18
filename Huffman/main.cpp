#include <iostream>
#include <cassert>
#include "HuffmanTree.h"
#include "MinHeap.h"
using namespace std;
int main() {
    int n, i;
    cin >> n;
    int *w = new int[n + 1];
    cout << "There are " << n << " nodes in the file.\n";
    cout << "The weight of each node is:\n";
    for (i = 1; i <= n; i++) {
        cin >> w[i];
        cout << "weight[" << i << "]: " << w[i] << endl;
    }
    cout << "\nCreate huffman tree:\n";
    HuffmanTree<int, int> htree(w, n);
    cout << endl;
    delete w;
    return 0;
}