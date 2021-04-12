/*
Write a class, named "TwoOrLess" with a header file (two_or_less.hpp) and an 
implementation file (two_or_less.cpp).

This is a class that acts much like a set, except it can hold 0, 1, or 2 
duplicates of an int. You need to support the insert, count, and size 
methods with the same parameters and return types as the set<int> class 
(see test cases).
*/
#pragma once

#include <utility>
using std::pair;
#include <vector>
using std::vector;
#include <algorithm>
#include <iostream>
using std::cout; using std::cin; using std::endl;


class TwoOrLess{
    vector<int> values_={};
public:
    TwoOrLess() = default;

    pair<int*, bool> insert(const int& arg);
    int size() const;
    int count(const int &arg) const;

};