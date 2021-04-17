#include "utility.h"

std::ostream& operator<<(std::ostream& oss, const Order& o){
  oss << "Name: " << o.username << endl;
  oss << "Side: " << o.side << endl;
  oss << "Asset: " << o.asset.name << " : " << o.asset.volume << endl;
  oss << "Price: " << o.price;

  return oss;
}


std::ostream& operator<<(std::ostream& oss, const Asset& a){
    oss << a.name << " : " << a.volume;
    
    return oss;
}

bool Order::Match(const Order& other){
    // find a matching Order for the argument
    return (other.side != side) && (other.asset.name == asset.name)
                  && (other.price == price);

  
}

