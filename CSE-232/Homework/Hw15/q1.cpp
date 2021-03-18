/*
Write a function (named "Lookup") that takes two const references to vectors.
The first vector is a vector of strings. This vector is a list of words. The 
second parameter is a list of ints. Where each int denotes an index in the 
first vector. The function should return a string formed by concatenated the 
words (separated by a space) of the first vector in the order denoted by the 
second vector.

If that doesn't make sense, I recommend looking at the first test case.

If an index isn't valid (for instance refers to a position outside of the 
other vector, raise an out_of_range exception.
*/

#include <cassert>
#include <iostream>
using std::cin; using std::cout;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
#include <stdexcept>
#include <algorithm>
using std::generate;
using std::copy_if;
#include <iterator>
using std::back_inserter;

string Lookup(vector<string> words, vector<int> indicies){
    string out;

    generate(indicies.begin(), indicies.end(), [&words, &out](){
        out += words.at(arg);
        return arg;
    });

    return out;
    cout << "Output: ";
    cout << out << '\n';

} // fn

void test1(){
    const std::vector<std::string> words {"zero", "one", "two"};
    const std::vector<int> indices {2, 1, 1, 2, 0}; 
    std::string result = Lookup(words, indices);
    std::cout << result << std::endl;
    const std::string expected = "two one one two zero ";
    assert(expected == result);
}

void test2(){
    const std::vector<std::string> words {"zero", "one", "two"};
    const std::vector<int> indices {2, 1, 1, 2, 0}; 
    std::string result = Lookup(words, indices);
    std::cout << result << std::endl;
    const std::string expected = "two one one two zero ";
    assert(expected == result);
    const std::vector<int> to_low_indices {2, 1, 1, -2, 0};
    // ASSERT_THROW(Lookup(words, to_low_indices), std::out_of_range);
    const std::vector<int> to_high_indices {2, 1, 1, 20, 0};
    // ASSERT_THROW(Lookup(words, to_high_indices), std::out_of_range);
}


int main(){
    
    test1();
    return 0;
}