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


void SortByUpper(vector<string>v1){

}


void testing(){
    #include <vector>
    #include <string>
    using std::vector;
    using std::string;
    vector<string> input {"DOG", "CAT", "FERRET"};
    SortByUpper(input);
    vector<string> expected { "CAT", "DOG", "FERRET" };
    assert(input == expected);

    vector<string> input { "zzCAT", "D123OG", "F  ERRET", "aF  ERRET", 
                           "D456OG", "D123OG" };
    SortByUpper(input);
    vector<string> expected { "zzCAT", "D123OG", "D456OG", "D123OG", 
                              "F  ERRET", "aF  ERRET" };
    assert(input == expected);


}

int main(){

} // mainclear