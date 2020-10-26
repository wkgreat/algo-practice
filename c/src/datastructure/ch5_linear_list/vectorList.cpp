//
// Created by wkgreat on 2019/12/6.
//

#include <sstream>
#include "vectorList.h"
#include "../ch1_cpp_basic/code_1_26_exception.h"

void vectorList_test() {

    linearList<int> * x = new vectorList<int>(10);
    x->insert(0,1);
    x->insert(0,2);
    x->insert(0,3);
    x->insert(0,4);
    x->output(std::cout);
    cout << endl;
    cout << *x << endl;
    cout << "get(1): " << x->get(1) << endl;

    try{
        x->insert(-1,0);
    }
    catch(illegalIndex e) {
        e.outputMessage();
    }

    cout << endl << "==Iterator===" << endl;

    auto y = dynamic_cast<vectorList<int>*>(x);
    reverse(y->begin(), y->end());
    y->output(std::cout);
    cout << endl;
    y->begin();
}