#include "everyother.h"
#include "mimir_testing.h"
#include <cassert>

int main(){
    EveryOther<char> eo_1 {'a', 'b', 'c', 'd'};
    ASSERT_EQ(eo_1.size(), 2, 1);
    eo_1.push_back('e');
    cout << eo_1 << std::endl;
    ASSERT_EQ(eo_1.size(), 3, 2);
    eo_1.push_back('f');
    ASSERT_EQ(eo_1.size(), 3, 3);
    EveryOther<std::string> eo_2 {"include", "don't", "keep"};
    
    // ASSERT_EQ(eo_2.size(), 2, 4);
    eo_2.push_back("skip");
    ASSERT_EQ(eo_2.size(), 2, 5);
    eo_2.push_back("good");
    ASSERT_EQ(eo_2.size(), 3, 6);
    std::ostringstream oss;
    oss << eo_1 << eo_2;
    std::cout << eo_1 << eo_2 << endl;
    ASSERT_EQ(oss.str(), "EveryOther(a, c, e, )EveryOther(include, keep, good, )");
    EveryOther<std::vector<int>> eo_4;
    std::vector<int> v {1, 2, 3};
    eo_4.push_back(v);

    return 0;
}