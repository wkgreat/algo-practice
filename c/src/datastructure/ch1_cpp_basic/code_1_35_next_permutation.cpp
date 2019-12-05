/**
 * C++ STL 中的 copy 和 next_permutation
 * */
#include <algorithm>

using namespace std;

template <class T>
void permutation(T list[], int m) {
    do {
        copy(list, list+m+1, ostream_iterator<T>(cout, ""));
        cout << endl;
    } while (next_permutation(list, list+m+1));
}

void test() {
    char *p = new char[5] {'a','b','c','d','e'};
    permutation(p,4);
    delete [] p;
    p = NULL;
}



