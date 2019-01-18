#include <iostream>
#include "sparseMatrix_cal.h"
using namespace std;
int main() {
    int i;
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
    cout << "请输入0,1,2,3选择进行的运算：";
    cin >> i;
    while (i) {
        switch (i) {
            case 1:{
                cout << "矩阵加法运算：" << endl << "======================" << endl;
                Count(i);
                break;
            }
            case 2:{
                cout << "矩阵减法运算：" << endl << "======================" << endl;
                Count(i);
                break;
            }
            case 3:{
                cout << "矩阵乘法运算：" << endl << "======================" << endl;
                multiplication();
                break;
            }
        }
        cout << "请输入0,1,2,3选择进行的运算：";
        cin >> i;
    }
    cout << "运算器关闭，谢谢使用" << endl << "======================" << endl;
    cout << "按任意键加回车结束程序: " << endl << "======================" << endl;
    char c;
    cin >> c;
    return 0;
}