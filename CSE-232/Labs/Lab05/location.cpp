#include <iostream>
using std::cout, std::cin, std::endl;
#include <string>
using std::string;
#include <algorithm>
using std::sort;
#include <cmath>

string reverse(string s) {
    string out = "";
    for (string::size_type i=0; i<=s.size(); i++) {
        out += s[s.size()-i];
    }
    return out;
}
// 11

// 1011
// d_ba
// abd

// 
// 10001 -> odd
// 10000 -> even
string to_bin(long dec) {
    string out;
    while (dec > 0) {
        out += std::to_string(dec % 2);
        dec /= 2;
    }
    return out;
}





long loc_to_dec(string loc) {
    long out = 0;
    for (char c : loc) {
        out += pow(2, static_cast<int>(c-'a'));
    }
    return out;
}

string dec_to_loc(long dec) {
    string bin = to_bin(dec);
    string out;
    for (string::size_type i=0; i<bin.size(); i++) {
        if (bin[i]=='1')
            out += static_cast<char>(i)+'a';
    }
    return out;
}

string abbreviate(string loc) {
    sort(loc.begin(), loc.end());
    bool passed = true;
    while (passed) {
        passed = false;
        for (string::size_type i=1; i<loc.size(); i++) {
            if (loc[i] == loc[i-1]) {
                passed = true;
                loc = loc.substr(0, i-1) + static_cast<char>(loc[i]+1) + 
                    loc.substr(i+1, string::npos);
            }
        }
        sort(loc.begin(), loc.end());
    }
    return loc;
}

long add_loc(string loc1, string loc2) {
    return loc_to_dec(loc1+loc2);
}

int main() {
    string loc1;
    cout << "Give me a location string:" << endl;
    cin >> loc1;
    
    long num;
    cout << "Give me an integer:" << endl;
    cin >> num;
    
    cout << loc1 << " to dec: " << loc_to_dec(loc1) << endl;
    cout << loc1 << " abbreviated: " << abbreviate(loc1) << endl;
    cout << num << " to loc" << dec_to_loc(num) << endl;
    cout << "Give me two more location strings:" << endl;
    string loc2;
    string loc3;
    cin >> loc2;
    cin >> loc3;
    
    cout << "Sum of " << loc2 << " and " << loc3 << " is: " << add_loc(loc2, loc3) << endl;
    return 0;
}

