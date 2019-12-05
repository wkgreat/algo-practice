//
// Created by wkgreat on 2019/12/5.
//

#ifndef ALGO_PRACTICE_ARRAYLIST_H
#define ALGO_PRACTICE_ARRAYLIST_H

#include "linearList.h"

template <class T>
class arrayList : public linearList
{
public:
    //构造函数，复制构造函数，析构函数
    arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T>&);
    ~arrayList() {delete [] element;}

    //ADT 方法
    bool empty() const {return listSize==0;}
    int size() const {return listSize;}
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;

    //其他方法
    int capacity() const {return arrayLength();}

protected:
    void checkIndex(int theIndex) const; //若索引theIndex无效，则抛出异常
    T* element; //存储线性表元素的以为数组
    int arrayLength; //一维数组的容量
    int listSize; //线性表的元素个数

};

#endif //ALGO_PRACTICE_ARRAYLIST_H
