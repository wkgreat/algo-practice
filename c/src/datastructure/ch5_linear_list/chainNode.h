//
// Created by wkgreat on 2019/12/8.
// 链表节点

#ifndef ALGO_PRACTICE_CHAINNODE_H
#define ALGO_PRACTICE_CHAINNODE_H

template <class T>
struct chainNode //这里使用了struct
{
    T element;
    chainNode<T> *next;

    chainNode(){}
    chainNode(const T& element) {this->element = element;}
    chainNode(const T& element, chainNode<T>* next) // ** WK 注意next的思想
    {
        this->element = element;
        this->next = next;
    }
};

#endif //ALGO_PRACTICE_CHAINNODE_H
