#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <string>
#include <map>


struct Asset {
  std::string name;
  int volume;

  Asset() = default;
  Asset(std::string name_, int volume_) : name(name_), volume(volume_){};

  int GetPrice();

};


struct Order {
  std::string username;
  std::string side;  // Can be "Buy" or "Sell"
  Asset asset;
  int price;

  // constructors
  Order() = default;
  Order(std::string name_, std::string side_, 
        std::string asset_, int volume_, int price_){
          username = name_;
          side = side_;
          asset = Asset(asset_, volume_);
          price = price_;
        }
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
          price = price;
        }
};


