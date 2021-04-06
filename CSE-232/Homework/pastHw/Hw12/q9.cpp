#include <iostream>
#include <string>
#include <stdexcept>
using std::string;
// write your solution here:

int crazy_convert(const string &s1){
    throw std::invalid_argument("invalid argument");
}

int sanitize_crazy_convert(const string &s1){
  try{
    return crazy_convert(s1);
    
  } catch (std::invalid_argument &e){
    return -1;
  } catch (std::runtime_error &e) {
    // throw std::length_error();
  }
  
}

int main(){
    string s1 = ""
    cout << sanitize_crazy_convert(s1);

    return 0;
}