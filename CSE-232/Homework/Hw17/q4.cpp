/*
I'm interested in knowing if there are two adjacent strings in a list that are 
very similar to each other. For instance, "Zach" and "Zack" are only one 
character apart.

Write a function, named "CloseEnough" that takes a const reference to a 
vector of strings and an int. The vector is a list of strings (each of the 
same length). The int represents how many characters can be different between 
any two strings next to each other. This function should return the index (an 
int) of the string that is within the second arguments distance to the next 
string in the vector. If no index fulfills this criteria, it should return -1.

Example:

const std::vector<std::string> more_words {
  "this is a sentence.",
  "this is also words ",
  "another line in one",
  "stuff words in open",
  "stuff words in OPEN",
  "whitespace\n\tagain  ",
};

ASSERT_EQ(CloseEnough(more_words, 5), 3); 

Index 3: "stuff words in open" 
is only distance 4 fron the next string
Index 4: "stuff words in OPEN", 
so the function returns 3


ASSERT_EQ(CloseEnough(more_words, 0), -1); 
// No index is within 0 distance of the next string.
 

You should be using the STL algorithms to achieve this, credit is only 
possible if your solution doesn't have any looping constructs (no "while" or 
"for" keywords anywhere in the solution). You also can't use the "for_each" or 
"for_each_n" algorithms. If a URL you are citing has such a word, add an 
interupting space like: https://www.programiz.com/cpp-programming/fo r-loop
*/
#include <cassert>
#include <iostream>
using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::set_difference;
#include <iterator>
using std::back_inserter;

int CloseEnough(const vector<string> v1, const int difference){
    vector<char> comp;
    vector<string> dead;
    adjacent_difference(v1.begin(), v1.end(), back_inserter(dead),
      [difference](string arg1, string arg2){
      sort(arg1.begin(), arg1.end());
      sort(arg2.begin(), arg2.end());
      set_difference(arg1.begin(), arg1.end(), arg2.begin(), arg2.end(),
    });
    

} // CloseEnough



int test(){
    #include <fstream>
    #include <regex>
    #include <sstream>
    const std::vector<std::string> words {
    "bog",
    "cat",
    "dog",
    "bot",
    "bat",
    "vat",
    "vat",
    "jot"
    };
    assert(CloseEnough(words, 1) == 3); // bot bat
    assert(CloseEnough(words, 2) == 2); // dog bot
    assert(CloseEnough(words, 3) == 0); // bog cat
    assert(CloseEnough(words, 0) == 5); // vat vat
    const std::vector<std::string> more_words {
    "this is a sentence.",
    "this is also words ",
    "another line in one",
    "stuff words in open",
    "stuff words in OPEN",
    "whitespace\n\tagain  ",
    };

    /*
    int diffs = 3;
    assert(diffs == CloseEnough(more_words, 5)); 
    */

    /*
    Index 3: "stuff words in open" 
    is only distance 4 fron the next string
    Index 4: "stuff words in OPEN", 
    so the fuction returns 3
    */

    assert(CloseEnough(more_words, 0) == -1); 
    // No index is within 0 distance of the next string.
    // Check for loops

    /*
    std::ifstream code{"code.cpp"};
    std::stringstream contents;
    contents << code.rdbuf();
    std::string text = contents.str();
    std::regex r{R"~(\b(for|while|goto|for_each|for_each_n)\b)~"};
    ASSERT_FALSE(std::regex_search(text,r));
    */
    }
