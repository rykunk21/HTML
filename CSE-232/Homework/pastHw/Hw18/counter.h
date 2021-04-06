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
#include <iostream>
#include <string>
#include <cassert>
using std::literals::operator""s;
#include "mimir_testing.h"


class Counter{
    private:
        // private data members
        int initial_int_=0;
        int value_=0;
        void log(const string& operation);

    public:
        // public data member
        vector<string> log_={};

        //constructor
        Counter();
        Counter(const int& num);
        Counter(const Counter &c);

        //member function
        int value();
        Counter &operator=(const Counter&);
        

        // destructor
        ~Counter(){};

        // friend functions
        friend ostream& operator<<(ostream&, Counter&);
        friend Counter operator+(const Counter&, const Counter&);
};

ostream& operator<<(ostream&, const Counter&);
