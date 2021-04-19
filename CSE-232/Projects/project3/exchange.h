#pragma once
#include <iostream>
#include <string>

#include "useraccount.h"
#include "utility.h"

class Exchange {
  private:
    std::vector<Account> users_;
    std::vector<Order> sellOrders_;
    std::vector<Order> buyOrders_;
    std::vector<Trade> completed_;

    Account* GetUser(const std::string& name);

    bool UserExists(const std::string& name);
    bool OrdersMatch();
    void Sort();
    void ExecuteTrade(Account* usr, const Order* order, const Order* match);
    
    
  public:
    
    // methods
      // functional
    bool FindMatch(Order* find ,const Order& order);
    void MakeDeposit(const std::string &username, const std::string &asset_,
                     int amount);
    bool MakeDeposit(const std::string &username, Asset asset);
    bool MakeWithdrawal(const std::string &username, const std::string &assent,
                        int amount);
    bool MakeWithdrawal(const std::string &username, Asset asset);
    
    
    bool AddOrder(const Order &order);


      // printing
    void PrintUserPortfolios(std::ostream &os) const;
    void PrintUsersOrders(std::ostream &os) const;
    void PrintTradeHistory(std::ostream &os) const;
    void PrintBidAskSpread(std::ostream &os) const;
    
};