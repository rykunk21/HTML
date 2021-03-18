/*
Write a program (not a function) that reads from a file named 
"data.csv". This file consists of a list of countries and gold 
medals they have won in various Olympic events. Write to standard out, 
the top 5 countries with the most gold medals. You can assume there will 
be no ties.

Example data file: data.csv

For the above data, this is the expected output:

1: United States with 1022 gold medals
2: Soviet Union with 440 gold medals
3: Germany with 275 gold medals
4: Great Britain with 263 gold medals
5: China with 227 gold medals
*/


#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <iostream>
using std::cout; using std::noskipws;
#include <utility>
using std::pair;
#include <sstream>
using std::istringstream;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
using std::unique;


int main(){

    ifstream data("data.csv"); //todo determine how to gather file stream csv

    assert(data.is_open());

    string country;
    string hold;
    int val;
    vector<pair<int, string>> v1;

    while(!data.eof()){
        /*
        assiging first and second values maybe can be done by the
        seperation of a comma. then v1.push_back(make_pair(arg1, arg2))
        */
        
        data >> noskipws;

        getline(data, country, ',');
        getline(data, hold);
        // cout << country << std::endl;
        if (data.fail()){
            break;
        }
        // assert(data.good());

        istringstream iss(hold);
        iss >> val;
        v1.push_back(make_pair(val, country));
        }

    data.close();

    sort(v1.begin(), v1.end(), [](const pair<int, string> &arg,
                                  const pair<int, string> &arg2){
        return arg2.first < arg.first;
    });

    for(auto i = 0; i < 5; i++){
        pair<int, string> elem = v1.at(i);
        cout << i+1 << ": " << elem.second << " with " << elem.first << " gold medals\n";
    }


    return 0;
}