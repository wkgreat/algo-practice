//
// Created by wkgreat on 2019/12/5.
// 线性表抽象类
//

#ifndef ALGO_PRACTICE_LINEARLIST_H
#define ALGO_PRACTICE_LINEARLIST_H

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
    virtual void output(ostream& out) const = 0;
};

#endif //ALGO_PRACTICE_LINEARLIST_H
