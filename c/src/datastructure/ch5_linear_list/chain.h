/**
 * 链表定义
 * 构造函数中还是有initialCapacity参数，目的是与arrayList相容
 * */

#ifndef ALGO_PRACTICE_CHAIN_H
#define ALGO_PRACTICE_CHAIN_H

#include <iterator>
#include "linearList.h"
#include "chainNode.h"

template <class T>
class chain : public linearList<T>
{
public:
    //构造、复制构造、析构函数
    chain(int initialCapacity = 10);
    chain(const chain<T>&);
    ~chain();

    //ADT
    bool empty() const {return listSize==0;}
    int size() const {return listSize;}
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(std::ostream& out) const;

    class iterator;
    iterator begin(){return iterator(firstNode);};
    iterator end(){return iterator(NULL);};

    // iterator for chain
    class iterator
    {
    public:
        // typedefs required by C++ for a forward iterator
        typedef std::forward_iterator_tag iterator_category;
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;

        // constructor
        iterator(chainNode<T>* theNode = NULL)
        {node = theNode;}

        // dereferencing operators
        T& operator*() const {return node->element;}
        T* operator->() const {return &node->element;}

        // increment
        iterator& operator++()   // preincrement
        {node = node->next; return *this;}
        iterator operator++(int) // postincrement
        {iterator old = *this;
            node = node->next;
            return old;
        }

        // equality testing
        bool operator!=(const iterator right) const
        {return node != right.node;}
        bool operator==(const iterator right) const
        {return node == right.node;}
    protected:
        chainNode<T>* node;
    };  // end of iterator class



protected:
    void checkIndex(int theIndex) const;
    chainNode<T>* firstNode;
    int listSize;
};

#endif //ALGO_PRACTICE_CHAIN_H
