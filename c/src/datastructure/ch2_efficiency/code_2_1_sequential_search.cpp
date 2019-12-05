/**
 * 顺序查找
 * */

#include <iostream>

using namespace std;

template <class T>
int sequentialSearch(T a[], int n, const T& x) {
    int i=0;
    for(i=0; i<n && a[i]!=x; i++);
    if(i==n) return -1;
    else return i;
}

/**
 * code 2-2 顺序查找的递归算法
 * */
template <class T>
int rSequentialSearch(T a[], int n, const T& x) {
    if(n-1<1) return -1;
    if(a[n-1] ==x ) return n-1;
    return rSequentialSearch(a, n-1, x);
}

void test() {
    int p[5] = {1,2,3,4,5};
    int x = 3;
    int r = sequentialSearch(p,5,x);
    cout << r << endl;

}

