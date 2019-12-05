/**
 * c++ STL 中的 accumulate
 * */
#include <istream>
#include <numeric> //accumulate is defined in numeric

using namespace std;

template <class T>
T sum(T a[], int n) {
    T theSum = 0;
    return accumulate(a, a+n, theSum);
}

void test() {
    int *p = new int[5]{1,2,3,4,5};
    int s = sum(p,5);
    cout << "sum is: " << s;
    delete [] p;
    p = NULL;
}

