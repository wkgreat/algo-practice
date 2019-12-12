//
// Created by wkgreat on 2019/12/12.
//

#include "matrix.h"

using namespace std;

void matrix_test()
{
    matrix<int> m(3,3);
    int k = 1;
    for(int i=1; i<=3; i++)
        for(int j=1;j<=3; j++)
            m(i,j) = k++;

    cout << m << endl;
    cout << +m << endl;
    cout << m+m << endl;
    cout << -m << endl;
    cout << m-m << endl;
    cout << m*m << endl;

}
