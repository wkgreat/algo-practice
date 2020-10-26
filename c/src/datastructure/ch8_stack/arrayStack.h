//
// Created by wkgreat on 2019/12/24.
// 比derivedArrayStack性能更好

#ifndef ALGO_PRACTICE_ARRAYSTACK_H
#define ALGO_PRACTICE_ARRAYSTACK_H

#include <sstream>
#include "../ch1_cpp_basic/code_1_26_exception.h"
#include "./stack.h"

template <class T>
void changeLength1D(T*& a, int oldLength, int newLength);

template <class T>
class arrayStack : public stack<T>
{
public:
    arrayStack(int initialCapacity=10);
    ~arrayStack() { delete [] stack; }
    bool empty() const { return stackTop == -1; }
    int size() const { return stackTop+1; }
    void output() const;
    T& top()
    {
        if (stackTop==-1) throw stackEmpty();
        return stack[stackTop];
    }
    void pop()
    {
        if(stackTop==-1) throw stackEmpty();
        stack[stackTop--].~T(); //T的析构函数
    }
    void push(const T& theElement);
protected:
    int stackTop;
    int arrayLength;
    T* stack;
};

//implementation
template <class T>
arrayStack<T>::arrayStack(int initialCapacity)
{ //构造函数
    if(initialCapacity < 1)
    {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << "Must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCapacity;
    stack = new T[arrayLength];
    stackTop = -1;
}

template <class T>
void arrayStack<T>::push(const T & theElement)
{ //将元素压入栈
    if(stackTop == arrayLength-1)
    { //栈满, 容量加倍
        changeLength1D(stack, arrayLength, 2*arrayLength);
        arrayLength *= 2;
    }
    stack[++stackTop] = theElement;

}

template <class T>
void arrayStack<T>::output() const
{
    if(!empty())
    {
        copy(stack, stack+stackTop+1, ostream_iterator<T>(cout, " - "));
    } else {
        cout << "N";
    }
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

#endif //ALGO_PRACTICE_ARRAYSTACK_H
