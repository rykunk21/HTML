#pragma once

#include "utility.h"

class Account {
    private:
        std::string name_;
        std::vector<Asset> assets_;
        std::vector<Order> openOrders_;
        std::vector<Trade> tradeHistory_;
        void Sort(); // this is gonna suck
        Asset Find(const Asset& arg);
    public:
        // getters
        std::string name() const {return name_;};
        std::vector<Asset> Assets() const {return assets_;};
        std::vector<Order> OpenOrders() const {return openOrders_;};
        std::vector<Trade> TradeHistory() const {return tradeHistory_;};

        // setters
        void name(std::string name) {name_ = name;};
        void Assets(std::vector<Asset> assets)
                    {assets_ = assets;};
        void OpenOrders(std::vector<Order> openOrders)
                        {openOrders_ = openOrders;};
        void TradeHistory(std::vector<Trade> tradeHistory)
                          {tradeHistory_ = tradeHistory;};
        
        // methods
            // funcitonal
        Asset Deposit(const Asset& asset);
        bool Withdraw(const Asset& asset);
        bool SufficientAsset(const Asset& asset);
        void OpenOrder(const Order& order);
        void CloseOrder(const Order& order);

            //display
        void PrintOpenOrders();
        void PrintTradeHistory();
        void PrintAssets(std::ostream& oss) const;

        // constructors
        Account() = default;
        Account(std::string name){name_ = name;};
 
        // friend function
        friend std::ostream& operator<<(std::ostream& oss, const Account& usr);
};

std::ostream& operator<<(std::ostream& oss, const Account& usr);

