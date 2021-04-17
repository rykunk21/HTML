#pragma once
#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <string>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <iterator>

#include "mimir_testing.h"
using std::literals::operator""s;

struct Asset {
  std::string name;
  int volume;
  Asset() : name(""), volume(0){};
  Asset(std::string name_, int volume_) : name(name_), volume(volume_){};
  friend std::ostream& operator<<(std::ostream& oss, const Asset& o);
};

struct Order {
  std::string username;
  std::string side;  // Can be "Buy" or "Sell"
  Asset asset;
  int price;

  // methods
  bool Match(const Order& order);

  // constructors
  Order() = default;
  Order(std::string name_, std::string side_, 
        std::string asset_, int volume_, int price_){
          username = name_;
          side = side_;
          asset = Asset(asset_, volume_);
          price = price_;
        }
  friend std::ostream& operator<<(std::ostream& oss, const Order& o);
};

struct Trade {
  std::string buyer_username;
  std::string seller_username;
  Asset asset;
  int price;

  // constructors
  Trade() = default;
  Trade(std::string buyer_, std::string seller_, 
        std::string asset_, int volume_, int price_){
          buyer_username = buyer_;
          seller_username = seller_;
          asset = Asset(asset_, volume_);
          price = price_;
        }
};

std::ostream& operator<<(std::ostream& oss, const Order& o);
std::ostream& operator<<(std::ostream& oss, const Asset& o);

template <typename type>
void print(const std::vector<type>&vec){
  std::copy(vec.begin(), vec.end(), 
            std::ostream_iterator<type>(cout, "\n"));
}


