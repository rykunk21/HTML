#include "q4.h"
#include "mimir_testing.h"
using std::literals::operator""s;

Price::Price(){
    value_ = 0.00;
}

Price::Price(double in){
    value_ = in;
}

string Price::val_to_str() const {
    ostringstream oss;
    oss << fixed << setprecision(2) << '$' << value_;
    return oss.str();
}

Price Price::operator+(const Price& p2){
    Price out(value_ + p2.value_);
    return out;
}

Price Price::operator-(const Price& p2){
    Price out(value_ - p2.value_);
    return out;
}

Price& Price::operator=(const Price& p2){
    value_ = p2.value_;
    return *this;
}

Price& Price::operator+=(const Price& p2){
    value_ += p2.value_;
    return *this;
}

Price& Price::operator-=(const Price& p2){
    value_ -= p2.value_;
    return *this;
}

ostream& operator<<(ostream& oss, const Price& p){
    if (p.val_to_str() == "$0"){
        oss << "$0.00";
        return oss;
    } else {
        oss << std::fixed << setprecision(2) << p.val_to_str();
        return oss;
    }
}

istream& operator>>(istream& iss, Price& p){
    
    iss.ignore(2, '$');
    double value;
    iss >> value;
    p.value_ = value;
    return iss;
    
}

void test(){
        
    Price p;
    std::istringstream iss("$12.45");
    iss >> p;
    Price p2 = p + p;
    std::ostringstream oss;
    oss << p << " " << p2;
    cout << oss.str();
    ASSERT_EQ(oss.str(), "$12.45 $24.90"s);
}

int main(){
    test();
}