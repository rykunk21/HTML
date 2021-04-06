#pragma once

#include <vector>
using std::vector;

struct PythonicIntVector{
    vector<int> v;

    PythonicIntVector() = default;

    int at(const int& arg);
    void push_back(const int& arg);

};
