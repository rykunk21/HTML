/*
template <class ForwardIterator, class UnaryPredicate>
  ForwardIterator remove_if (ForwardIterator first, ForwardIterator last,
                             UnaryPredicate pred)
{
  ForwardIterator result = first;
  while (first!=last) {
    if (!pred(*first)) {
      if (result!=first)
        *result = std::move(*first);
      ++result;
    }
    ++first;
  }
  return result;
}
*/

#include <iostream>
#include <vector>
using std::vector;
#include <algorithm>
using std::copy_if;
#include <iomanip>

vector<int> get_positives(vector<int>::iterator begin, 
                           vector<int>::iterator end) {

    vector<int> out;
    copy_if(begin, end, back_inserter(out),[](int arg){
        return (arg > 0);
    });

    return out;    
} // fn

template <typename any>
void ASSERT_EQ(any arg1, any arg2){
    std::cout << std::boolalpha << (arg1 == arg2);
}

int main(){
    #include <vector>
    using std::vector;
    vector<int> v{1, 4, -7, 100, 3, 0, 12, -6};
    vector<int> expected{1, 4, 100, 3, 12};
    vector<int> result = get_positives(v.begin(), v.end());
    ASSERT_EQ(expected, result);
    return 0;

} // main