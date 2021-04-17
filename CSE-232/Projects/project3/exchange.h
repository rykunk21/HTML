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
    bool UserExists(const std::string& name);
    void Sort();
    Account* GetUser(const std::string& name);
    void ExecuteTrade();
  public:
    
    // methods
      // functional
    void MakeDeposit(const std::string &username, const std::string &asset_,
                     int amount);
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