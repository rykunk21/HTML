/*
Write a function named "FriendsWithPets" that takes a const reference to a 
std::map of my friends names (std::string) to the number of pets they own 
(int) and returns the number of friends (int) that have at least one pet.

 

You should be using the STL algorithms to achieve this, credit is only given 
if your solution doesn't have any looping constructs (no "while" or "for" 
keywords anywhere in the solution). If a URL you are citing has such a word, 
add an interupting space like: https://www.programiz.com/cpp-programming/fo 
r-loop

*/


#include <iostream>
using std::cout;
#include <iomanip>
using std::boolalpha;
#include <fstream>
#include <regex>

#include <utility>
using std::pair;
#include <map>
using std::map;
#include <string>
using std::string;
#include <algorithm>
using std::count_if;


int FriendsWithPets(const map<string, int> &friend_names){
    
    return count_if(friend_names.begin(), friend_names.end(), 
                     [](const pair<string, int> &arg){
        return arg.second != 0;    
    });
}

int main(){
    
    const std::map<std::string, int> best_friends = {
    {"Mal", 0},
    {"Inara", 7},
    {"Book", 0},
    {"Wash", 1},
    {"River", 1},
    {"Simon", 2},
    {"Kaylee", 0},
    };
    int result = FriendsWithPets(best_friends);
    assert(result == 4);
    const std::map<std::string, int> okay_friends = {
    {"Harry", 12},
    {"Hermione", 4},
    {"Ron", 9},
    {"Luna", 0},
    {"Neville", 17},
    {"Ginny", 12},
    {"Fred", 19},
    {"George", 7},
    };
    result = FriendsWithPets(okay_friends);
    assert(result == 7);
    /*
    // No loops allowed
    std::ifstream code{"q1.cpp"};
    std::regex r{R"~(\bfor\b|\bwhile\b|\bgoto\b)~"};
    std::string line;
    while (std::getline(code, line)) 
    assert(!std::regex_search(line,r));
    */


} // main