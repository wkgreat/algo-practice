//
// Created by wkgreat on 2019/12/8.
//

#include "chain.h"

using namespace std;

void chain_test() {
    chain<int> *a = new chain<int>(10);
    for(int i=0; i<10; ++i) a->insert(0,i);
    cout << "Output: ";
    a->output(cout);
    cout << endl;

    for(chain<int>::iterator iter = a->begin(); iter!=a->end(); iter++) {
        cout << "Iter: " << *iter << endl;
    }

}