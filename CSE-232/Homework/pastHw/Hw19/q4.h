/*
You need to write a class named Price that represents a dollar and cents 
value. It should support a default constructor and a converting constructor 
for a double. It should support the <<, +, +=, -, -=, and >> operators. 
Please see the test cases for the specific behavior for each operator.

Your code should be placed in code.cpp and code.h

*/

#include <math.h>
#include <string>
using std::string;
#include <sstream>
using std::ostringstream; using std::istream;
#include <iostream>
using std::cout; using std::ostream;
#include <iomanip>
using std::setprecision; using std::fixed;


class Price{

    double value_;
    string val_to_str() const;

    public:
        // constructors
        Price();
        Price(double in);

        // methods
        Price operator+(const Price& p2);
        Price operator-(const Price& p2);
        Price& operator=(const Price& p2);
        Price& operator+=(const Price& p2);
        Price& operator-=(const Price& p2);

        // friend functions
        friend ostream& operator<<(ostream& oss, const Price& p);
        friend istream& operator>>(istream& iss, Price& p);
};
ostream& operator<<(ostream& oss, const Price& p);
istream& operator>>(istream& iss, Price& p);