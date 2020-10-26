/**
 * 链表定义
 * 构造函数中还是有initialCapacity参数，目的是与arrayList相容
 * */

#ifndef ALGO_PRACTICE_CHAIN_H
#define ALGO_PRACTICE_CHAIN_H

#include <iterator>
#include <sstream>
#include "../ch1_cpp_basic/code_1_26_exception.h"
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


/**
 * Implementation
 * */
template <class T>
chain<T>::chain(int initialCapacity)
{
    if(initialCapacity < 1)
    {
        ostringstream s;
        s << "Initial Capacity = " << initialCapacity << " Must be > 0";
        throw illegalParameterValue((char*)s.str().c_str());
    }
    firstNode = NULL;
    listSize = 0;
}

template <class T>
chain<T>::chain(const chain<T>& theList)
{ //复制构造函数
    listSize = theList.listSize;

    if(listSize==0)
    { //如果链表为空
        firstNode = NULL;
        return;
    }

    //链表不为空
    chainNode<T>* sourceNode = theList.firstNode;
    firstNode = new chainNode<T>(sourceNode->element); //复制链表的首元素

    sourceNode = sourceNode->next;
    chainNode<T>* targetNode = firstNode;
    while(sourceNode!=NULL)
    { //复制剩余元素
        targetNode->next = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode->next = NULL; //链表结束

}

template <class T>
chain<T>::~chain()
{ //析构函数
    while(firstNode!=NULL)
    {
        chainNode<T>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template <class T>
T & chain<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    chainNode<T>* currentNode = firstNode;
    for(int i=0; i<theIndex; i++) {
        currentNode = firstNode->next;
    }
    return currentNode->element;
}

template <class T>
int chain<T>::indexOf(const T & theElement) const
{
    chainNode<T>* currentNode = firstNode;
    int index = 0;
    while(currentNode!=NULL && currentNode->element!=theElement)
    {
        currentNode = currentNode->next;
        index++;
    }
    if(currentNode==NULL) return -1;
    else return index;
}

/**
 * 删除节点，分为三种情况：
 *  1）theIndex<0 or theIndex>=listSize，删除操作无效
 *  2）删除非空表的第0个元素节点
 *  3）删除其他元素节点
 * */
template <class T>
void chain<T>::erase(int theIndex)
{//删除索引为theIndex的元素
    checkIndex(theIndex); //若该元素不存在，则抛出异常

    chainNode<T>* deleteNode;
    if(theIndex==0)
    { //删除链表的首节点
        deleteNode = firstNode;
        firstNode = deleteNode->next;
    } else { //用指针指向要删除节点的前驱节点
        chainNode<T>* p = firstNode;
        for(int i=0; i<theIndex-1; i++)
            p = p->next;
        deleteNode = p->next;
        p->next = p->next->next;
    }
    listSize--;
    delete deleteNode;
}


template <class T>
void chain<T>::insert(int theIndex, const T & theElement)
{//在索引theIndex的位置插入元素theElement
    if(theIndex<0 || theIndex>listSize)
    {//无效索引
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex((char*)s.str().c_str());
    }
    if(theIndex==0)
        firstNode = new chainNode<T>(theElement, firstNode); //在头部插入
    else
    {
        chainNode<T>*p = firstNode;
        for(int i=0; i<theIndex-1; i++)
            p = p->next;
        p->next = new chainNode<T>(theElement, p->next); //在p后插入
    }
}

template <class T>
void chain<T>::output(std::ostream & out) const
{
    for(chainNode<T>* currentNode = firstNode;
        currentNode!=NULL;
        currentNode=currentNode->next)
        cout << currentNode->element << " ";
}

template <class T>
void chain<T>::checkIndex(int theIndex) const
{ //确定索引theIndex在0和listSize-1之间
    if(theIndex <0 || theIndex >= listSize) {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex((char * )s.str().c_str());
    }
}

#endif //ALGO_PRACTICE_CHAIN_H
