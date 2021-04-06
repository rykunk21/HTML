/*
Write a program that reads in a series of lines 
containing whitespace delimited words.

For each line, it should prints the words of each 
line with separating commas in AP style. Meaning, no Oxford comma.

You may assume that every line has at least one word on it.
*/
#include <iostream>
using std::cin; using std::cout;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <sstream>
using std::istringstream;
#include <algorithm>
using std::replace;
using std::ostream_iterator;
using std::copy;


int main(){
    string line;
    vector<string> words;
    getline(cin, line);
    istringstream iss(line);

    string word;
    while(iss >> word){
        words.push_back(word);
    }
    
    ostream_iterator<string> out(cout, ", ");
    copy(words.begin(), words.end()-2, out);
    for(auto ptr = words.end()-2; ptr != words.end()-1; ++ptr){
        cout << *ptr;
        if (*ptr != words.end()-1){
            cout << " and ";
        }
    }

} // main