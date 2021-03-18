
#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <vector>
using std::vector;
#include <iterator>
using std::back_inserter;
#include <algorithm>
using std::transform;
using std::generate;
#include <string>
using std::stoi;


void fib(int n){
    
    vector<int> iterator_size(n);
    vector<int> v1;
    generate(iterator_size.begin(), iterator_size.end(), [&v1](){
            if (v1.size() == 0 || v1.size() == 1){
                v1.push_back(1);
            } else {
                v1.push_back(v1.back()+ (v1.at(v1.size()-2)));
            }
            return 0;
        });
            
    for (int elem: v1){
        cout << elem << '\n';
    }
}


int main(){

    int n = 8;
    vector<int> v1(n, -1);

    /*
    transform(v1.begin(), v1.end(), v1.begin(), [&v1](int &arg){
        if (v1.front() == 0 || (v1.size()-(v1.size()-2)) == 0){
                return 1;
            } else if (arg == -1) {
                return v1.back() + (v1.at(v1.size()-2));
            }
            return 0;
        });

    for (int elem: v1){
        cout << elem << '\n';
    }
    */

   fib(8);

}