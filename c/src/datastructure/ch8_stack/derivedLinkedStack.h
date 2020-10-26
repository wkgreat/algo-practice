//
// Created by wkgreat on 2019/12/24.
// 栈的链表实现，应该使用链表的左边作为栈顶

#ifndef ALGO_PRACTICE_DERIVEDLINKEDSTACK_H
#define ALGO_PRACTICE_DERIVEDLINKEDSTACK_H

#include "../ch5_linear_list/chainNode.h"
#include "../ch1_cpp_basic/code_1_26_exception.h"

template<class T>
class linkedStack : public stack<T>
{
public:
    linkedStack(int initialCapacity=10)
    { stackTop = NULL; stackSize=0; }
    ~linkedStack();
    bool empty() const { return stackSize==0; }
    int size() const { return stackSize; }
    T& top()
    {
        if(stackSize==0) throw stackEmpty();
        return stackTop->element;
    }
    void pop();
    void push(const T& theElement)
    {
        stackTop = chainNode<T>(theElement, stackTop);
        stackSize++;
    }
private:
    chainNode<T>* stackTop; //栈顶指针
    int stackSize; //栈中元素个数
};

//implementation

template <class T>
linkedStack<T>::~linkedStack()
{
    while(stackTop!=NULL)
    {
        chainNode<T>* nextNode = stackTop->next;
        delete stackTop;
        stackTop = nextNode;
    }
}

template <class T>
void linkedStack<T>::pop()
{
    if(stackSize==0) throw stackEmpty();
    chainNode<T>* nextNode = stackTop->next;
    delete stackTop;
    stackTop = nextNode;
    stackSize--;
}

#endif //ALGO_PRACTICE_DERIVEDLINKEDSTACK_H
