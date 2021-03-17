#include <cassert>
#include <string>
#include <vector>
#include <utility>

void ShiftRange(std::vector<int> &v, int left, int right) {
    /*
    Given a vector of ints, v, sorts the vector and moves all elements within 
    the range [left, right] to the end of the vector.

    copy the range left to right into a new vector
    remove range left to right from orivinal vector
    sort the vector
    contatenate the new vector together
    */




}

void PassOrFail(std::vector<std::pair<std::string, int>> &v) {
    /*
    Given a vector, v, where each element of the vector is a (name, grade) 
    pair, sorts the vector by name and partitions the first half of the 
    vector as pairs who passed, and the second half of the vector as pairs who 
    failed.

    A pair “passes” if the grade is greater than or equal to 600 points.
    */

}

std::vector<int> Fibonacci(int n) {
    /* 
    Generates the first n Fibonacci numbers.

    make a blank vector of size n
    transform all elements based on the Fibonacci function
        need index and original vector
        how do we get the position of the element in a generic function?
    */
    std::vector<int> v1(n);


}

int BinaryToInt(const std::string &binary_str) {
    /*
    Converts a binary string (base 2) to an int (base 10).
    #include <string>
    using std::stoi
    int stoi (const string&  str, size_t* idx = 0, int base = 10);
    */


}

int main() {
    // given (a vector of ints, and ints "left", and "right"), sort the vector, rotate all numbers in the range
    // [left,right] to end of vector
    std::vector<int> v1 = {13, 22, 4, 5, 3, 11, 16, 25, 7};
    std::vector<int> w1 = {3, 4, 5, 7, 22, 25, 11, 13, 16};
    // Notice that 11, 13, 15 (the values between 10 and 20 are moved to the end)

    ShiftRange(v1, 10, 20);
    assert(v1 == w1);

    // given a vector, where each element in the vector is a [name,grade] pair
    // sort range by name, partition range into pass and fail, preserving
    // alphabetic order within partition
    // Note: the grades are the number of points earned (600 points earns a passing grade)
    std::vector<std::pair<std::string, int>> v2 {
        {"josh", 851},
        {"mark", 600},
        {"charles", 412},
        {"sebnem", 1000},
        {"abdol", 905},
        {"imen", 300}
    };
    std::vector<std::pair<std::string, int>> w2 { 
        {"abdol", 905}, 
        {"josh", 851}, 
        {"mark", 600}, 
        {"sebnem", 1000},  // Everyone after this point failed
        {"charles", 412}, 
        {"imen", 300}
    };

    PassOrFail(v2);
    assert(v2 == w2);

    // generate 1st n fibonacci numbers
    // See: https://en.wikipedia.org/wiki/Fibonacci_number
    std::vector<int> v3 = Fibonacci(8);
    std::vector<int> w3 = {1, 1, 2, 3, 5, 8, 13, 21};
    assert(v3 == w3);

    // convert at string representing a binary number 
    // to an int
    const std::string binary_str = "10110";
    int result = BinaryToInt("10110");
    assert(result == 22);
}

