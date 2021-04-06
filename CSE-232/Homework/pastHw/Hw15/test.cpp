#include <string>
using std::string;
#include <cassert>
#include <iostream>
using std::cout;

string remove_duplicate(string og){
    string out;
    out += og.at(0);
    bool exists = false;

    // iterate over every letter in original
    int original_size = static_cast<int>(og.size());
    for(int i = 1; i < original_size; i++){

        // iterate over every letter that you have already appended to the
        // new string
        int out_size = static_cast<int>(out.size());
        for(int j=0; j < out_size; j++){

            // if the char is already in the new string, note existance and break
            if (og.at(i) == out.at(j)){
                
            }
        }

        // add the element if it doesnt exist
        if (exists == false)
        out += og.at(i);
        
        
    }
    return out;
}


int main(){
    string in = remove_duplicate("AABBCAB");
    string expected = "ABC";

    cout << in << '\n';  // ABCNEW

    assert(in == expected); // True

}
