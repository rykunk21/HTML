#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;
#include <exception>
using std::exception;
/*
template <typename T, size_t size>
void print(T (&arr)[size]){
    for (auto elem: arr){
        cout << elem << ' ';
    }
    cout << '\n';
}

template <typename T, size_t size>
void _2Dprint(T (&arr)[size]){
    for (int i =0; i<8; i++){
        for (int j =0; j<8; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

template <typename T, size_t size>
void recursive_add(T item_to_add, T (&arr)[size]){
    
}

int main(){
    // default initialization to 8 for array of ints
    int arr[8] = {0};

    // any way to do this without nested for loops?
    int grid[8][8];
    for (int i =0; i<8; i++){
        for (int j =0; j<8; j++){
            grid[i][j] = 1;
        } 
    }
    print(arr);
    cout << '\n';
    _2Dprint(grid);
}   

*/

void test(){
    cout << 1+2 << endl;
}

int main(){
    test;
}

