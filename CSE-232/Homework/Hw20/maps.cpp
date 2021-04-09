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
#include <utility>
using std::pair;
#include "mimir_testing.h"

set<string> only_once(const map<string, int>& m){
    set<string> out;
    for (auto elem : m){
        if (elem.second == 1){
            out.insert(elem.first);
        }
    }
    return out;
}

multimap<int, string> count_to_words(const map<string, int>& m){
    multimap<int, string> out;
    for (auto elem: m){
        pair<int, string> add (elem.second, elem.first);
        out.insert(add);
    }
    return out;
}

/*
map<int, set<string>> count_to_set(const map<string, int>& m){
    map<int, set<string>> out;
    multimap<int, string> words = count_to_words(m);
    for (auto elem: m){
        set<string> add;
        multimap<int, string>::iterator it = words.find(elem.second);
        while((*it).first == elem.second){
            add.insert((*it).second);
            it++;
        }
        pair<int, set<string>> out_elem (elem.second, add);
        out.insert(out_elem);
    }
    return out;
}
*/

map<int, set<string>> count_to_set(const map<string, int>& m){
    map <int, set<string>> out;
    for (auto elem: m){
        out[elem.second].insert(elem.first);
    }
    
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
    t1();
    t2();
    t3();
} // main