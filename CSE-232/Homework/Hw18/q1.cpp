/*
For this problem, you will need to sort a list of whitespace separated 
integers using three different sort algorithms (described here: 
http://theoryapp.com/selection-insertion-and-bubble-sort/ and 
https://en.wikipedia.org/wiki/Insertion_sort).

Your program will output the state of the initial list of numbers and 
also after each swap for each of the three sorting algorithms (selection, 
insertion, and bubble). Note: You want to use the version of insertion 
sort from Wikipedia.

Do not perform swaps if they don't change the vector.
*/
#include <iostream>
using std::cout; using std::cin;
#include <string>
using std::string;
#include <sstream>
using std::ostringstream; using std::istringstream;
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;
#include <cassert>
#include <algorithm>
using std::sort; using std::min_element;
#include <iterator>
using std::back_inserter;


ostringstream get_inp(string filename){
    ostringstream out;
    ifstream file(filename);
    string hold;
    while(getline(file, hold)){
        out << hold << '\n';
    }
    return out;
}

ostringstream& print(vector<int> v, ostringstream &oss, char sep=' '){
    for (int elem: v){
        cout << elem << sep;
        oss << elem << sep;  
    }
    cout << '\n';
    oss << '\n';
    return oss;
}

ostringstream selection_sort(vector<int> &v){
    ostringstream oss;
    vector<int> sorted=v;

    sort(sorted.begin(), sorted.end()); // init a sorted list for termination
    cout << "Selection Sort" << '\n';
    oss << "Selection Sort" << '\n';

    print(v, oss); // print the vec before sorting
    while (v != sorted){
        
        int i=0;
        vector<int>::iterator min_elem;
        for (auto ptr = v.begin()+i; ptr != v.end(); ++ptr){
            
            // min element gets the smallest element in a range
            // https://www.cplusplus.com/reference/algorithm/min_element/
            min_elem = min_element(ptr, v.end());
            if (*min_elem == v.at(i)){ // Do not perform swaps if they don't change the vector. 
                i += 1;
                continue;
            }
            int hold = v.at(i);
            v.at(i) = *min_elem;
            *min_elem = hold;
            i+= 1;
            print(v, oss);
        }
    }
    return oss;
}

void swap(int &arg1, int&arg2){
    int hold = arg1;
    arg1 = arg2;
    arg2 = hold;
}

ostringstream insertion_sort(vector<int> &v){
    ostringstream oss;
    vector<int> sorted=v;

    sort(sorted.begin(), sorted.end()); // init a sorted list for termination
    cout << "Intersection Sort" << '\n';
    oss << "Intersection Sort" << '\n';

    print(v, oss); // print the vec before sorting
    while (v != sorted){
        int i=1;
        vector<int>::iterator left_elem = v.begin();
        for(auto ptr = v.begin()+1; ptr != v.end();){
            
            
            while(*ptr >= *left_elem){
                ptr -= 1;
                left_elem += 1;
                swap(*ptr, *left_elem);
                print(v, oss);
                left_elem = ptr-1;
            }
            i++;
            ptr = v.begin() + i;
            cout << "Value at " << i << ": " << *ptr << std::endl;
            assert(false);
        }
    }

    return oss;
}

void bubble_sort(vector<int> v){
    
}

int main(){
    ostringstream oss = get_inp("input.txt");
    cout << "File Input: \n" << oss.str();
    vector<int> ints = {1, 6, 3, 8, 4, 2};
    string hold;

    ostringstream oss_comp = insertion_sort(ints);

    assert(oss_comp.str() == oss.str());

    return 0;
}