//
// Created by wkgreat on 2019/12/5.
//

#ifndef ALGO_PRACTICE_ARRAYLIST_H
#define ALGO_PRACTICE_ARRAYLIST_H

#include "./linearList.h"
#include <iterator>

template <class T>
class arrayList : public linearList<T> // WK 在父类上别忘加泛型
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
    void output(std::ostream& out) const;

    //其他方法
    int capacity() const {return arrayLength;}
    class iterator;
    iterator begin() {return iterator(element); }
    iterator end() {return iterator(element+listSize); }

    //双向迭代器
    class iterator
    {
    public:
        //用typedef语句实现双向迭代器
        typedef std::bidirectional_iterator_tag iterator_category; //类别为双向迭代器
        typedef T value_type;
        typedef std::ptrdiff_t difference_type; //ptrdiff_t 两个指针减法的结果
        typedef T* pointer;
        typedef T& reference;

        //构造函数
        iterator(T* thePosition = 0) {position = thePosition;}
        T& operator*() const {return *position;}
        T* operator->() const {return position;}
        iterator& operator++() {++position; return *this;} //前加
        iterator operator++(int) //后加 小心 返回的是iterator而不是iterator&
        {
            iterator old = *this;
            ++position;
            return old;
        }

        //迭代器的值减小
        iterator& operator--() {--position; return *this;} //前减
        iterator operator--(int) //后减 小心 返回的是iterator而不是iterator&
        {
            iterator old = *this;
            --position;
            return old;
        }

        //测试是否相等
        bool operator!=(const iterator right) const { return position!=right.position; }
        bool operator==(const iterator right) const { return position==right.position; }

    protected:
        T* position;

    };

protected:
    void checkIndex(int theIndex) const; //若索引theIndex无效，则抛出异常
    T* element; //存储线性表元素的以为数组
    int arrayLength; //一维数组的容量
    int listSize; //线性表的元素个数

};

//改变一个一维数组的长度
template <class T>
void changeLength1D(T*& a, int oldLength, int newLength);

#endif //ALGO_PRACTICE_ARRAYLIST_H
