/**
 * 重点: 使用递归生成全排列
 * 知识点:
 *  copy函数
 *  osstream_iterator<T>(cout, "")
 *  swap函数
 * */
#include <iostream>

using namespace std;

//使用递归函数生成排列
template <class T>
void permutation(T list[], int k, int m) {
    if(k==m) {
        copy(list, list+m+1, ostream_iterator<T>(cout, "")); //WK: 将数组拷贝到输出流
        cout << endl;
    } else {
        for(int i=k; i<=m; ++i) {
            swap(list[k], list[i]); //交换
            permutation(list, k+1, m);
            swap(list[k], list[i]); //交换
        }
    }
}

void test() {
    char * cs = new char[3]{'1','2','3'};
    permutation(cs, 0, 2);
    delete [] cs;
    cs = NULL;
}
