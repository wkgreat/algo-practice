/**
 * 使用C++ STL 中的vector 来实现线性表
 * */

#ifndef ALGO_PRACTICE_VECTORLIST_H
#define ALGO_PRACTICE_VECTORLIST_H

#include <vector>
#include "linearList.h"

using namespace std;

template <class T>
class vectorList : public linearList<T>
{

public:
    //构造函数，复制构造函数，析构函数
    vectorList(int initialCapacity=10);
    vectorList(const vectorList<T>&);
    ~vectorList() {delete element;}

    //ADT
    bool empty() const {return element->empty();};
    int size() const {return element->size();};
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(std::ostream& out) const;

    //增加的方法
    int capacity() const {return (int) element->capacity();}

    //线性表的起始和结束位置的迭代器
    /**
     * vector<T>::iterator 在vector类里也是一个定义的类型 {{typedef __wrap_iter<pointer> iterator;}}
     * 所以使用了typedef typename
     * */
    typedef typename vector<T>::iterator iterator;
    iterator begin() { return element->begin(); }
    iterator end() { return element->end(); }

protected:
    void checkIndex(int theIndex) const;
    vector<T>* element;

};

#endif //ALGO_PRACTICE_VECTORLIST_H
