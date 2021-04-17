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


