#include <stack>
#include <deque>
#include <cassert>
#include <iostream>
template <typename type>
std::stack<type> reverse_stack(std::stack<type> stackin){
    int i = static_cast<int>(stackin.size());
    std::stack<type> out;
    while (i > 0){
        out.push(stackin.top());
        stackin.pop();
        i--;
    }
    return out;
}

template <typename type>
void print(std::stack<type> stack){
    int size = static_cast<int>(stack.size());
    for (int i=0; i< size; i++){
        std::cout << stack.top() << ' ';
        stack.pop();
    }
    std::cout << std::endl;
}

int main(){
    std::deque<int> deq {3, 1, 4, 1, 5};
    std::stack<int> input(deq);
    std::stack<int> result = reverse_stack(input);
    std::deque<int> deq_ex {5, 1, 4, 1, 3};
    std::stack<int> expected(deq_ex);

    print(result);
    print(expected);
    assert(result.size() == expected.size());
    while (!result.empty()) {
    assert(result.top()== expected.top());
    result.pop(); expected.pop();
    }
    std::stack<double> input_2;
    std::stack<double> result_2 = reverse_stack(input_2);
    std::stack<double> expected_2;
    assert(result_2== expected_2);

    return 0;
}