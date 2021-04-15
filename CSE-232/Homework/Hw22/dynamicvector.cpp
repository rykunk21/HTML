#include "Dynamicvector.h"

#include <iostream>
#include <cassert>

int main(){

    
    const int size = 3;
    int * array = new int [size] {1, 4, 7};
    DynamicVector dv(array, size);
    assert(dv.capacity() == 3);
    assert(dv.size() == 3);
    assert(dv.data() ==  array);
    dv.reserve(2);
    assert(dv.capacity()== 3);
    assert(dv.size()== 3);
    assert(dv.data()== array);
    // std::cout << dv.at(3) << std::endl;
    dv.reserve(7);
    assert(dv.capacity() ==  7);
    assert (dv.size()==3);
    int * new_array = dv.data();
    assert(new_array !=  array);
    dv.at(0) = -78;
    assert(new_array[0]== -78);
    // ASSERT_THROW(dv.at(3), std::out_of_range);
}