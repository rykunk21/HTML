/*
Write a function (named ArrayToVector) that can accept a pointer 
(a dymanically allocated array), a size of that array, and returns a 
containing vector of the elements of that array. The function should 
dispose of the array when it is finished with it. 
*/
#include <vector>
using std::vector;
#include "mimir_testing.h"

template <typename T>
vector<T> ArrayToVector(){
    vector<T> out;

    return out;
}

int main(){
    /*CXX_FLAGS -Wall -Wpedantic -Werror*/

    int size = 3;
    char * array = new char[size];
    array[0] = '8';
    array[1] = '1';
    array[2] = 'd';
    std::vector<char> result = ArrayToVector(array, size);
    ASSERT_EQ(result.size(), size);
    ASSERT_EQ(result.at(2), 'd');
    ASSERT_EQ(result.at(0), '8');
}