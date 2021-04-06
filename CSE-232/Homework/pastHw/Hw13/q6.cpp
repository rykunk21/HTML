/*
Write a function, named 'all_to_int', that takes a vector of 
strings, and converts each to an int and returns the resulting vector. 
If a string can't be turned to a long, use a 0 in its place.

Note: You cannot use loops in your code (no 'for' or 'while' statements).



}

*/
#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::transform;
#include <sstream>
using std::istringstream;
#include <stdexcept>


vector<int> all_to_int(const vector<string> & strings){
    vector<int> result{};

    transform(strings.begin(), strings.end(), back_inserter(result), [](string arg){
        int out;
        
        try{
            out = std::stoi(arg);
        } catch (std::invalid_argument){
            out = 0;
        }
        return out;
    });

    return result;    
}

int main(){

    vector<string> convert = {"1", "2", "3", "this is not an int", "4", "5"};
    vector<int> expected = {1,2,3, 0, 4,5};

    vector<int> result = all_to_int(convert);

    for(auto ptr = result.begin(); ptr != result.end(); ++ptr){
        std::cout << *ptr << '\n';
    }
    assert(result == expected);

} // main