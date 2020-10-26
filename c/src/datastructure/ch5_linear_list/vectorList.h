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

/**
 * Implementation
 * */
template <class T>
vectorList<T>::vectorList(int initialCapacity)
{
    if(initialCapacity<1)
    {
        ostringstream s;
        s << "InitialCapacity = " << initialCapacity << " Must be > 0";
        throw illegalParameterValue((char *)s.str().c_str());
    }

    element = new vector<T>; //创建容量为0的空向量
    element->reserve(initialCapacity); //vector容量从0增加到initialCapacity
}

template <class T>
vectorList<T>::vectorList(const vectorList<T>& theList)
{ //复制构造函数
    element = new vector<T>(*theList.element);
}

template <class T>
T& vectorList<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    return *(element->begin()+theIndex);
}

template <class T>
int vectorList<T>::indexOf(const T& theElement) const
{
    int theIndex = (int) (find(element->begin(),element->end(), theElement) - element->begin());
    if(theIndex==size()) return -1;
    else return theIndex;
}

template <class T>
void vectorList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    element->erase(begin()+theIndex);
}

template <class T>
void vectorList<T>::checkIndex(int theIndex) const
{ //确定索引theIndex在0和listSize-1之间
    if(theIndex <0 || theIndex >= element->size()) {
        ostringstream s;
        s << "index = " << theIndex << " size = " << element->size();
        throw illegalIndex((char * )s.str().c_str());
    }
}

template <class T>
void vectorList<T>::insert(int theIndex, const T & theElement)
{
    if(theIndex<0 || theIndex>size())
    {
        ostringstream s;
        s << "index = " << theIndex << " size= " << size();
        throw illegalIndex((char *)s.str().c_str());
    }
    element->insert(element->begin()+theIndex, theElement);
}

template <class T>
void vectorList<T>::output(std::ostream& out) const
{
    copy(element->begin(), element->end(), ostream_iterator<T>(out, " "));

}

#endif //ALGO_PRACTICE_VECTORLIST_H
