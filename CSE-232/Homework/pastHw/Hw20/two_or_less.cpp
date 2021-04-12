#include "two_or_less.hpp"


pair<int*, bool> TwoOrLess::insert(const int& arg){
    bool inserted = false;
    int occurances = this->count(arg);
    if(occurances < 2){
        inserted = true;
        values_.push_back(arg);
    }

    int* ptr = &values_.back();
    pair<int*, bool> out (ptr, inserted); // pointer to the value that was inserted
    return out;
}

int TwoOrLess::size() const {
    return values_.size();
}

int TwoOrLess::count(const int& arg) const {
    return std::count(values_.begin(), values_.end(), arg);
}
