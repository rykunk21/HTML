/*
Write a function, named only_numbers, that takes a const reference to a 
string and returns a string composed only of the characters from the original
string that are digits.

You should be using the STL algorithms to achieve this, full credit is only 
possible if your solution doesn't have any looping constructs (no "while" or 
"for" keywords anywhere in the solution). If a URL you are citing has such a 
word, add an interupting space like: 
https://www.programiz.com/cpp-programming/fo r-loop
*/

#include <string>
using std::string;
#include <algorithm>
using std::copy_if;
#include<iterator>
using std::back_inserter;

string only_numbers(const string &s1){
    string out = "";

    copy_if(s1.begin(), s1.end(), back_inserter(out),[](const char &c1){
        string digit = "1234567890";
        return digit.find(c1) != string::npos;
    });

    return out;

}// fn