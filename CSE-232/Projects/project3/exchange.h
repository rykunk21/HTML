#pragma once
#include <iostream>
#include <string>

#include "useraccount.h"
#include "utility.h"

class Exchange {
  private:
    std::vector<User> users_;
    std::vector<Order> openOrders_;
    std::vector<Trade> completed_;
    bool UserExists(const std::string& name);
  public:
    void MakeDeposit(const std::string &username, const std::string &asset_,
                     int amount);
    void PrintUserPortfolios(std::ostream &os) const;
    bool MakeWithdrawal(const std::string &username, const std::string &assent,
                        int amount);
    bool AddOrder(const Order &order);
    void PrintUsersOrders(std::ostream &os) const;
    void PrintTradeHistory(std::ostream &os) const;
    void PrintBidAskSpread(std::ostream &os) const;
};