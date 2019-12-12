//
// Created by ke.wang7 on 2019/12/11.
//

#ifndef ALGO_PRACTICE_MATRIX_H
#define ALGO_PRACTICE_MATRIX_H

#include <iostream>
#include "../ch1_cpp_basic/code_1_26_exception.h"
using namespace std;

template <class T>
class matrix {

    friend ostream &operator <<(ostream&, const matrix<T>&);
public:
    matrix(int theRows=0, int theColumns=0);
    matrix(const matrix<T>&);
    ~matrix() {delete [] element;}
    [[nodiscard]] int rows() const {return theRows;}
    [[nodiscard]] int columns() const {return theColumns;}
    T&operator()(int i, int j) const;
    matrix<T>&operator=(const matrix<T>&);
    matrix<T>operator+() const; //unary +
    matrix<T>operator+(const matrix<T>&) const;
    matrix<T>operator-() const; //unary minus
    matrix<T>operator-(const matrix<T>&) const;
    matrix<T>operator*(const matrix<T>&) const;
    matrix<T>&operator+=(const T&);

private:
    int theRows;
    int theColumns;
    T* element;
};

template <class T>
matrix<T>::matrix(int theRows, int theColumns)
{
    if(theRows < 0 || theColumns < 0)
        throw illegalParameterValue("Rows and columns must be >=0");
    if((theRows==0 || theColumns==0) && (theRows!=0 || theRows!=0))
        throw illegalParameterValue("Either both or neither rows and columns should be zero");
    this->theRows = theRows;
    this->theColumns = theColumns;
    element = new T[theRows*theColumns];
}

template <class T>
matrix<T>::matrix(const matrix<T> & m)
{
    theRows = m.theRows;
    theColumns = m.theColumns;
    element = new T[theRows*theColumns];
    copy(m.element, m.element+theRows*theColumns, element); // copy function
}

//赋值操作符=的重载
template <class T>
matrix<T> & matrix<T>::operator=(const matrix<T> & m)
{
    if(this != &m)
    {
        delete [] element;
        theRows = m.theRows;
        theColumns = m.theColumns;
        element = new T[theRows*theColumns];
        copy(m.element, m.element+theRows*theColumns, element);
    }
    return *this;
}

//() 操作符重载
//矩阵索引是从1开始的
template <class T>
T& matrix<T>::operator()(int i, int j) const
{
    if(i<1 || i>theRows || j<1 || j>theColumns)
        throw maitrixIndexOutOfBounds();
    return element[ (i-1) * theColumns + j-1 ];
}

//矩阵加法
template <class T>
matrix<T> matrix<T>::operator+(const matrix<T> & m) const
{ //返回矩阵 w = (*this) + m
    if(theRows!=m.theRows || theColumns!=m.theColumns)
        throw matrixSizeMismatch();
    matrix<T> w(theRows, theColumns);
    for(int i=0; i<theRows*theColumns; i++) //直接对数组进行操作
        w.element[i] = element[i] + m.element[i];
    return w;
}

//矩阵乘法
template <class T>
matrix<T> matrix<T>::operator*(const matrix<T> & m) const
{
    if(theColumns!=m.theRows)
        throw matrixSizeMismatch();
    matrix<T> w(theRows, m.theColumns);

    //定义矩阵*this, m和w的游标且初始化以为(1,1)元素定位
    int ct=0, cm=0, cw=0;

    //对所有i和j计算w(i,j)
    for(int i=1; i<=theRows; i++)
    {
        for(int j=1; j<=m.theColumns; j++)
        {
            T sum = element[ct] * m.element[cm];

            //累加其余所有项
            for(int k=2; k<=theColumns; k++){
                ct++; //*this中第i行下一项
                cm += m.theColumns; //m中第j列下一项
                sum += element[ct]*m.element[cm];
            }
            w.element[cw++] = sum;

            //从行的起点和下一列重新开始
            ct -= theColumns - 1; //this回到该行起点
            cm = j; //wk m的第j列

        }

        //从下一行和第一列重新开始
        ct += theColumns; //this下一行
        cm = 0; //m的第一列
    }
}

#endif //ALGO_PRACTICE_MATRIX_H
