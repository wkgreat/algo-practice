//
// Created by wkgreat on 2019/12/6.
//
#include "arrayList.h"

using namespace std;

void arrayList_test() {

    linearList<int> * x = new arrayList<int>(10);
    x->insert(0,1);
    x->insert(0,2);
    x->insert(0,3);
    x->insert(0,4);
    x->output(std::cout);
    cout << endl;
    cout << *x << endl;

    try{
        x->insert(-1,0);
    }
    catch(illegalIndex e) {
        e.outputMessage();
    }

    cout << endl << "==Iterator===" << endl;

    auto y = dynamic_cast<arrayList<int>*>(x);
    reverse(y->begin(), y->end());
    y->output(std::cout);
    cout << endl;
    y->begin();
}