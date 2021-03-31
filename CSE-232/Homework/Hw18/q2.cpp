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

ostream& operator<<(ostream& out, const Counter &count){
    count.log("<<",0);
    out << "Counter(" << count.initial_int_ << ")@" << count.value_;
    return out;
}

Counter::Counter(const int& num){
    this->log("Constructor", num);
    initial_int_ = num;
    value_ = num;
};

int Counter::value() {
    this->log("value", value_);

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
    std::ostringstream oss;
    oss << c;
    ASSERT_EQ(oss.str(), "Counter(9)@9"s);
    std::vector<std::string> expected2 = {
    "Constructor called with a 9",
    "<< called."
    };

    for (string elem: c.log_){
        std::cout << elem << std::endl;
    }

    ASSERT_EQ(expected2, c.log_);
    ASSERT_EQ(c.value(), 9);
    std::ostringstream oss2;
    oss2 << c;
    ASSERT_EQ(oss2.str(), "Counter(9)@8"s);
    std::vector<std::string> expected3 = { 
    "Constructor called with a 9", 
    "<< called.", 
    "value called. Returned a 9", "<< called." };
    ASSERT_EQ(expected3, c.log_);

}