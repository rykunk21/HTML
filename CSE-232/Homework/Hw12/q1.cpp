/*
* Write a function, named "smaller_than_predecessor", 
* that takes a reference to a vector of ints. It 
* should return an iterator pointing at the first 
* element that is strictly smaller than the element before it.
* You can assume that the vector has at least two elements. 
* If no element qualifies, return an iterator to one past 
* the end of the vector.
*/


#include <iostream>
#include <vector>
using std::vector;

using std::cin; using std::cout; using std::endl;


vector<int>::iterator smaller_than_predecessor(vector<int> &vec){
    int curr = vec.front();
    for(auto ptr = vec.begin(); ptr != vec.end(); ++ptr){
        if (*ptr < curr){
            return ptr;
        } else {
            curr = *ptr;
        }
    }

    return vec.end();
} // fn

template <typename any>
bool ASSERT_EQ(any arg1, any arg2){
    return arg1 == arg2;
}

int main(){
    std::vector<int> input = {1, 3, 7, 4, 10, 99};
    auto result = smaller_than_predecessor(input);
    ASSERT_EQ(*result, 4);
    ASSERT_EQ(result - input.begin(), 3);
    input = {1, 3, 7, 10, 99, 98};
    result = smaller_than_predecessor(input);
    ASSERT_EQ(*result, 98);
    ASSERT_EQ(result - input.begin(), 5);
    input = {1, -1, 3, 7, 10, 99, 98};
    result = smaller_than_predecessor(input);
    ASSERT_EQ(*result, -1);
    ASSERT_EQ(result - input.begin(), 1);
    input = {1, 3, 7, 10, 99, 100};
    result = smaller_than_predecessor(input);
    ASSERT_EQ(result, input.end());
}