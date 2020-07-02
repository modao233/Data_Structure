//
// Created by 莫道 on 2018/12/27.
//

//
// updated by modao on 2020/7/1.
//

#ifndef PROJECT_SPARSEMATRIXCAL_H
#define PROJECT_SPARSEMATRIXCAL_H

#include <iostream>
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

template <typename T>
class Triple;

template <typename T>
class SparseMatrix{
private:
    int matrixRow = 0, matrixCol = 0, valueCount = 0;
    Triple<T>* data = nullptr;
public:
    SparseMatrix() = default;
    SparseMatrix<T>& add(const SparseMatrix<T>& temp);
    SparseMatrix<T>& sub(const SparseMatrix<T>& temp);
    SparseMatrix<T>& mul(const SparseMatrix<T>& temp);
    template <typename T1>
    friend istream& operator>>(istream& in, SparseMatrix<T1>& temp);
    template <typename T1>
    friend ostream& operator<<(ostream& o, SparseMatrix<T1>& temp);
    template <typename T1>
    friend SparseMatrix<T1>& operator+(SparseMatrix<T1>& a, SparseMatrix<T1>& b);
    template <typename T1>
    friend SparseMatrix<T1>& operator-(SparseMatrix<T1>& a, SparseMatrix<T1>& b);
    template <typename T1>
    friend SparseMatrix<T1>& operator*(SparseMatrix<T1>& a, SparseMatrix<T1>& b);
};

template <typename T>
class Triple{
public:
    int row = 0, col = 0;
    T value = T();
public:
    Triple() = default;
    friend class SparseMatrix<T>;
};

template <typename T>
SparseMatrix<T>& operator+(SparseMatrix<T>& a,SparseMatrix<T>& b){
    a.add(b);
    return a;
}
template <typename T>
SparseMatrix<T>& operator-(SparseMatrix<T>& a,SparseMatrix<T>& b){
    a.sub(b);
    return a;
}
template <typename T>
SparseMatrix<T>& operator*(SparseMatrix<T>& a,SparseMatrix<T>& b){
    a.mul(b);
    return a;
}
template <typename T>
istream& operator>>(istream& in, SparseMatrix<T>& temp){
    cout << "请输入矩阵的行数：";
    in >> temp.matrixRow;
    cout << "请输入矩阵的列数：";
    in >> temp.matrixCol;
    cout << "非零元素个数：" << endl;
    in >> temp.valueCount;
    temp.data = new Triple<T>[temp.valueCount];
    cout << "请以行为主序，以三元组方式输入矩阵元素（输入的行数和列数从1开始，且不能超过矩阵的行数和列数）" << endl;
    int i, r, c, v;
    for(i = 0; i < temp.valueCount; i++){
        in >> r >> c >> v;
        if(r == 0 || r > temp.matrixRow){
            cout << "输入数据无效，请重新输入" << endl;
            i--;
            continue;
        }
        if(c == 0 || r > temp.matrixCol){
            cout << "输入数据无效，请重新输入" << endl;
            i--;
            continue;
        }
        if(r == 0){
            cout << "输入数据无效，请重新输入" << endl;
            i--;
            continue;
        }
        temp.data[i].row = r;
        temp.data[i].col = c;
        temp.data[i].value = v;
    }
    return in;
}

template <typename T>
ostream& operator<<(ostream& o, SparseMatrix<T>& temp){
    T *a[temp.matrixRow+1];
    for(int i = 0; i <= temp.matrixRow; i++)a[i] = new T[temp.matrixCol+1]{0};
    for(int i = 0; i< temp.valueCount; i++){
        a[temp.data[i].row][temp.data[i].col] = temp.data[i].value;
    }
    for(int i = 1; i <= temp.matrixRow; i++){
        for(int j = 1; j <= temp.matrixCol; j++)
            o << a[i][j] << ' ';
        cout << endl;
    }
    for(int i = 1; i <= temp.matrixRow; i++)delete[] a[i];
    return o;
}
template <typename T>
SparseMatrix<T>& SparseMatrix<T>::add(const SparseMatrix<T>& temp){
    if((matrixRow != temp.matrixRow) || (matrixCol != temp.matrixCol)){
        cout << "这两个矩阵无法进行加法运算" << endl;
        return *this;
    }
    for(int i = 0; i< valueCount;i++){
        for(int j = 0; j< temp.valueCount;j++){
            if((data[i].row == temp.data[j].row) && (data[i].col == temp.data[j].col))
                data[i].value += temp.data[j].value;
        }
    }
    cout << *this << endl;
    return *this;
}
template <typename T>
SparseMatrix<T>& SparseMatrix<T>::sub(const SparseMatrix<T>& temp){
    if((matrixRow != temp.matrixRow) || (matrixCol != temp.matrixCol)){
        cout << "这两个矩阵无法进行减法运算" << endl;
        return *this;
    }
    for(int i = 0; i< valueCount;i++){
        for(int j = 0; j< temp.valueCount;j++){
            if((data[i].row == temp.data[j].row) && (data[i].col == temp.data[j].col))
                data[i].value -= temp.data[j].value;
        }
    }
    cout << *this << endl;
    return *this;
}
template <typename T>
SparseMatrix<T>& SparseMatrix<T>::mul(const SparseMatrix& temp){
    if(matrixCol != temp.matrixRow){
        cout << "这两个矩阵无法进行乘法运算" << endl;
        return *this;
    }
    T* a[matrixRow+1];
    for(int i = 0; i <= matrixRow; i++)a[i] = new T[matrixCol+1]{0};
    for(int i = 0; i< valueCount; i++){
        a[data[i].row][data[i].col] = data[i].value;
    }
    T* b[temp.matrixRow+1];
    for(int i = 0; i <= temp.matrixRow; i++)b[i] = new T[temp.matrixCol+1]{0};
    for(int i = 0; i< temp.valueCount; i++){
        b[temp.data[i].row][temp.data[i].col] = temp.data[i].value;
    }
    for(int i = 1; i<=matrixRow; i++){
        for(int j = 1; j <= temp.matrixCol; j++){
            T sum = 0;
            for(int k = 1; k <= matrixCol; k++){
                sum += a[i][k]*b[k][j];
            }
            cout << sum << ' ';
        }
        cout << endl;
    }

    for(int i = 0; i <= matrixRow; i++)delete[] a[i];
    for(int i = 0; i <= temp.matrixRow; i++)delete[] b[i];
    return *this;
}

#endif //PROJECT_SPARSEMATRIXCAL_H
