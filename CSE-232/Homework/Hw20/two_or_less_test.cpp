/*
testing for two_or_less.cpp
*/
#include "two_or_less.hpp"
#include "mimir_testing.h"

void insert(){
    TwoOrLess thing;
    thing.insert(1);
    thing.insert(2);
    thing.insert(1);
    thing.insert(1);
}

void insert_and_size(){
    TwoOrLess thing;
    ASSERT_EQ(thing.size(), 0);
    thing.insert(0);
    ASSERT_EQ(thing.size(), 1);

}

void insert_size_count(){
    TwoOrLess thing;
    ASSERT_EQ(thing.size(), 0);
    ASSERT_EQ(thing.count(0), 0);
    thing.insert(0);
    ASSERT_EQ(thing.size(), 1);
    ASSERT_EQ(thing.count(0), 1);
    thing.insert(0);
    ASSERT_EQ(thing.size(), 2);
    ASSERT_EQ(thing.count(0), 2);
    thing.insert(0);
    ASSERT_EQ(thing.size(), 2);
    ASSERT_EQ(thing.count(0), 2);

}

void insert_size_count2(){
    TwoOrLess thing;
    ASSERT_EQ(thing.size(), 0);
    ASSERT_EQ(thing.count(0), 0);
    thing.insert(0);
    ASSERT_EQ(thing.size(), 1);
    ASSERT_EQ(thing.count(0), 1);
    thing.insert(1);
    ASSERT_EQ(thing.size(), 2);
    ASSERT_EQ(thing.count(1), 1);
    ASSERT_EQ(thing.count(0), 1);
    thing.insert(0);
    ASSERT_EQ(thing.size(), 3);
    ASSERT_EQ(thing.count(0), 2);
    thing.insert(0);
    ASSERT_EQ(thing.size(), 3);
    ASSERT_EQ(thing.count(0), 2);
    thing.insert(4);
    ASSERT_EQ(thing.size(), 4);
    ASSERT_EQ(thing.count(4), 1);
    ASSERT_EQ(thing.count(0), 2);
    thing.insert(4);
    thing.insert(4);
    thing.insert(4);
    thing.insert(4);
    ASSERT_EQ(thing.size(), 5);
    ASSERT_EQ(thing.count(4), 2);
    ASSERT_EQ(thing.count(1), 1);
    ASSERT_EQ(thing.count(0), 2);

}

void return_pair(){
    TwoOrLess thing;
    auto p = thing.insert(4);
    ASSERT_EQ(p.second, true);
    ASSERT_EQ(*p.first, 4);
    auto p2 = thing.insert(4);
    ASSERT_EQ(p2.second, true);
    ASSERT_EQ(*p2.first, 4);
    auto p3 = thing.insert(4);
    ASSERT_EQ(p3.second, false);
    auto p4 = thing.insert(10);
    ASSERT_EQ(p4.second, true);
    ASSERT_EQ(*p4.first, 10);

}


int main(){
}

