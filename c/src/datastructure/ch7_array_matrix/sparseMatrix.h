/**
 * TODO 稀疏矩阵(基于线性表的)的实现
 * TODO 同时还有基于多个线性表的实现(如行链表等)
 * 在线性表中，矩阵元素以行主次序进行存储
 * 重点例子 转置及矩阵相加
 * */

#ifndef ALGO_PRACTICE_SPARSEMATRIX_H
#define ALGO_PRACTICE_SPARSEMATRIX_H

#include "../ch5_linear_list/arrayList.h"

template <class T>
class matrixTerm
{
private:
    T value;
    int row, col;
    //TODO...
};

template <class T>
class sparseMatrix
{
public:
    void transpose(sparseMatrix<T> &b);
    void add(sparseMatrix<T> &b, sparseMatrix<T> &c);
    //TODO ...
private:
    int rows, cols;
    arrayList<matrixTerm<T>> terms;
};

#endif //ALGO_PRACTICE_SPARSEMATRIX_H
