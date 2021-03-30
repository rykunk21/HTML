/*
Write a struct named "SafePtrToDouble" that is used to provide a (slightly) 
safer way to work with pointers (you'll learn better solutions in CSE 335). 
One major problem with pointers is that they can be dereferenced even when 
they are nullptr (meaning they have an invalid address to dereference). A 
nullptr value for a pointer is used to indicate that the pointer isn't 
pointing at a valid memory location. But it is up to the programmer to 
confirm that a pointer is not nullptr before dereferencing it. But programmers 
make mistakes!

This struct should accept as a converting constructor a pointer to a double. 
This struct must define two methods that both have no parameters:

"Dereference": this method should act like a dereference of the pointer the 
struct was created with. However, if the pointer is nullptr then a 
std::logic_error should be thrown
"Value": this method should return the value of the pointer.
Your code should be in two files: "SafePtrToDouble.cpp" and "SafePtrToDouble.h". 
Also note, a knowledge of pointers and references will be needed to solve this 
problem.
*/
#include <stdexcept>
using std::logic_error;
#include <cassert>
#include "q1.h"


SafePtrToDouble::SafePtrToDouble(double *d){
    self = d;
}


double& SafePtrToDouble::Dereference(){

    if (self == nullptr){
        throw(logic_error("Value is null"));
    } else {
        double& out = *self;
        return out;
    }
}

double* SafePtrToDouble::Value(){
    return self;
}


int main(){

    double d = 6.7;
    SafePtrToDouble s(&d);
    double lcomp = s.Dereference();
    
    assert(lcomp == 6.7);
    assert(s.Value() == &d);
    d = 7.8;
    assert(s.Dereference() == 7.8);
    s.Dereference() = 9.0;
    cout << s.Dereference() << std::endl;
    assert(s.Dereference() == 9.0);
    assert(d == 9.0);
    SafePtrToDouble s2(nullptr);
    assert(s2.Value() == nullptr);
    // ASSERT_THROW(s2.Dereference(), std::logic_error);

}