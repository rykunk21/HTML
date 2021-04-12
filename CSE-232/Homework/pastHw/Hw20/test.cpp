#include <map>
using std::map;
#include <utility>
using std::pair;
#include <iostream>
using std::cout;


int main(){
    map<int, char> m;

    for (int i=0; i<20; i++){
        pair<int, char> add(i, 'w');
        m.insert(add);
    }

    m[2] = 'g';
    m[4] = 'h';

    for (auto elem: m){
        cout << elem.first << ' ' << elem.second << '\n';
    }

}