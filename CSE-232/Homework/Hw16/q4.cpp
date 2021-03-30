#include <map>
using std::map;
#include <utility>
using std::pair;
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main(){
    const map<int, int> my_map {
        {1,2},
        {2,3},
        {3,4}
    };

    for (auto [x, y]: my_map){
        cout << x << ' ' << y << endl;
    }

    
    return 0;
}