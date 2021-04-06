/*
Write a function, named "FriendsInCommon", that takes two constant 
references to a set of strings (where each string is a name of a friend). 
This function should return a set of names consisting of the names that are 
in both arguments.

 

You should be using the STL algorithms to achieve this, credit is only given 
if your solution doesn't have any looping constructs (no "while" or "for" 
keywords anywhere in the solution). If a URL you are citing has such a word, 
add an interupting space like: https://www.programiz.com/cpp-programming/fo 
r-loop
*/
#include <set>
using std::set;
#include <algorithm>
using std::set_intersection;
#include <iterator>
using std::inserter;
#include <string>
#include <regex>
#include <fstream>
#include <string>
using std::string;
using csetstr = const set<string>;

set<string> FriendsInCommon(csetstr &set1, csetstr &set2){
    set<string> out;

    /* from https://stackoverflow.com/questions/13448064/
            how-to-find-the-intersection-of-two-stdset-in-c
        
        helped me determine how to correctly provide an output iterator
        this is because sets need to utilize insert rather than back_inserter
    */

    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), 
                     inserter(out, out.begin()));

    return out;
} // fn


int main(){

const std::set<std::string> my_friends = {
  "Book",
  "River",
  "Mal",
  "Inara",
  "Kaylee",
  "Simon",
  "Jayne",
  "Wash",
  "Zoe",
};
const std::set<std::string> their_friends = {
  "Yo-Saff-Bridge",
  "Inara",
  "Mal",
  "Tracey",
};
std::set<std::string> result = FriendsInCommon(
  my_friends, their_friends);
  
std::set<std::string> expected = {
  "Inara",
  "Mal",
};
assert(expected == result);
// No loops allowed
/*
std::ifstream code{"code.cpp"};
std::regex r{R"~(\bfor\b|\bwhile\b|\bgoto\b)~"};
std::string line;
while (std::getline(code, line)) 
assert(!std::regex_search(line,r));
*/

} // main