#include<iostream>
using std::cout; using std::endl; using std::boolalpha;
#include <exception>
using std::exception;
#include "table.h"

Table::Table(long width, long height, long val){
  width_ = width;
  height_ = height;
  int i=0;
  while(i < width){
    vector<long> col(height, val);
    t_.push_back(col);
    i++;
  }
}

void Table::fill_random(long lo, long hi, unsigned int seed){
  std::mt19937 generator(seed);
  std::uniform_int_distribution<long> distribution(lo,hi);

  for (long i=0; i<width_ ;i++){
    for (long j=0; j<height_; j++){
      t_[i][j] = distribution(generator);
    }
  }
}

bool Table::set_value(unsigned int row_num, unsigned int col_num, long val){
  try{ 
    t_.at(col_num).at(row_num) = val;
    return true;
  } catch (exception& e){
    return false;
  }
}

long Table::get_value(unsigned int row_num, unsigned int col_num) const{
  return t_.at(col_num).at(row_num);
}

void Table::print_table(ostream& ostr){
  ostringstream oss;
  for (auto col: t_){
    for (long row: col){
      oss << row << ",";
    }
    oss << '\n';
  }
  ostr << oss.str();
} 

int main (){
  bool result_bool;
  long result_long;
  cout << boolalpha;
  
  Table my_table(5,5);
  my_table.print_table(cout);
  cout << endl;;

  my_table.fill_random(1,10, 12);
  my_table.print_table(cout);
  cout << endl;;

  result_bool = my_table.set_value(100,100,100);
  cout << "Result:" << result_bool << endl;
  cout << endl;

  result_long = my_table.get_value(3,3);
  cout << result_long << endl;
  try{
    result_long = my_table.get_value(100,100);
  } catch (exception& e){
    cout << "Correct!" << endl;
  }
  cout << endl;
  
  for(int i=0; i< 5; i++)
    my_table.set_value(i,i,100);

  my_table.print_table(cout);
  cout << endl;;

}
