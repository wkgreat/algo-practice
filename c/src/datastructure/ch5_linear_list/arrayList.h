//
// Created by wkgreat on 2019/12/5.
//

#ifndef ALGO_PRACTICE_ARRAYLIST_H
#define ALGO_PRACTICE_ARRAYLIST_H

#include "./linearList.h"
#include <iterator>
#include <sstream>
#include "../ch1_cpp_basic/code_1_26_exception.h"

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

/**
 * Implementation
 * */

template <class T>
arrayList<T>::arrayList(int initialCapacity)
{ //构造函数
    if(initialCapacity<1)
    {
        ostringstream s;
        s << "Initial Capacity = " << initialCapacity << " Must be > 0";
        throw illegalParameterValue((char * )s.str().c_str()); //WK s.str() 返回 string_type
    }
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
}

template <class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{ //复制构造函数
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    copy(theList.element, theList.element+listSize, element); //使用copy
}

template <class T>
void arrayList<T>::checkIndex(int theIndex) const
{ //确定索引theIndex在0和listSize-1之间
    if(theIndex <0 || theIndex >= listSize) {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex((char * )s.str().c_str());
    }
}

template <class T>
T& arrayList<T>::get(int theIndex) const
{ //返回索引为theIndex的元素，若此元素不存在，则返回-1
    checkIndex(theIndex);
    return element[theIndex];
}

template <class T>
int arrayList<T>::indexOf(const T & theElement) const
{ //返回元素theELement第一次出现的索引， 若该元素不存在，则返回-1

    //查找元素 使用了find函数
    int theIndex = (int) (find(element, element+listSize, theElement) - element);

    //确定元素是否找到
    if(theIndex == listSize)
        return -1; //没有找到
    else return theIndex;

}

template <class T>
void arrayList<T>::erase(int theIndex)
{ //删除其索引为theIndex的元素, TODO可以考虑动态减少数组容量，以节省空间
    checkIndex(theIndex);
    // 有效索引，移动其索引大于theIndex的元素
    // WK 注意用法copy在一个序列上使用的，实现了元素的向左平移
    copy(element+theIndex+1, element+listSize, element+theIndex);

    element[--listSize].~T(); //listSize自减1并调用析构函数
}

template <class T>
void arrayList<T>::insert(int theIndex, const T & theElement)
{
    if(theIndex < 0 || theIndex > listSize)
    { //无效索引
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex((char * )s.str().c_str());
    }
    //有效索引，确定数组是否已满
    if(listSize==arrayLength)
    {   //数组空间已满，数组长度倍增
        changeLength1D(element, arrayLength, 2*arrayLength);
        arrayLength*=2;
    }

    //使用copy_backward来实现元素的向右平移
    copy_backward(element+theIndex, element+listSize, element+listSize+1);
    element[theIndex] = theElement;
    listSize++;
}

template <class T>
void changeLength1D(T*& a, int oldLength, int newLength)
{ //改变一个一维数组的长度
    if(newLength<0) {
        throw illegalParameterValue("new length must be > 0");
    }
    T* temp = new T[newLength];
    int number = min(oldLength,newLength);
    copy(a, a+number, temp);
    delete [] a;
    a = temp;
}

template <class T>
void arrayList<T>::output(std::ostream& out) const
{
    copy(element, element+listSize, ostream_iterator<T>(out, " "));
}

#endif //ALGO_PRACTICE_ARRAYLIST_H
