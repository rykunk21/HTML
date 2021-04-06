#include <vector>
using std::vector;

int main(){
    vector<int> vec = {1,2,3,4,5,6,7};

    for (auto x: vec){
        x = 2;
    }

    for (auto &x: vec){
        assert(x == 2);
    }
} // main
