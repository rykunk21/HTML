/*
Write a function called SortByUpper, that takes a vector of strings and 
changes that vector to be sorted according to only the uppercase letters 
in each string. No other characters should be involved in determining the 
order of the vector.

For instance "zCAxT" < "aDyOG", because "CAT" < "DOG".

Like with the last assignment, you must use iterators and generic algorithms 
to solve this problem, no loops.
*/
#include <cassert>
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::sort;
using std::copy_if;
#include <iterator>
using std::back_inserter;
#include <iostream>

string only_upper(string word){
    string out;
    copy_if(word.begin(), word.end(), back_inserter(out), [](const char &arg){
        return isupper(arg);
    });
    return out;
}


void SortByUpper(vector<string> &v1){
    sort(v1.begin(), v1.end(), [](string &arg1, string &arg2){
        return only_upper(arg1) < only_upper(arg2);
    });
}


/*
void SortByUpper(vector<string> &v1){
    vector<string> out;
    transform(v1.begin(), v1.end(), back_inserter(out), [](string &word){
        string out;
        copy_if(word.begin(), word.end(), back_inserter(out), [](const char 
                                                                 &letter){
            return isupper(letter);
        });
        return out;
    });
    sort(out.begin(), out.end());

    v1 = out;
}
*/

    



void testing(){

    vector<string> input {"DOG", "CAT", "FERRET"};
    SortByUpper(input);
    vector<string> expected { "CAT", "DOG", "FERRET" };

    assert(input == expected);

    input = { "zzCAT", "D123OG", "F  ERRET", "aF  ERRET", 
                           "D456OG", "D123OG" };
    SortByUpper(input);
    expected = { "zzCAT", "D123OG", "D456OG", "D123OG", 
                 "F  ERRET", "aF  ERRET" };
    assert(input == expected);


}

int main(){
    string dog = "DOG";
    string cat = "CAT";
    std::cout << (cat < dog) << '\n';


    testing();
} // mainclear