//
// Created by wkgreat on 2019/12/6.
//

#include <sstream>
#include "arrayList.h"
#include "../ch1_cpp_basic/code_1_26_illegalParameterValue.cpp"

using namespace std;

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

void arrayList_test() {

    linearList<int> * x = new arrayList<int>(10);
    x->insert(0,1);
    x->insert(0,2);
    x->insert(0,3);
    x->insert(0,4);
    x->output(std::cout);
    cout << endl;
    cout << *x << endl;

    try{
        x->insert(-1,0);
    }
    catch(illegalIndex e) {
        e.outputMessage();
    }

    cout << endl << "==Iterator===" << endl;

    auto y = dynamic_cast<arrayList<int>*>(x);
    reverse(y->begin(), y->end());
    y->output(std::cout);
    cout << endl;
    y->begin();
}