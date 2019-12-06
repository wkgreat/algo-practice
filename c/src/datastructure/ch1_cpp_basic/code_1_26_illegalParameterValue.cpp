#ifndef ALGO_PACTICE_ILLEGALPARAMETERVALUE_CPP
#define ALGO_PACTICE_ILLEGALPARAMETERVALUE_CPP

#include <iostream>
#include <string>
using namespace std;

class illegalParameterValue {
public:
    illegalParameterValue():
        message("Illegal parameter value"){}
    illegalParameterValue(char * theMessage) {
        message = theMessage;
    }
    void outputMessage() { cout << message << endl;}

private:
    string message;

};

class illegalIndex
{
public:
    illegalIndex():message("Illegal Index Value"){}
    illegalIndex(char * theMessage) {
        message = theMessage;
    }
    void outputMessage() { cout << message << endl;}

private:
    string message;
};

#endif

