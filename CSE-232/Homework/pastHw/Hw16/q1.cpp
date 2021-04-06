/*
I've encountered a corrupted database that has a series of important numbers, 
but instead of being separated by a space, the spaces have been randomly 
changed into alphabetic characters. Write a function (named "get_numbers") 
that can take a string like "18y5638b-78" and return a vector of ints 
{18, 5638, -78}.

*/

#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::transform;
#include <sstream>
using std::istringstream;

vector<int> get_numbers(string s1){
    
    vector<int> out;
    transform(s1.begin(), s1.end(), s1.begin(), [](char &arg){
        if (isalpha(arg)){
            return ' ';
        } else {
            return arg;
        }
    });

    istringstream iss(s1);
    int hold;
    while (iss >> hold){
        out.push_back(hold);
    }
    
    return out;
}


int main(){
    vector<int> v2 = get_numbers("1348g138f138g672h");


} // main