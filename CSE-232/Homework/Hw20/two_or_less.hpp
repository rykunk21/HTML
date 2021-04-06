/*
Write a class, named "TwoOrLess" with a header file (two_or_less.hpp) and an 
implementation file (two_or_less.cpp).

This is a class that acts much like a set, except it can hold 0, 1, or 2 
duplicates of an int. You need to support the insert, count, and size 
methods with the same parameters and return types as the set<int> class 
(see test cases).
*/

#include <utility>
using std::pair;

class TwoOrLess{
public:
    pair<int*, bool> insert(int arg);
    int size();
    int count(int arg);
};