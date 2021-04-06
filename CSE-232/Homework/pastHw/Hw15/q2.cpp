/*
There's an old joke: "Why is 6 scared of 7? Because 7 8 9 (seven ate nine)." 
But since hearing that joke, I've had an irrational fear of the number 7. 
Write a templated function, called "safe_add" that adds two numbers 
(ints, floats, doubles, etc) and returns their sum. However, if either number 
(or their sum) contains the number 7, raise a runtime_error stating "can't
add because 6+1 appears in it".

*/
#include <cassert>
#include <string>
using std::string; using std::to_string;
#include <iostream>
#include <stdexcept>
#include <vector>
using std::vector;

int safe_add(int num1, int num2){
    int sum = num1 + num2;
    
    // from http://www.cplusplus.com/reference/string/to_string/
    // to_string() takes a numerical value and returns the string equivilant

    vector<string> strings_to_test = {to_string(num1), to_string(num2), 
                                      to_string(sum)};
    for (string word: strings_to_test){
        for (char character : word){
            if (character == '7'){
                throw std::runtime_error("can't add because 6+1 appears in it");
            }
        }
    }
    return sum;
}


void test1(){

    const int x = 10, y = 99;
    int result = safe_add(x, y);
    int expected = 109;
    assert(result == expected); 

    //ASSERT_THROW(safe_add(x, y), std::runtime_error);
    result = safe_add(66, 30);
    expected = 96;
    assert(result == expected); 



}


void test2(){

    const int x = 170, y = 10;
    // ASSERT_THROW(safe_add(x, y), std::runtime_error);
    try {
    safe_add(x, y);
    } catch (std::runtime_error & e) {
    assert(std::string(e.what()) == "can't add because 6+1 appears in it");
    }
    int result = safe_add(66, 30);
    int expected = 96;
    assert(result == expected);
    }

int main(){
    std::cout << "Test1:\n\n";
    test1();

    std::cout << "\n\nTest2:\n\n";
    test2();

}