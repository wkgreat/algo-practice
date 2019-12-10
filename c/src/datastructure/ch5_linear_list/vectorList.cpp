//
// Created by wkgreat on 2019/12/6.
//

#include <sstream>
#include "vectorList.h"
#include "../ch1_cpp_basic/code_1_26_exception.h"

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

void vectorList_test() {

    linearList<int> * x = new vectorList<int>(10);
    x->insert(0,1);
    x->insert(0,2);
    x->insert(0,3);
    x->insert(0,4);
    x->output(std::cout);
    cout << endl;
    cout << *x << endl;
    cout << "get(1): " << x->get(1) << endl;

    try{
        x->insert(-1,0);
    }
    catch(illegalIndex e) {
        e.outputMessage();
    }

    cout << endl << "==Iterator===" << endl;

    auto y = dynamic_cast<vectorList<int>*>(x);
    reverse(y->begin(), y->end());
    y->output(std::cout);
    cout << endl;
    y->begin();
}