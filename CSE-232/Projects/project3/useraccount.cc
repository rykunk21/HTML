#include "useraccount.h"

template <typename T>
T* Account::Find(const T& arg){
    T* out();
    Asset a();
    cout << a.name() << endl;

    // if (out->name() == a.name()){
    //     cout << "Correct Type" << endl;
    // }
    return out;
}

bool Account::SufficientAsset(const Asset& asset){
    Asset* find = Find<Asset>(asset);
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