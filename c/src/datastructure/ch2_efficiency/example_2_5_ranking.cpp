/**
 * 一个元素在一个序列中的名次 是所有比它小的元素个数加上在它左边出现的与它相同的元素个数
 * 如 数组 a=[4,3,9,3,7] 的名次为 r=[2,0,4,1,3]
 * */
#include <algorithm>

using namespace std;

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

void test() {
    int a[5] = {4,3,9,3,7};
    int r[5] = {0,0,0,0,0};
    ranking(a,5, r);
    copy(r, r+5, std::ostream_iterator<int>(cout, ","));
}
