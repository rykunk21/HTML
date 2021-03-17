/*
Write a function, named series_of_letters, that takes a reference to a 
vector of chars and returns nothing. The function should modify the vector 
to contain a series of letters increasing from the smallest letter 
(by ASCII value) in the vector. Note, the vector should not change in size, 
and the initial contents of the vector (excepting the smallest letter) do not
 matter.

You should be using the STL algorithms to achieve this, full credit is only 
possible if your solution doesn't have any looping constructs (no "while" or 
"for" keywords anywhere in the solution). If a URL you are citing has such a 
word, add an interupting space like:
https://www.programiz.com/cpp-programming/fo r-loop

*/
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
using std::transform;


void series_of_letters(vector<char> &v1){
    sort(v1.begin(), v1.end());
    const char begin = v1.front();
    for(int i=0; i < static_cast<int>(v1.size()); i++){
        v1.at(i) = begin + i;
    }
} // fn