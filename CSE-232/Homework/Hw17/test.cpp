#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <string>
using std::string;
#include <numeric>
using std::accumulate;

int main(){
    string s1 = "This is a string";
    string s2 = "This is a stning";

    int result = 0;

    accumulate(s1.begin(), s1.end(), result, [](int &init, const char &arg1){
        cout << init << endl;
        return init + int(arg1);
    });

    accumulate(s2.begin(), s2.end(), result, [](int &init, const char &arg1){
        cout << init << endl;
        return init + int(arg1);
    });


    
    return 0;
}