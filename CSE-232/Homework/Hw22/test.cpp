#include <iostream>
#include <string>
using std::string;


int main(){

    std::string* x = new string();

    delete x;
    delete x;

    return 0;
}