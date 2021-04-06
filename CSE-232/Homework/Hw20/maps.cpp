/*
I've made a map<string, int> that represents the number of times a word appears 
in a particular text.

I need you to transform the data in this data structure to some related data 
structure. Do not copy this map, using const references.

only_once: takes a map<string, int> and returns a set<string> of words that 
only appeared once in the text.

count_to_words: takes a map<string, int> and returns a multimap<int, string> 
of the counts to the words with that count.

count_to_set: takes a map<string, int> and returns a map<int, set<string>> 
of the counts to the set of words with that count.

*/

#include <map>
using std::map; using std::multimap;
#include <set>
using std::set;
#include <string>
using std::string;
#include "mimir_testing.h"

set<string> only_once(const map<string, int>& wcounts){
    set<string> out;

    return out;
}

multimap<int, string> count_to_words(const map<string, int>& m){
    multimap<int, string> out;

    return out;
}

map<int, set<string>> count_to_set(const map<string, int>& m){
    map<int, set<string>> out;

    return out;
}


void t1(){
    const map<string, int> word_counts = {
	{"josh", 2},
	{"smart", 1},
	{"cse", 8},
	{"ferret", 1},
	{"politics", 0},
	{"C++", 1},
    };
    set<string> expected = {"smart", "ferret", "C++"};
    set<string> result = only_once(word_counts);
    ASSERT_EQ(expected, result);
}

void t2(){
    const map<string, int> word_counts = {
	{"josh", 2},
	{"smart", 1},
	{"cse", 8},
	{"ferret", 1},
	{"politics", 0},
	{"C++", 1},
    };
    multimap<int, string> expected = {
        {0, "politics"},
        {1, "C++"},
        {1, "ferret"},
        {1, "smart"},
        {2, "josh"},
        {8, "cse"},
    };
    multimap<int, string> result = count_to_words(word_counts);
    ASSERT_EQ(expected, result);
}

void t3(){
    const map<string, int> word_counts = {
	{"josh", 2},
	{"smart", 1},
	{"cse", 8},
	{"ferret", 1},
	{"politics", 0},
	{"C++", 1},
    };
    map<int, set<string>> expected = {
        {0, {"politics"}},
        {1, {"C++", "ferret", "smart"}},
        {2, {"josh"}},
        {8, {"cse"}},
    };
    map<int, set<string>> result = count_to_set(word_counts);
    ASSERT_EQ(expected, result);
}

int main(){

} // main