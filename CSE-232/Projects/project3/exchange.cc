#include "exchange.h"


void Exchange::Sort(){
    // std::sort()
}

Account* Exchange::GetUser(const std::string& name){
    // get a reference to the user object in users_ to be mutated

    for (Account& usr: users_){
        if (usr.name() == name){
            return &usr;
        }
    }
    Account usr(name);
    users_.push_back(usr);
    return GetUser(usr.name()); // recursively return user
    
}

void Exchange::MakeDeposit(const std::string &username, 
                           const std::string &asset_name, int amount){
    // deposit the asset into the users portfolio
    Account* usr = GetUser(username);
    
    Asset asset(asset_name, amount);
    asset = usr->Deposit(asset);

}

void Exchange::PrintUserPortfolios(std::ostream &os) const{
        for (Account usr: users_){
            os << usr << std::endl;
        }

}
bool Exchange::MakeWithdrawal(const std::string &username, 
                              const std::string &asset_name, int amount){
    Account* usr = GetUser(username);
    Asset asset(asset_name, amount);
    return !usr->Withdraw(asset);

    
}

bool Exchange::MakeWithdrawal(const std::string &username, Asset asset){
    Account* usr = GetUser(username);
    return usr->Withdraw(asset);

    
}

void Exchange::ExecuteTrade(){
    // Execute a trade, optimize data



}

bool Exchange::AddOrder(const Order &order){
    // check side first
    Account* usr = GetUser(order.username);
    Asset asset = order.asset;

    // Buy
    if (order.side == "Buy"){
        Asset total("USD", (order.asset.volume * order.price));
        usr->PrintAssets(cout);
        if (MakeWithdrawal(order.username, total)){
            usr->PrintAssets(cout);
            cout << "SCOPE" << endl;
            buyOrders_.push_back(order);
            ExecuteTrade();

        } else {
            return false;
        }

    // Sell
    } else if (order.side == "Sell"){
        if (usr->SufficientAsset(asset)){
            sellOrders_.push_back(order);
            ExecuteTrade();
        } else {
            return false;
        }
    }

    return false;
}

void Exchange::PrintUsersOrders(std::ostream &os) const {

}

void Exchange::PrintTradeHistory(std::ostream &os) const {

}

void Exchange::PrintBidAskSpread(std::ostream &os) const {

}

