/**
 * code 1-37
 * 寻找序列中最大元素的索引
 * */
#include <iostream>
#include "../ch1_cpp_basic/code_1_26_illegalParameterValue.cpp"

using namespace std;

template <class T>
int indexOfMax(T a[], int n) {
    if(n<=0)
        throw illegalParameterValue("n must be > 0");
    int indexOfMax = 0;
    for(int i=0; i<n; i++) {
        if(a[indexOfMax]<a[i]) {
            indexOfMax = i;
        }
    }
    return indexOfMax;
}