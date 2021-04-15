#include "exchange.h"

bool Exchange::UserExists(const std::string& name){
    for (User usr: users_){
        if (usr.name == name){
            return true;
        }
    }
    return false;
}


void Exchange::MakeDeposit(const std::string &username, const std::string &asset_,
                 int amount){
    User usr(username);
    if (!UserExists(username)){
        users_.push_back(usr);
    }
    Asset asset(asset_, amount);
    
    std::cout << usr.deposit(asset).name << std::endl;


}

void Exchange::PrintUserPortfolios(std::ostream &os) const{

}
bool Exchange::MakeWithdrawal(const std::string &username, const std::string &assent,
                    int amount){
    return false;
}
bool Exchange::AddOrder(const Order &order){
    return false;
}

void Exchange::PrintUsersOrders(std::ostream &os) const {

}

void Exchange::PrintTradeHistory(std::ostream &os) const {

}

void Exchange::PrintBidAskSpread(std::ostream &os) const {

}

