
#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;
#include <fstream>
using std::ifstream; using std::ofstream;
#include <vector>
using std::vector;

vector<string> get_input(string filename){
    vector<string> out;
    string line;
    ifstream file(filename);
    while (getline(file, line)){
        out.push_back(line);
    }
    return out;
}

char shiftLetter (char c, int n){
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    int c_ind = alpha.find(c) + 1;
    bool changed_to_lower = false;
    if (n == 26 || n == -26){
        return c;
    }
    if (66 <= int(c) && int(c) <= 90){
        changed_to_lower = true;
        c += 32;
        c = char(c);
    }
    if (n < 0){
        n = abs(26 - abs(n));
        while (n > 26){
            n = abs(26 - abs(n));
        }
    }
    int new_char_pos = c_ind + n;
    while (new_char_pos > 26){
        new_char_pos = abs(26 - new_char_pos);
    }
    char out = alpha.at(new_char_pos - 1);
    if (changed_to_lower){
        out = static_cast<char>(int(c) - 32);
    }
    return out;
}

int main(){
    cout << shiftLetter('g', 27) << endl;

} // main