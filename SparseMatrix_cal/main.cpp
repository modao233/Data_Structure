#include <iostream>
#include "MatrixCal.h"
using std::cin;
using std::cout;
using std::endl;
int main() {
    cout << "**************************" << endl;
    cout << "*                        *" << endl;
    cout << "*    -稀疏矩阵运算器-    *" << endl;
    cout << "*                        *" << endl;
    cout << "*    1-矩阵加法          *" << endl;
    cout << "*    2-矩阵减法          *" << endl;
    cout << "*    3-矩阵乘法          *" << endl;
    cout << "*    0-退出              *" << endl;
    cout << "*                        *" << endl;
    cout << "**************************" << endl;

    int i = 1;
    while (i) {
        cout << "请输入0,1,2,3选择进行的运算：";
        cin >> i;
        if(!i)break;
        SparseMatrix<int> a,b;
        cin >> a >> b;

        switch (i) {
            case 1:{
                cout << "矩阵加法运算：" << endl << "======================" << endl;
                a.add(b);
                break;
            }
            case 2:{
                cout << "矩阵减法运算：" << endl << "======================" << endl;
                a.sub(b);
                break;
            }
            case 3:{
                cout << "矩阵乘法运算：" << endl << "======================" << endl;
                a.mul(b);
                break;
            }
        }
    }
    cout << "运算器关闭，谢谢使用" << endl << "======================" << endl;
    return 0;
}
