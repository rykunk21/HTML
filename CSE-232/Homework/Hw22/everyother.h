#pragma once


#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <vector>
using std::vector;
#include <initializer_list>
using std::initializer_list;
#include <algorithm>
using std::copy; using std::copy_if;
#include <iterator>
using std::back_inserter;
#include <string>
using std::string;
#include <sstream>

template <typename T>
class EveryOther{
    private:
        vector<T> data;
        bool add = true;
        
    public:
        EveryOther() = default;
        EveryOther(initializer_list<T> init){
            vector<T> hold;
            copy(init.begin(), init.end(), back_inserter(hold));
            for (int i=0; i<static_cast<int>(hold.size()); i+=2){
                data.push_back(hold[i]);
            }
            add = ((hold.size() % 2) == 0);
        }
        
        void push_back(T arg){
            if (add){
                data.push_back(arg);
            }
            add = !add;
        }

        int size(){
            return data.size();
        }

        template <typename type>
        friend std::ostream& operator<<(std::ostream& oss, EveryOther<type>& vec);
};

template <typename T>
std::ostream& operator<<(std::ostream& oss, EveryOther<T>& vec){
    oss << "EveryOther(";
    copy(vec.data.begin(), vec.data.end(), std::ostream_iterator<T>(oss, ", "));
    oss << ")";
    return oss;
}   