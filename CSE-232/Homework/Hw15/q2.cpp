/*
There's an old joke: "Why is 6 scared of 7? Because 7 8 9 (seven ate nine)." 
But since hearing that joke, I've had an irrational fear of the number 7. 
Write a templated function, called "safe_add" that adds two numbers 
(ints, floats, doubles, etc) and returns their sum. However, if either number 
(or their sum) contains the number 7, raise a runtime_error stating "can't
add because 6+1 appears in it".

*/
#include <cassert>
#include <stdexcept>


int safe_add(int num1, int num2){
    
}


void testing(){

    const int x = 10, y = 99;
    int result = safe_add(x, y);
    int expected = 109;
    assert(result == expected); 


    const int x = 10, y = 60;
    //ASSERT_THROW(safe_add(x, y), std::runtime_error);
    int result = safe_add(66, 30);
    int expected = 96;

    #include <stdexcept>
    #include <string>
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
    testing();

}