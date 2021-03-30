#ifndef SAFEPTRTODOUBLE
#define SAFEPTRTODOUBLE

#include <iostream>
using std::cout; using std::cin;
#include <stdexcept>
using std::logic_error;

struct SafePtrToDouble{
    double* self;
    
    SafePtrToDouble()=default;
    SafePtrToDouble(double* d);

    double& Dereference();
    double* Value();
};


#endif