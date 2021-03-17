/*
I'm interested in finding long words, so I'm going to pass words to your 
program via stdin. I want you to output the words ordered by length. If 
two words have the same length, output them in dictionary order. The words 
are all lowercase separated by whitespace. Make sure you remove duplicate
 words.

The output should be one word per line.
*/

#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <algorithm>
using std::unique; using std::sort; 
#include <string>
using std::string;
#include <vector>
using std::vector;


int main(){

    vector<string> v1{};
    string userin = "";
    while(cin >> userin){
        v1.push_back(userin);
    }
    
    sort(v1.begin(), v1.end(), [](string &arg1, string &arg2){
        return arg1 < arg2;
    });
    sort(v1.begin(), v1.end(), [](string &arg1, string &arg2){
        return arg1.size() < arg2.size();
    });
    std::vector<string>::iterator it;
    it = std::unique (v1.begin(), v1.end());
    v1.resize( std::distance(v1.begin(),it) );



    for(auto ptr = v1.begin(); ptr != v1.end(); ++ptr){
        cout << *ptr << '\n';
    }
}