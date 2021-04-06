/*
I've been playing around with numbers recently. I was asked, 
"Given three numbers, what is highest value you can generate with the 
formula (a - b) / c with a, b, and c in any order?"

So I need your help. What are all the possible permutations of three 
numbers read in from stdin? What is there result from applying the above 
formula? And, What is the highest possible value.

Notes: please use doubles for precision and always output 4 decimal places. 
Also, you are only allowed to use one loop (one instance of 'for' or 'while').

Example input: 

1
2
3
Example Output:

(1.0000 - 2.0000) / 3.0000 = -0.3333
(1.0000 - 3.0000) / 2.0000 = -1.0000
(2.0000 - 1.0000) / 3.0000 = 0.3333
(2.0000 - 3.0000) / 1.0000 = -1.0000
(3.0000 - 1.0000) / 2.0000 = 1.0000
(3.0000 - 2.0000) / 1.0000 = 1.0000
Largest value was 1.0000


The three inputted values should be sorted prior to permuting.
*/

#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <iomanip>
using std::setprecision; using std::fixed;
using cdoub = const double;
#include <vector>
using std::vector;
#include <algorithm>
using std::max_element;
using std::sort;

double formula(cdoub &a, cdoub &b, cdoub &c){
    return (a - b) / c;
} // fn

void swap(double &a, double &b){
    double hold = a;
    a = b;
    b = hold;
}


void print(cdoub &a, cdoub &b, cdoub &c){
    cout << '(' << a << " - " << b << ')';
    cout << " / " << c << " = " << formula(a, b, c) << '\n';
}

int main(){
    vector<double> v1{};
    double a;
    double b;
    double c;
    cout << fixed <<setprecision(4);

    cin >> a >> b >> c;
    v1.push_back(a);
    v1.push_back(b);
    v1.push_back(c);

    sort(v1.begin(), v1.end());

    a = v1.at(0);
    b = v1.at(1);
    c = v1.at(2);

    v1 = {};

    print(a, b, c);
    v1.push_back(formula(a, b, c));

    print(a, c, b);
    v1.push_back(formula(a, c, b));

    print(b, a, c);
    v1.push_back(formula(b, a, c));

    print(b, c, a);
    v1.push_back(formula(b, c, a));

    print(c, a, b);
    v1.push_back(formula(c, a, b));

    print(c, b, a);
    v1.push_back(formula(c, b, a));
    

    cout << "Largest value was " << *max_element(v1.begin(), 
                                                 v1.end()) << '\n';

} // main
