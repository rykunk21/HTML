/*
Now you need to modify your previous coding problem's solution, so that it 
logs each time one of the "Rule of 3" functions is called.
*/

#include "counter.h"

ostream& operator<<(ostream& out, Counter &count){
    count.log("<<");
    out << "Counter(" << count.initial_int_ << ")@" << count.value_;
    return out;
}

Counter operator+(const Counter& c1, const Counter& c2){
    Counter out(0);
    out.initial_int_ = c1.initial_int_ + c2.initial_int_;
    out.value_ = c1.value_ + c2.value_;
    out.log("+");
    return out;
}

Counter& Counter::operator=(const Counter& c){
    value_ = c.value_;
    initial_int_ = c.initial_int_;
    log_ = c.log_;
    this->log("=");
    return *this;

}

Counter::Counter(){
    this->log("default");
}

Counter::Counter(const int& num){
    initial_int_ = num;
    value_ = num;
    this->log("Constructor");
}

Counter::Counter(const Counter& c){
    value_ = c.value_;
    initial_int_ = c.initial_int_;
    log_ = c.log_;
    this->log("copy");
}


int Counter::value() {
    this->log("value");
    return value_--;
}

void Counter::log(const string& operation){
    ostringstream oss;

    if (operation == "Constructor"){
         oss << "Constructor called with a " << this->initial_int_;
    } else if (operation == "value"){
        oss << "value called. Returned a " << this->value_;
    } else if (operation == "<<"){
        oss << "<< called.";
    } else if (operation == "="){
        oss << "= called.";
    } else if (operation == "default"){
        oss << "Default Constructor called.";
    } else if (operation == "+"){
        oss << "+ called.";
    } else if (operation == "copy"){
        oss << "Copy Constructor called.";
    }

    this->log_.push_back(oss.str());
}


int main(){
   
    Counter c(5);
    Counter d(c);
    Counter e;
    e = d;
    std::vector<std::string> expected {
    "Constructor called with a 5",
    "Copy Constructor called.",
    "= called."
    
    };

    for (string elem: e.log_){
        std::cout << elem << std::endl;
    }

    ASSERT_EQ(e.log_, expected);
}