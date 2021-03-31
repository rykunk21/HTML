#pragma once


#include <cstdlib>
#include <iostream>
#include <string>

// ASSERT_EQ

/*
template <typename T>
void assertEq(T x, T y, std::string const& nameX, std::string const& nameY, std::string const& fname, int line) {
    if (x == y) return;
    else {std::cout << "Fail" << std::endl;}
    
    std::cerr << fname << ":" << line << ": Failure" << std::endl
              << "Expected equality of these values:" << std::endl
              << "  " << nameX << std::endl
              << "    Which is: " << x << std::endl
              << "  " << nameY << std::endl
              << "    Which is: " << y << std::endl;

    std::abort();
    

}

#define ASSERT_EQ(x, y) assertEq(x, y, #x, #y, __FILE__, __LINE__)
*/

template <typename templt_type>
void ASSERT_EQ(templt_type in_in, templt_type correct_in, int test_num = 1) {
    if (in_in == correct_in) {
      std::cout << "Pass " << test_num << std::endl;
    } else {
        std::cout << "Fail " << test_num << std::endl;
    }  
}