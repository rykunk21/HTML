/*

Write a function (named MultipleOf4) that takes and returns a string of 
space character separated ints. The string that is returned should only 
contain the ints that are multiples of 4.

You should be using the STL algorithms to achieve this, credit is only 
possible if your solution doesn't have any looping constructs 
(no "while" or "for" keywords anywhere in the solution). If a URL you are 
citing has such a word, add an interupting space like: 
https://www.programiz.com/cpp-programming/fo r-loop
*/
#include "mimir_testing.h"
#include <string>
using std::string;
#include <fstream>

string MultipleOf4(string inp){
    return inp;
}

int main(){
    std::string input {"0 -3 10 16 18 4672 2004 345 -4"};
    std::string result = MultipleOf4(input);
    ASSERT_EQ(result, "0 16 4672 2004 -4 ");
}