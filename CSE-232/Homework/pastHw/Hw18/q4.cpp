/*
For this code problem, start with your working solution from the previous 
code problem. But here you need to add some new funtionality.

First off, each counter object should have a public data member called 
"log_" it is a vector of strings. It starts empty, but each method call 
on the object should add a string to the log_. See the test cases for exact 
formating.

Be sure the two existing functions (constructor and value) log themselves.

Then implement the << operator so that a Constructor can write itself to a 
stream. It shoudl write "Counter(9)@8" if the counter was initialized with 
the value 9 and the next value to be returned by the "value" member function 
is an 8.

Next implement the + operator when returns a new counter that has an initial 
value and current values that is the sum of the two counters' data members.

*/
/*
Write a class called Counter, that has a constructor that takes an int. It 
has a member function called "value" (no parameters), which returns an int 
that initially is the int it was constructed with. However, each time this 
function is invoked, the value is decremented. Be sure the constructor and the 
getter method are the only public members of the class.

The files counter.cpp and counter.h are where you should place your 
implementation and header content.

*/

#include <iostream>
#include <string>
#include <cassert>
#include "counter.h"
using std::literals::operator""s;
#include "mimir_testing.h"

ostream& operator<<(ostream& out, Counter &count){
    count.log("<<", 0);
    out << "Counter(" << count.initial_int_ << ")@" << count.value_;
    return out;
}

Counter operator+(const Counter& c1, const Counter& c2){
    Counter out(0);
    out.initial_int_ = c1.initial_int_ + c2.initial_int_;
    out.value_ = c1.value_ + c2.value_;
    return out;
}

Counter::Counter(const int& num){
    this->log("Constructor", num);
    initial_int_ = num;
    value_ = num;
};

int Counter::value() {
    this->log("value");

    return value_--;
};


void Counter::log(const string& operation, const int& value){
    ostringstream oss;
    if (operation == "Constructor"){
        oss << "Constructor called with a " << value;
    } else if (operation == "value"){
        oss << "value called. Returned a " << value;
    } else {
        oss << "<< called.";
    }
    
    this->log_.push_back(oss.str());
}


int main(){
        
    Counter c(9);
    std::vector<std::string> expected = {"Constructor called with a 9"};
    ASSERT_EQ(expected, c.log_);
    ASSERT_EQ(c.value(), 9);
    std::vector<std::string> expected2 = {
    "Constructor called with a 9",
    "value called. Returned a 9"
    };
    ASSERT_EQ(expected2, c.log_);
    ASSERT_EQ(c.value(), 8);
    ASSERT_EQ(c.value(), 7);
    ASSERT_EQ("value called. Returned a 7"s, c.log_.back());

    }
