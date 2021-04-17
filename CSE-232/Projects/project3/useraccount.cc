#include "useraccount.h"

bool Account::SufficientAsset(const Asset& asset){
    // check if the user has the volume of the corresponding asset
    for (Asset& a: assets_){
        if(a.name == asset.name && a.volume >= asset.volume){
            return true;
        }
    }
    return false;
}

Asset Account::Deposit(const Asset& asset){
    for (Asset& a: assets_){
        if (a.name == asset.name){
            a.volume += asset.volume;
            return a;
        }
    }
    assets_.push_back(asset);
    return asset;
}

bool Account::Withdraw(const Asset& asset){
    for (Asset& a: assets_){
        if (a.name == asset.name && a.volume >= asset.volume){
            a.volume -= asset.volume;
            return true;
        }
    }
    return false;
}

void Account::PrintAssets(std::ostream& oss) const {
    assert(assets_.size() > 0);
    for (Asset asset: assets_){
        oss << asset.volume << ' ' << asset.name << ", ";
    }
}

std::ostream& operator<<(std::ostream& oss, const Account& usr){
    oss << usr.name() << ' ';
    usr.PrintAssets(oss);
    return oss;
}