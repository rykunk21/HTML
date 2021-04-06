#pragma once

#include <vector>
using std::vector;


struct FunnyVector{
    vector<int> v;
    int threshold=1;

    int size();
    void push_back(const int& arg);
    vector<int> get();

    FunnyVector() = default;
    FunnyVector(const int& threshold);
    
};