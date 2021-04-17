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

bool Exchange::FindMatch(Order* find ,const Order& order){


    if (order.side == "Sell"){
        for (Order& existing: buyOrders_){
            if (existing.Match(order)){
                *find = existing;
                return true;
            }
        }
    } else if (order.side == "Buy") {
        for (Order& existing: sellOrders_){
            if (existing.Match(order)){
                *find = existing;
                return true;
            }
        }
    }
    return false;
}


void Exchange::ExecuteTrade(Account* usr, const Order* order, const Order* match){
    // Execute a trade, optimize data
    cout << "Trade is down to get smacked" << endl;

}

bool Exchange::AddOrder(const Order &order){
    Account* usr = GetUser(order.username);
    Asset asset = order.asset;
     // determine if theres a matching o

    // Buy
    if (order.side == "Buy"){
        Asset total("USD", (order.asset.volume * order.price));
        if (usr->SufficientAsset(total)){ // user can propose the trade
            usr->OpenOrder(order); // mark the trade as open for the user
            Order match;
            if (FindMatch(&match, order)){
                ExecuteTrade(usr, &order, &match);
            } else {
                buyOrders_.push_back(order);
                cout << "Nobody willing to sell rn" << endl;
            }

        } else {
            return false;
        }

    // Sell
    } else if (order.side == "Sell"){
        if (usr->SufficientAsset(asset)){
            Order match;
            if (FindMatch(&match, order)){
                ExecuteTrade(usr, &order, &match);
            } else {
                sellOrders_.push_back(order);
                cout << "We cant buy rn" << endl;
            }
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

