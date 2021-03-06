//
// Created by wkgreat on 2019/12/5.
// 线性表抽象类
//

#ifndef ALGO_PRACTICE_LINEARLIST_H
#define ALGO_PRACTICE_LINEARLIST_H

#include <iostream>
#include <algorithm>

template <class T>
class linearList
{
public:
    virtual ~linearList(){};
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual T& get(int theIndex) const = 0;
    virtual int indexOf(const T& theElement) const = 0;
    virtual void erase(int theIndex) = 0;
    virtual void insert(int theIndex, const T& theElement) = 0;
    virtual void output(std::ostream& out) const = 0;
};

/**
 * 重载<<运算符
 * */
template <class T>
std::ostream& operator<<(std::ostream& out, const linearList<T>& x)
{
    x.output(out);
    return out;
}

#endif //ALGO_PRACTICE_LINEARLIST_H
