// pair q2
/*
Write a class called Counter, that has a constructor that takes an int. It 
has a member function called "value" (no parameters), which returns an int 
that initially is the int it was constructed with. However, each time this 
function is invoked, the value is decremented. Be sure the constructor and the 
getter method are the only public members of the class.

The files counter.cpp and counter.h are where you should place your 
implementation and header content.

*/


#pragma once

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <sstream>
using std::ostringstream;
#include <iostream>
using std::ostream;

class Counter{
    private:
        int initial_int_=0;
        int value_=0;
    public:
        vector<string> log_={};

        Counter(const int& num);
        int value();
        void log(const string& operation, const int& value);
        friend ostream& operator<<(ostream&, const Counter&);
};

ostream& operator<<(ostream&, const Counter&);