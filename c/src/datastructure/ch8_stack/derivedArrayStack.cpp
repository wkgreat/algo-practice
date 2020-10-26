//
// Created by wkgreat on 2019/12/24.
//

#include "./derivedArrayStack.h"

void derivedArrayStack_test()
{
    derivedArrayStack<int> stack(10);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    while(!stack.empty()) {
        cout << stack.top() << endl;
        stack.pop();
    }
}

