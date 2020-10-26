//
// Created by wkgreat on 2019/12/25.
// 汉诺塔
//

#include <iostream>
#include "arrayStack.h"
using namespace std;

/**
 * code-8-7
 * */
void towerOfHanoi(int n, int x, int y, int z) // x->y by z
{
    if(n>0)
    {
        towerOfHanoi(n-1, x, z, y); // x->z by y
        cout << n << " move from " << x <<" to " << y << endl;
        towerOfHanoi(n-1, z, y, x);
    }
}

/**
 * code-8-8
 * 用数字表示碟子
 * */
//tower[1:3] 表示三个塔
arrayStack<int> tower[4];

void moveAndShow(int, int, int, int);
void showState(arrayStack<int>[], int);

void towerOfHanoi(int n)
{
    for(int d=n; d>0; d--) tower[1].push(d); //初始化，把碟子d加到塔1

}

void moveAndShow(int n, int x, int y, int z)
{
    if(n>0)
    {
        moveAndShow(n-1, x, z, y);
        int d = tower[x].top();
        tower[x].pop();
        tower[y].push(d);
        cout << "===========" << endl;
        showState(tower, 3);
        moveAndShow(n-1, z, y, x);
    }
}

void showState(arrayStack<int> stack[], int n)
{
    for(int i=1; i<=n; ++i)
    {
        //stack[i].output();
        arrayStack<int>& s = stack[i]; //这里必须加&引用，否则报错
        s.output();
        cout << endl;
    }
}

void hanoi_test()
{
    towerOfHanoi(3);
    moveAndShow(3, 1, 2, 3);
}

