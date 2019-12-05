#include <algorithm>
#include "../ch1_cpp_basic/code_1_37_indexOfMax.cpp"

using namespace std;

////计数排序

/**
 * 一个元素在一个序列中的名次 是所有比它小的元素个数加上在它左边出现的与它相同的元素个数
 * 如 数组 a=[4,3,9,3,7] 的名次为 r=[2,0,4,1,3]
 * */
template <class T>
void ranking(T a[], int n, int r[]) {
    for(int i=0; i<n; i++) {
        r[i] = 0;
    }
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if (a[j]<=a[i]) r[i]++;
            else r[j]++;
        }
    }
}
/**
 * 计数排序
 * code 2-6 使用附加数组进行计数排序
 * 借助额外数组u
 * */
template <class T>
void rearrange(T a[], int n, int r[]) {
    T *u = new T[n];
    for(int i=0; i<n; i++) {
        u[r[i]] = a[i];
    }
    for(int i=0; i<n; i++) {
        a[i] = u[i];
    }
    delete [] u;
    u = NULL;
}

/**
 * 计数排序
 * code 2-6 使用附加数组进行计数排序
 * 原地重排
 * */
template <class T>
void rearrange2(T a[], int n, int r[]) {
    for(int i=0; i<n; ++i) {
        while(r[i] != i) {
            int t = r[i];
            swap(a[i], a[t]);
            swap(r[i], r[t]);
        }
    }
}

////选择排序
template <class T>
void selectionSort(T a[], int n) {
    for(int size = n; size > 1; size--) {
        int j = indexOfMax(a, size);
        swap(a[j], a[size-1]);
    }
}
/**
 * 选择排序，可以及时终止
 * */
template <class T>
void selectionSort2(T a[], int n) {
    bool sorted = false;
    for(int size = n; !sorted && (size>1); size--) {
        int indexOfMax = 0;
        sorted = true;
        for(int i=1; i<size; i++)
            if(a[indexOfMax] <= a[i]) indexOfMax = i;
            else sorted = false;
        swap(a[indexOfMax], a[size-1]);
    }
}

//// 冒泡排序
//一次冒泡过程
template <class T>
void bubble(T a[], int n) {
    for(int i=0; i<n-1; i++) {
        if(a[i] > a[i+1])
            swap(a[i], a[i+1]);
    }
}
//冒泡排序
template <class T>
void bubbleSort(T a[], int n) {
    for(int i=n; i>1; i--) {
        bubble(a, i);
    }
}

////冒泡排序 及时终止
template <class T>
bool bubble2(T a[], int n) {
    bool swapped = false;
    for (int i=0; i<n-1; i++) {
        if(a[i]>a[i+1]) {
            swap(a[i],a[i+1]);
            swapped = true;
        }
    }
    return swapped;
}
template <class T>
void bubbleSort2(T a[], int n) {
    for(int i=n; i>1 && bubble(a, i); i--);
}

////插入排序
//插入操作
template <class T>
void insert(T a[], int n, const T& x) {
    int i;
    for(i=n-1; i>=0 && a[i] > x; i--)
        a[i+1] = a[i];
    a[i+1] = x;
}
template <class T>
void insertSort(T a[], int n) {
    for(int i=1; i<n; i++) {
        T t = a[i];
        insert(a, i, t);
    }
}

////另外一种插入排序
template <class T>
void insertSort2(T a[], int n)
{ //对数组a[0:n-1] 实施插入排序
    for(int i=1; i<n; i++)
    { //把a[i]插入a[0:i-1]
        T t = a[i];
        int j;
        for(j=i-1; j>=0 && t < a[j]; j--)
            a[j+1] = a[j];
        a[j+1] = t;
    }
}

void example_2_5_test() {
    int a[5] = {4,3,9,3,7};
    int r[5] = {0,0,0,0,0};
    ranking(a,5, r);
    rearrange2(a, 5 , r);
    copy(r, r+5, std::ostream_iterator<int>(cout, ","));
    cout << endl;
    copy(a, a+5, std::ostream_iterator<int>(cout, ","));
    cout << endl;

    cout << "===select sort===" << endl;
    int b[5] = {4,3,9,3,7};
    selectionSort2(b, 5);
    copy(b, b+5, std::ostream_iterator<int>(cout, ","));
    cout << endl;

    cout << "===bubble sort===" << endl;
    int c[5] = {4,3,9,3,7};
    bubbleSort(c, 5);
    copy(c, c+5, std::ostream_iterator<int>(cout, ","));
    cout << endl;



}
