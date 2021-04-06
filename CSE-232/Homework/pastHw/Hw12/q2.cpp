/*
Write a function, named sort_by_course_number, that takes a reference 
to a vector of string (like {"CSE 232", "ECE 100", "CSE 450", "CSE 232"}) 
and returns nothing. The function should reorder the vector so that the 
courses are sorted by number in ascending order. You can assume that the 
department code is separated from the number by a space and that all course 
numbers are 3 characters long.

You should be using the STL algorithms to achieve this, full credit is 
only possible if your solution doesn't have any looping constructs 
(no "while" or "for" keywords anywhere in the solution). If a URL you are 
citing has such a word, add an interupting space like: 
https://www.programiz.com/cpp-programming/fo r-loop

*/
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

void sort_by_course_number(vector<string> &vec){
    sort(vec.begin(), vec.end(),[](const string &arg1, const string &arg2){

        return arg1.substr(arg1.length()-3) < arg2.substr(arg2.length()-3);
    });
}
