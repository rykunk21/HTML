#include <iostream>
#include <iterator>
#include <list>
#include <cassert>



int center(std::list<int>::const_iterator i1, std::list<int>::const_iterator i2){
    int val;
    --i2;
    if (*i1 == *i2){
        return *i1;
    }
    val = center(++i1, i2);
    return val;

}


int main(){

    std::list<int> my_list = {1, 4, 5};
    int result = center(my_list.cbegin(), my_list.cend());
    std::cout << result;
    assert(result== 4);
    my_list = {-5, 9, 7};
    result = center(my_list.cbegin(), my_list.cend());
    assert(result == 9);
    return 0;
}