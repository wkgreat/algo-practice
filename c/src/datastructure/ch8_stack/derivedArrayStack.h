//
// Created by wkgreat on 2019/12/22.
// 使用arrayList来派生stack
// 这种方法性能不高

#ifndef ALGO_PRACTICE_DERIVEDARRAYSTACK_H
#define ALGO_PRACTICE_DERIVEDARRAYSTACK_H

#include "./stack.h"
#include "../ch5_linear_list/arrayList.h"

template <class T>
class derivedArrayStack : private arrayList<T>, public stack<T>
{
public:
    derivedArrayStack(int initialCapacity = 10) : arrayList<T>(initialCapacity) {}
    bool empty() const { return arrayList<T>::empty(); }
    int size() const { return arrayList<T>::size(); }
    T& top()
    {
        if(empty()) throw stackEmpty();
        return arrayList<T>::get(arrayList<T>::size()-1);
    }
    void pop()
    {
        if(empty()) throw stackEmpty();
        arrayList<T>::erase(arrayList<T>::size()-1);
    }
    void push(const T& theElement)
    {
        arrayList<T>::insert(arrayList<T>::size(), theElement);
    }
};

#endif //ALGO_PRACTICE_DERIVEDARRAYSTACK_H
