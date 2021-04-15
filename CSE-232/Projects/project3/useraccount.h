#pragma once

#include "utility.h"


class Portfolio {
    private:
        std::vector<Asset> assets_;
        std::vector<Order> openOrders_;
        std::vector<Order> tradeHistory_;
        bool AssetExists(Asset);
    public:
        // getters
        std::vector<Asset> Assets() const {return assets_;};
        std::vector<Order> OpenOrders() const {return openOrders_;};
        std::vector<Order> TradeHistory() const {return tradeHistory_;};

        // setters (not super important)
        void Assets(std::vector<Asset> assets)
                    {assets_ = assets;};
        void OpenOrders(std::vector<Order> openOrders)
                        {openOrders_ = openOrders;};
        void TradeHistory(std::vector<Order> tradeHistory)
                          {tradeHistory_ = tradeHistory;};
        
        // methods
        Asset AddAsset(Asset asset);
        bool SufficientFunds(Asset asset, int amount);
        void PrintOpenOrders();
        void PrintTradeHistory();

        // constructors
        Portfolio() = default;
        Portfolio(Asset asset);  

};

struct User{
    std::string name;
    Portfolio assets;
    Asset deposit(Asset asset){return assets.AddAsset(asset);};
    bool withdraw(Asset asset);

    User() = default;
    User(std::string name_){name = name_;};
};