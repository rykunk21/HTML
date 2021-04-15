#include "exchange.h"
#include "mimir_testing.h"
using std::literals::operator""s;
#include <iostream>
#include <sstream>
#include <string>
#include <cassert>


void makeDepositSing(){
    Exchange e;
    e.MakeDeposit("Nahum", "BTC", 10);
    e.MakeDeposit("Nahum", "USD", 8500);
}

void makeDepositMult(){
    Exchange e;
    e.MakeDeposit("Nahum", "BTC", 10);
    e.MakeDeposit("Nahum", "USD", 8500);
    e.MakeDeposit("Dolson", "USD", 600);
    e.MakeDeposit("Nahum", "USD", 500);
    e.MakeDeposit("Dolson", "ETH", 60);
    e.MakeDeposit("Nahum", "ETH", 4);
    e.MakeDeposit("Ofria", "BTC", 100);

}

void printUserPortfolios(){
    
Exchange e;
e.MakeDeposit("Nahum", "BTC", 10);
e.MakeDeposit("Nahum", "USD", 8500);
e.MakeDeposit("Dolson", "USD", 600);
e.MakeDeposit("Nahum", "USD", 500);
e.MakeDeposit("Dolson", "ETH", 60);
e.MakeDeposit("Nahum", "ETH", 4);
e.MakeDeposit("Ofria", "BTC", 100);
e.PrintUserPortfolios(std::cout);
e.MakeDeposit("Dolson", "ETH", 10);
e.PrintUserPortfolios(std::cout);
std::ostringstream oss;
e.PrintUserPortfolios(oss);
ASSERT_EQ(oss.str(), "User Portfolios (in alphabetical order):\n"
                     "Dolson's Portfolio: 70 ETH, 600 USD, \n"
                     "Nahum's Portfolio: 10 BTC, 4 ETH, 9000 USD, \n"
                     "Ofria's Portfolio: 100 BTC, \n"s);
}

void makeWithdrawl(){
    Exchange e;
    e.MakeDeposit("Nahum", "BTC", 10);
    e.PrintUserPortfolios(std::cout);
    std::cout << std::endl;
    assert(!e.MakeWithdrawal("Dolson", "USD", 10)); // Dolson has no portfolio
    assert(!e.MakeWithdrawal("Nahum", "USD", 10)); // Nahum has no USD
    assert(!e.MakeWithdrawal("Nahum", "BTC", 11)); // Nahum doesn't have enough USD
    assert(e.MakeWithdrawal("Nahum", "BTC", 6)); // Success!
    std::ostringstream oss;
    e.PrintUserPortfolios(std::cout);
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), "User Portfolios (in alphabetical order):\nNahum's Portfolio: 4 BTC, \n"s);
    assert(e.MakeWithdrawal("Nahum", "BTC", 4)); 
    // Success! Remove the last of the BTC
    // Please note that you shouldn't report assets that have an amount of 0.
    e.PrintUserPortfolios(std::cout);
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), "User Portfolios (in alphabetical order):\nNahum's" 
                         "Portfolio: 4 BTC, \nUser Portfolios (in alphabetical order):"
                         "\nNahum's Portfolio: \n");
}

void makeWithdrawlcomp(){
    Exchange e;
    e.MakeDeposit("Nahum", "BTC", 10);
    e.PrintUserPortfolios(std::cout);
    std::cout << std::endl;
    assert(!e.MakeWithdrawal("Dolson", "USD", 10)); // Dolson has no portfolio
    assert(!e.MakeWithdrawal("Nahum", "USD", 10)); // Nahum has no USD
    assert(!e.MakeWithdrawal("Nahum", "BTC", 11)); // Nahum doesn't have enough USD
    assert(e.MakeWithdrawal("Nahum", "BTC", 6)); // Success!
    std::ostringstream oss;
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), "User Portfolios (in alphabetical order):\nNahum's Portfolio: 4 BTC, \n");
    assert(e.MakeWithdrawal("Nahum", "BTC", 4)); 
    // Success! Remove the last of the BTC
    // Please note that you shouldn't report assets that have an amount of 0.
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), "User Portfolios (in alphabetical order):\nNahum's Portfolio: \n");
    e.MakeDeposit("Dolson", "BTC", 4);
    e.MakeDeposit("Dolson", "USD", 4000);
    e.MakeDeposit("Ofria", "ETH", 77);
    assert(e.MakeWithdrawal("Dolson", "BTC", 1)); 
    assert(e.MakeWithdrawal("Dolson", "USD", 4000)); 
    assert(!e.MakeWithdrawal("Ofria", "BTC", 1)); 
    assert(!e.MakeWithdrawal("Ofria", "Apples", 1)); 
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), "User Portfolios (in alphabetical order):\nDolson's "
                         "Portfolio: 3 BTC, \nNahum's Portfolio: \nOfria's "
                         "Portfolio: 77 ETH, \n");
}

void ordersOverloaded(){
    
    // uncomment after finishing Order
    /*
    Order o1 {"Nahum", "Buy", "BTC", 100, 60000};
    Order o2(o1);
    assert(o1 == o2);
    Order o3 = o2;
    assert(o1 == o3);
    o3.side = "Sell";
    assert(o1 != o3);
    std::ostringstream oss;
    oss << o1;
    ASSERT_EQ(oss.str(), "Buy 100 BTC at 60000 USD by Nahum");
    oss.str("");
    oss << Order{"Dolson", "Sell", "ETH", 9, 888};
    ASSERT_EQ(oss.str(), "Sell 9 ETH at 888 USD by Dolson");
    */

}

void addorderNoTrades(){
    Exchange e;
    std::ostringstream oss;
    e.MakeDeposit("Nahum", "BTC", 10);
    e.MakeDeposit("Nahum", "USD", 500);
    e.MakeDeposit("Dolson", "USD", 1000);
    e.MakeDeposit("Ofria", "ETH", 44);
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), "User Portfolios (in alphabetical order):\nDolson's "
                         "Portfolio: 1000 USD, \nNahum's Portfolio: 10 BTC, 500 USD, "
                         "\nOfria's Portfolio: 44 ETH, \n");
    assert(!e.AddOrder({"Nahum", "Sell", "BTC", 50, 1000}));
    // Can't place order because Nahum doesn't have enough BTC
    assert(!e.AddOrder({"Nahum", "Buy", "BTC", 50, 200}));
    // Can't place order because Nahum doesn't have enough USD
    assert(e.AddOrder({"Nahum", "Sell", "BTC", 4, 1000}));
    assert(e.AddOrder({"Nahum", "Buy", "ETH", 3, 2}));
    assert(e.AddOrder({"Dolson", "Buy", "BTC", 7, 1}));
    assert(e.AddOrder({"Ofria", "Sell", "ETH", 2, 500}));
    // Make sure to remove orders from portfolios
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), "User Portfolios (in alphabetical order):\nDolson's "
                         "Portfolio: 993 USD, \nNahum's Portfolio: 6 BTC, 494 USD, "
                         "\nOfria's Portfolio: 42 ETH, \n");
}

void printUsersOrderNoTrades(){
    Exchange e;
    std::ostringstream oss;
    e.MakeDeposit("Nahum", "BTC", 10);
    e.MakeDeposit("Nahum", "USD", 500);
    e.MakeDeposit("Dolson", "USD", 1000);
    e.MakeDeposit("Ofria", "ETH", 44);
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), "User Portfolios (in alphabetical order):\nDolson's "
                         "Portfolio: 1000 USD, \nNahum's Portfolio: 10 BTC, 500 USD, "
                         "\nOfria's Portfolio: 44 ETH, \n");
    e.PrintUsersOrders (std::cout);
    oss.str("");
    e.PrintUsersOrders (oss);
    ASSERT_EQ(oss.str(), "Users Orders (in alphabetical order):\nDolson's "
                         "Open Orders (in chronological order):\nDolson's "
                         "Filled Orders (in chronological order):\nNahum's "
                         "Open Orders (in chronological order):\nNahum's Filled "
                         "Orders (in chronological order):\nOfria's Open Orders "
                         "(in chronological order):\nOfria's Filled Orders "
                         "(in chronological order):\n");
}   

void addOrderExactComplete(){
        
    Exchange e;
    std::ostringstream oss;
    e.MakeDeposit("Nahum", "BTC", 10);
    e.MakeDeposit("Dolson", "USD", 5555);
    assert(e.AddOrder({"Nahum", "Sell", "BTC", 5, 100}));
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), "User Portfolios (in alphabetical order):\nDolson's "
                         "Portfolio: 5555 USD, \nNahum's Portfolio: 5 BTC, \n");
    e.PrintUsersOrders(std::cout);
    oss.str("");
    e.PrintUsersOrders(oss);
    ASSERT_EQ(oss.str(), "Users Orders (in alphabetical order):\nDolson's "
                         "Open Orders (in chronological order):\nDolson's "
                         "Filled Orders (in chronological order):\nNahum's "
                         "Open Orders (in chronological order):\nSell 5 BTC "
                         "at 100 USD by Nahum\nNahum's Filled Orders "
                         "(in chronological order):\n");
    std::cout << std::endl << std::endl;
    assert(e.AddOrder({"Dolson", "Buy", "BTC", 5, 100}));
    // This trade exactly matches Nahum's Sell
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), "User Portfolios (in alphabetical order):\nDolson's "
                         "Portfolio: 5 BTC, 5055 USD, \nNahum's Portfolio: 5 BTC, 500 USD, \n");
    e.PrintUsersOrders (std::cout);
    oss.str("");
    e.PrintUsersOrders (oss);
    ASSERT_EQ(oss.str(), "Users Orders (in alphabetical order):\nDolson's "
                         "Open Orders (in chronological order):\nDolson's "
                         "Filled Orders (in chronological order):\nBuy 5 BTC "
                         "at 100 USD by Dolson\nNahum's Open Orders "
                         "(in chronological order):\nNahum's Filled Orders "
                         "(in chronological order):\nSell 5 BTC at 100 USD by Nahum\n");
}

void addOrderExactIncomplete(){
    Exchange e;
    std::ostringstream oss;
    e.MakeDeposit("Nahum", "BTC", 10);
    e.MakeDeposit("Dolson", "USD", 5555);
    assert(e.AddOrder({"Nahum", "Sell", "BTC", 5, 100}));
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), "User Portfolios (in alphabetical order):\nDolson's "
                         "Portfolio: 5555 USD, \nNahum's Portfolio: 5 BTC, \n");
    e.PrintUsersOrders(std::cout);
    oss.str("");
    e.PrintUsersOrders(oss);
    ASSERT_EQ(oss.str(), "Users Orders (in alphabetical order):\nDolson's "
                         "Open Orders (in chronological order):\nDolson's "
                         "Filled Orders (in chronological order):\nNahum's "
                         "Open Orders (in chronological order):\nSell 5 BTC "
                         "at 100 USD by Nahum\nNahum's Filled Orders "
                         "(in chronological order):\n");
    std::cout << std::endl << std::endl;
    assert(e.AddOrder({"Dolson", "Buy", "BTC", 7, 100}));
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), "User Portfolios (in alphabetical order):\nDolson's "
                         "Portfolio: 5 BTC, 4855 USD, \nNahum's Portfolio: "
                         "5 BTC, 500 USD, \n");
    e.PrintUsersOrders (std::cout);
    oss.str("");
    e.PrintUsersOrders (oss);
    ASSERT_EQ(oss.str(), "Users Orders (in alphabetical order):\nDolson's "
                         "Open Orders (in chronological order):\nBuy 2 BTC at "
                         "100 USD by Dolson\nDolson's Filled Orders "
                         "(in chronological order):\nBuy 5 BTC at 100 USD by "
                         "Dolson\nNahum's Open Orders (in chronological order):"
                         "\nNahum's Filled Orders (in chronological order):"
                         "\nSell 5 BTC at 100 USD by Nahum\n");
    std::cout << std::endl << std::endl;
    assert(e.AddOrder({"Nahum", "Sell", "BTC", 3, 100}));
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), "User Portfolios (in alphabetical order):\nDolson's "
                         "Portfolio: 7 BTC, 4855 USD, \nNahum's Portfolio: 2 "
                         "BTC, 700 USD, \n");
    e.PrintUsersOrders (std::cout);
    oss.str("");
    e.PrintUsersOrders (oss);
    ASSERT_EQ(oss.str(), "Users Orders (in alphabetical order):\nDolson's "
                         "Open Orders (in chronological order):\nDolson's "
                         "Filled Orders (in chronological order):\nBuy 5 BTC at "
                         "100 USD by Dolson\nBuy 2 BTC at 100 USD by Dolson\n"
                         "Nahum's Open Orders (in chronological order):\n"
                         "Sell 1 BTC at 100 USD by Nahum\nNahum's Filled Orders"
                         " (in chronological order):\nSell 5 BTC at 100 USD by Nahum\n"
                         "Sell 2 BTC at 100 USD by Nahum\n");
}

void addOrderDifferentTM(){
    Exchange e;
    std::ostringstream oss;
    e.MakeDeposit("Nahum", "BTC", 1000);
    e.MakeDeposit("Dolson", "USD", 555555);
    assert(e.AddOrder({"Nahum", "Sell", "BTC", 5, 100}));
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), 
    "User Portfolios (in alphabetical order):\nDolson's Portfolio: "
    "555555 USD, \nNahum's Portfolio: 995 BTC, \n"
    );
    e.PrintUsersOrders(std::cout);
    oss.str("");
    e.PrintUsersOrders(oss);
    ASSERT_EQ(oss.str(), 
    "Users Orders (in alphabetical order):\nDolson's Open "
    "Orders (in chronological order):\nDolson's Filled Orders "
    "(in chronological order):\nNahum's Open Orders (in chronological order):\n"
    "Sell 5 BTC at 100 USD by Nahum\nNahum's Filled Orders "
    "(in chronological order):\n"
    );
    std::cout << std::endl << std::endl;
    assert(e.AddOrder({"Dolson", "Buy", "BTC", 70, 150}));
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), 
    "User Portfolios (in alphabetical order):\nDolson's Portfolio: 5 BTC, "
    "545055 USD, \nNahum's Portfolio: 995 BTC, 750 USD, \n"
    );
    e.PrintUsersOrders (std::cout);
    oss.str("");
    e.PrintUsersOrders (oss);
    ASSERT_EQ(oss.str(), 
    "Users Orders (in alphabetical order):\nDolson's Open Orders "
    "(in chronological order):\nBuy 65 BTC at 150 USD by Dolson\nDolson's "
    "Filled Orders (in chronological order):\nBuy 5 BTC at 150 USD by Dolson\n"
    "Nahum's Open Orders (in chronological order):\nNahum's Filled Orders "
    "(in chronological order):\nSell 5 BTC at 150 USD by Nahum\n"
    );
    std::cout << std::endl << std::endl;
    assert(e.AddOrder({"Nahum", "Sell", "BTC", 30, 125}));
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), 
    "User Portfolios (in alphabetical order):\nDolson's Portfolio: 35 BTC, "
    "545055 USD, \nNahum's Portfolio: 965 BTC, 4500 USD, \n"
    );
    e.PrintUsersOrders (std::cout);
    oss.str("");
    e.PrintUsersOrders (oss);
    ASSERT_EQ(oss.str(), 
    "Users Orders (in alphabetical order):\nDolson's Open Orders "
    "(in chronological order):\nBuy 35 BTC at 150 USD by Dolson\nDolson's "
    "Filled Orders (in chronological order):\nBuy 5 BTC at 150 USD by "
    "Dolson\nBuy 30 BTC at 125 USD by Dolson\nNahum's Open Orders "
    "(in chronological order):\nNahum's Filled Orders (in chronological order):"
    "\nSell 5 BTC at 150 USD by Nahum\nSell 30 BTC at 125 USD by Nahum\n"
    );
    assert(e.MakeWithdrawal("Dolson", "BTC", 35));
}

void printTradeHistory(){
    Exchange e;
    std::ostringstream oss;
    e.MakeDeposit("Nahum", "BTC", 1000);
    e.MakeDeposit("Dolson", "USD", 555555);
    assert(e.AddOrder({"Nahum", "Sell", "BTC", 5, 100}));
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), 
    "User Portfolios (in alphabetical order):\n"
    "Dolson's Portfolio: 555555 USD, \n"
    "Nahum's Portfolio: 995 BTC, \n"
    );
    e.PrintUsersOrders(std::cout);
    oss.str("");
    e.PrintUsersOrders(oss);
    ASSERT_EQ(oss.str(), 
    "Users Orders (in alphabetical order):\n"
    "Dolson's Open Orders (in chronological order):\n"
    "Dolson's Filled Orders (in chronological order):\n"
    "Nahum's Open Orders (in chronological order):\n"
    "Sell 5 BTC at 100 USD by Nahum\n"
    "Nahum's Filled Orders (in chronological order):\n"
    );
    std::cout << std::endl << std::endl;
    assert(e.AddOrder({"Dolson", "Buy", "BTC", 70, 150}));
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), 
    "User Portfolios (in alphabetical order):\nDolson's Portfolio: 5 BTC, "
    "545055 USD, \nNahum's Portfolio: 995 BTC, 750 USD, \n"
    );
    e.PrintUsersOrders(std::cout);
    oss.str("");
    e.PrintUsersOrders(oss);
    ASSERT_EQ(oss.str(), 
    "Users Orders (in alphabetical order):\nDolson's Open Orders "
    "(in chronological order):\nBuy 65 BTC at 150 USD by Dolson\n"
    "Dolson's Filled Orders (in chronological order):\nBuy 5 BTC at 150 USD by"
    " Dolson\nNahum's Open Orders (in chronological order):\nNahum's Filled Orders"
    " (in chronological order):\nSell 5 BTC at 150 USD by Nahum\n"
    );
    std::cout << std::endl << std::endl;
    assert(e.AddOrder({"Nahum", "Sell", "BTC", 30, 125}));
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), 
    "User Portfolios (in alphabetical order):\nDolson's Portfolio: 35 BTC, "
    "545055 USD, \nNahum's Portfolio: 965 BTC, 4500 USD, \n"
    );
    e.PrintUsersOrders(std::cout);
    oss.str("");
    e.PrintUsersOrders(oss);
    ASSERT_EQ(oss.str(), 
    "Users Orders (in alphabetical order):\nDolson's Open Orders "
    "(in chronological order):\nBuy 35 BTC at 150 USD by Dolson\nDolson's "
    "Filled Orders (in chronological order):\nBuy 5 BTC at 150 USD by Dolson\n"
    "Buy 30 BTC at 125 USD by Dolson\nNahum's Open Orders (in chronological order):"
    "\nNahum's Filled Orders (in chronological order):\nSell 5 BTC at 150 USD by Nahum\n"
    "Sell 30 BTC at 125 USD by Nahum\n"
    );
    std::cout << std::endl << std::endl;
    assert(e.AddOrder({"Nahum", "Sell", "BTC", 40, 120}));
    e.PrintTradeHistory(std::cout);
    oss.str("");
    e.PrintTradeHistory(oss);
    ASSERT_EQ(oss.str(), 
    "Trade History (in chronological order):\nDolson Bought 5 of BTC From Nahum"
    " for 150 USD\nDolson Bought 30 of BTC From Nahum for 125 USD\nDolson Bought "
    "35 of BTC From Nahum for 120 USD\n");
}

void manyTrades(){
        
    Exchange e;
    std::ostringstream oss;
    e.MakeDeposit("Nahum", "BTC", 1000);
    e.MakeDeposit("Nahum", "USD", 100000);
    e.MakeDeposit("Dolson", "USD", 555555);
    e.MakeDeposit("Ofria", "ETH", 678);
    e.MakeDeposit("Zaabar", "USD", 12121212);
    e.MakeDeposit("Zaabar", "LTC", 4563);
    // BTC rough price 1000
    // ETH rough price 100
    // LTC rough price 500
    e.AddOrder({"Nahum", "Sell", "BTC", 5, 1100});
    e.AddOrder({"Nahum", "Sell", "BTC", 100, 1200});
    e.AddOrder({"Nahum", "Buy", "BTC", 7, 800});
    e.AddOrder({"Dolson", "Buy", "BTC", 1, 950});
    e.AddOrder({"Ofria", "Sell", "ETH", 12, 156});
    e.AddOrder({"Ofria", "Sell", "ETH", 10, 160});
    e.AddOrder({"Zaabar", "Sell", "LTC", 10, 550});
    e.AddOrder({"Zaabar", "Buy", "LTC", 10, 450});
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), 
    "User Portfolios (in alphabetical order):\nDolson's Portfolio: 554605 USD,"
    " \nNahum's Portfolio: 895 BTC, 94400 USD, \nOfria's Portfolio: 656 ETH, "
    "\nZaabar's Portfolio: 4553 LTC, 12116712 USD, \n"
    );
    e.PrintUsersOrders(std::cout);
    oss.str("");
    e.PrintUsersOrders(oss);
    ASSERT_EQ(oss.str(), 
    "Users Orders (in alphabetical order):\nDolson's Open Orders (in chronological order):"
    "\nBuy 1 BTC at 950 USD by Dolson\nDolson's Filled Orders (in chronological order):"
    "\nNahum's Open Orders (in chronological order):\nSell 5 BTC at 1100 USD by "
    "Nahum\nSell 100 BTC at 1200 USD by Nahum\nBuy 7 BTC at 800 USD by Nahum\nNahum's "
    "Filled Orders (in chronological order):\nOfria's Open Orders (in chronological order):\n"
    "Sell 12 ETH at 156 USD by Ofria\nSell 10 ETH at 160 USD by Ofria\nOfria's Filled Orders "
    "(in chronological order):\nZaabar's Open Orders (in chronological order):\n"
    "Sell 10 LTC at 550 USD by Zaabar\nBuy 10 LTC at 450 USD by Zaabar\nZaabar's Filled Orders"
    " (in chronological order):\n"
    );
    std::cout << std::endl << std::endl;
    e.AddOrder({"Nahum", "Buy", "LTC", 55, 600});
    e.AddOrder({"Nahum", "Buy", "ETH", 30, 158});
    e.AddOrder({"Ofria", "Sell", "ETH", 10, 140});
    e.AddOrder({"Zaabar", "Buy", "BTC", 1000, 1500});
    e.AddOrder({"Zaabar", "Buy", "ETH", 200, 1200});
    e.PrintTradeHistory(std::cout);
    oss.str("");
    e.PrintTradeHistory(oss);
    ASSERT_EQ(oss.str(), 
    "Trade History (in chronological order):\nNahum Bought 10 of LTC From Zaabar "
    "for 600 USD\nNahum Bought 12 of ETH From Ofria for 158 USD\nNahum Bought 10"
    " of ETH From Ofria for 140 USD\nZaabar Bought 5 of BTC From Nahum for 1500 USD\nZaabar"
    " Bought 100 of BTC From Nahum for 1500 USD\nZaabar Bought 10 of ETH From Ofria for 1200 USD\n"
    );
    std::cout << std::endl;
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), 
    "User Portfolios (in alphabetical order):\nDolson's Portfolio: 554605 USD, \n"
    "Nahum's Portfolio: 895 BTC, 22 ETH, 10 LTC, 214160 USD, \nOfria's Portfolio:"
    " 646 ETH, 15296 USD, \nZaabar's Portfolio: 105 BTC, 10 ETH, 4553 LTC, 10382712 USD, \n"
    );
    std::cout << std::endl;
    e.PrintUsersOrders(std::cout);
    oss.str("");
    e.PrintUsersOrders(oss);
    ASSERT_EQ(oss.str(), 
    "Users Orders (in alphabetical order):\nDolson's Open Orders (in chronological order):"
    "\nBuy 1 BTC at 950 USD by Dolson\nDolson's Filled Orders (in chronological order):\nNahum's"
    " Open Orders (in chronological order):\nBuy 7 BTC at 800 USD by Nahum\nBuy 45 LTC at 600"
    " USD by Nahum\nBuy 8 ETH at 158 USD by Nahum\nNahum's Filled Orders (in chronological order):"
    "\nBuy 10 LTC at 600 USD by Nahum\nBuy 12 ETH at 158 USD by Nahum\nBuy 10 ETH at 140 USD by Nahum\nSell"
    " 5 BTC at 1500 USD by Nahum\nSell 100 BTC at 1500 USD by Nahum\nOfria's Open"
    " Orders (in chronological order):\nOfria's Filled Orders (in chronological order):\n"
    "Sell 12 ETH at 158 USD by Ofria\nSell 10 ETH at 140 USD by Ofria\nSell 10"
    " ETH at 1200 USD by Ofria\nZaabar's Open Orders (in chronological order):\nBuy 10"
    " LTC at 450 USD by Zaabar\nBuy 895 BTC at 1500 USD by Zaabar\nBuy 190 ETH at 1200"
    " USD by Zaabar\nZaabar's Filled Orders (in chronological order):\nSell 10 LTC at"
    " 600 USD by Zaabar\nBuy 5 BTC at 1500 USD by Zaabar\nBuy 100 BTC at 1500 USD by Zaabar\nBuy"
    " 10 ETH at 1200 USD by Zaabar\n"
    );

}

void manyTradesMore(){
    
    Exchange e;
    std::ostringstream oss;
    e.MakeDeposit("Nahum", "BTC", 1000);
    e.MakeDeposit("Nahum", "USD", 100000);
    e.MakeDeposit("Dolson", "USD", 555555);
    e.MakeDeposit("Ofria", "ETH", 678);
    e.MakeDeposit("Zaabar", "USD", 12121212);
    e.MakeDeposit("Zaabar", "LTC", 4563);
    // BTC rough price 1000
    // ETH rough price 100
    // LTC rough price 500
    e.AddOrder({"Nahum", "Sell", "BTC", 5, 1100});
    e.AddOrder({"Nahum", "Sell", "BTC", 100, 1200});
    e.AddOrder({"Nahum", "Buy", "BTC", 7, 800});
    e.AddOrder({"Dolson", "Buy", "BTC", 1, 950});
    e.AddOrder({"Ofria", "Sell", "ETH", 12, 156});
    e.AddOrder({"Ofria", "Sell", "ETH", 10, 160});
    e.AddOrder({"Zaabar", "Sell", "LTC", 10, 550});
    e.AddOrder({"Zaabar", "Buy", "LTC", 10, 450});
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), 
    "User Portfolios (in alphabetical order):\nDolson's Portfolio: 554605 USD, "
    "\nNahum's Portfolio: 895 BTC, 94400 USD, \nOfria's Portfolio: 656 ETH, \n"
    "Zaabar's Portfolio: 4553 LTC, 12116712 USD, \n"
    );
    e.PrintUsersOrders(std::cout);
    oss.str("");
    e.PrintUsersOrders(oss);
    ASSERT_EQ(oss.str(), 
    "Users Orders (in alphabetical order):\nDolson's Open Orders "
    "(in chronological order):\nBuy 1 BTC at 950 USD by Dolson\nDolson's Filled "
    "Orders (in chronological order):\nNahum's Open Orders (in chronological order):"
    "\nSell 5 BTC at 1100 USD by Nahum\nSell 100 BTC at 1200 USD by Nahum\nBuy "
    "7 BTC at 800 USD by Nahum\nNahum's Filled Orders (in chronological order):"
    "\nOfria's Open Orders (in chronological order):\nSell 12 ETH at 156 USD by "
    "Ofria\nSell 10 ETH at 160 USD by Ofria\nOfria's Filled Orders "
    "(in chronological order):\nZaabar's Open Orders (in chronological order):"
    "\nSell 10 LTC at 550 USD by Zaabar\nBuy 10 LTC at 450 USD by Zaabar\nZaabar's"
    " Filled Orders (in chronological order):\n"
    );
    std::cout << std::endl << std::endl;
    e.AddOrder({"Nahum", "Buy", "LTC", 55, 600});
    e.AddOrder({"Nahum", "Buy", "ETH", 30, 158});
    e.AddOrder({"Ofria", "Sell", "ETH", 10, 140});
    e.AddOrder({"Zaabar", "Buy", "BTC", 10, 1500});
    e.AddOrder({"Zaabar", "Buy", "ETH", 200, 1200});
    e.AddOrder({"Nahum", "Sell", "BTC", 30, 158});
    e.AddOrder({"Dolson", "Buy", "BTC", 20, 2000});
    e.PrintTradeHistory(std::cout);
    oss.str("");
    e.PrintTradeHistory(oss);
    ASSERT_EQ(oss.str(), 
    "Trade History (in chronological order):\nNahum Bought 10 of LTC From "
    "Zaabar for 600 USD\nNahum Bought 12 of ETH From Ofria for 158 USD\nNahum "
    "Bought 10 of ETH From Ofria for 140 USD\nZaabar Bought 5 of BTC From "
    "Nahum for 1500 USD\nZaabar Bought 5 of BTC From Nahum for 1500 USD\nZaabar"
    " Bought 10 of ETH From Ofria for 1200 USD\nDolson Bought 1 of BTC From "
    "Nahum for 158 USD\nNahum Bought 7 of BTC From Nahum for 158 USD\nDolson "
    "Bought 20 of BTC From Nahum for 2000 USD\n"
    );
    std::cout << std::endl;
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), 
    "User Portfolios (in alphabetical order):\nDolson's Portfolio: 21 BTC, "
    "514605 USD, \nNahum's Portfolio: 872 BTC, 22 ETH, 10 LTC, 112924 USD, \n"
    "Ofria's Portfolio: 646 ETH, 15296 USD, \nZaabar's Portfolio: 10 BTC, 10 "
    "ETH, 4553 LTC, 11867712 USD, \n"
    );
    std::cout << std::endl;
    e.PrintUsersOrders(std::cout);
    oss.str("");
    e.PrintUsersOrders(oss);
    ASSERT_EQ(oss.str(), 
    "Users Orders (in alphabetical order):\nDolson's Open Orders "
    "(in chronological order):\nDolson's Filled Orders (in chronological order):"
    "\nBuy 1 BTC at 158 USD by Dolson\nBuy 20 BTC at 2000 USD by Dolson\n"
    "Nahum's Open Orders (in chronological order):\nSell 95 BTC at 1200 USD by"
    " Nahum\nBuy 45 LTC at 600 USD by Nahum\nBuy 8 ETH at 158 USD by Nahum\nSell "
    "2 BTC at 158 USD by Nahum\nNahum's Filled Orders (in chronological order):\n"
    "Buy 10 LTC at 600 USD by Nahum\nBuy 12 ETH at 158 USD by Nahum\nBuy 10 ETH"
    " at 140 USD by Nahum\nSell 5 BTC at 1500 USD by Nahum\nSell 5 BTC at 1500 "
    "USD by Nahum\nSell 1 BTC at 158 USD by Nahum\nBuy 7 BTC at 158 USD by Nahum\n"
    "Sell 7 BTC at 158 USD by Nahum\nSell 20 BTC at 2000 USD by Nahum\nOfria's "
    "Open Orders (in chronological order):\nOfria's Filled Orders "
    "(in chronological order):\nSell 12 ETH at 158 USD by Ofria\nSell 10 ETH "
    "at 140 USD by Ofria\nSell 10 ETH at 1200 USD by Ofria\nZaabar's Open Orders "
    "(in chronological order):\nBuy 10 LTC at 450 USD by Zaabar\nBuy 190 ETH "
    "at 1200 USD by Zaabar\nZaabar's Filled Orders (in chronological order):\n"
    "Sell 10 LTC at 600 USD by Zaabar\nBuy 5 BTC at 1500 USD by Zaabar\nBuy 5 "
    "BTC at 1500 USD by Zaabar\nBuy 10 ETH at 1200 USD by Zaabar\n"
    );

}

void printBidAskSpread(){
    Exchange e;
    std::ostringstream oss;
    e.MakeDeposit("Nahum", "BTC", 1000);
    e.MakeDeposit("Nahum", "USD", 100000);
    e.MakeDeposit("Dolson", "USD", 555555);
    e.MakeDeposit("Ofria", "ETH", 678);
    e.MakeDeposit("Zaabar", "USD", 12121212);
    e.MakeDeposit("Zaabar", "LTC", 4563);
    // BTC rough price 1000
    // ETH rough price 100
    // LTC rough price 500
    e.AddOrder({"Nahum", "Sell", "BTC", 5, 1100});
    e.AddOrder({"Nahum", "Sell", "BTC", 100, 1200});
    e.AddOrder({"Nahum", "Buy", "BTC", 7, 800});
    e.AddOrder({"Dolson", "Buy", "BTC", 1, 950});
    e.AddOrder({"Ofria", "Sell", "ETH", 12, 156});
    e.AddOrder({"Ofria", "Sell", "ETH", 10, 160});
    e.AddOrder({"Zaabar", "Sell", "LTC", 10, 550});
    e.AddOrder({"Zaabar", "Buy", "LTC", 10, 450});
    e.AddOrder({"Nahum", "Buy", "LTC", 55, 600});
    e.AddOrder({"Nahum", "Buy", "ETH", 30, 158});
    e.AddOrder({"Ofria", "Sell", "ETH", 10, 140});
    e.AddOrder({"Zaabar", "Buy", "BTC", 10, 1500});
    e.AddOrder({"Zaabar", "Buy", "ETH", 200, 1200});
    e.AddOrder({"Nahum", "Sell", "BTC", 30, 158});
    e.AddOrder({"Dolson", "Buy", "BTC", 20, 2000});
    e.AddOrder({"Nahum", "Sell", "ETH", 1, 1423});
    e.PrintUserPortfolios(std::cout);
    oss.str("");
    e.PrintUserPortfolios(oss);
    ASSERT_EQ(oss.str(), 
    "User Portfolios (in alphabetical order):\nDolson's Portfolio: 21 BTC, "
    "514605 USD, \nNahum's Portfolio: 872 BTC, 21 ETH, 10 LTC, 112924 USD, \n"
    "Ofria's Portfolio: 646 ETH, 15296 USD, \nZaabar's Portfolio: 10 BTC, 10 ETH, "
    "4553 LTC, 11867712 USD, \n"
    );
    e.PrintUsersOrders(std::cout);
    oss.str("");
    e.PrintUsersOrders(oss);
    ASSERT_EQ(oss.str(), 
    "Users Orders (in alphabetical order):\n"
    "Dolson's Open Orders (in chronological order):\n"
    "Dolson's Filled Orders (in chronological order):\n"
    "Buy 1 BTC at 158 USD by Dolson\n"
    "Buy 20 BTC at 2000 USD by Dolson\n"
    "Nahum's Open Orders (in chronological order):\n"
    "Sell 95 BTC at 1200 USD by Nahum\nBuy 45 LTC at 600 USD by Nahum\n"
    "Buy 8 ETH at 158 USD by Nahum\n"
    "Sell 2 BTC at 158 USD by Nahum\n"
    "Sell 1 ETH at 1423 USD by Nahum\n"
    "Nahum's Filled Orders (in chronological order):\n"
    "Buy 10 LTC at 600 USD by Nahum\n"
    "Buy 12 ETH at 158 USD by Nahum\n"
    "Buy 10 ETH at 140 USD by Nahum\n"
    "Sell 5 BTC at 1500 USD by Nahum\n"
    "Sell 5 BTC at 1500 USD by Nahum\n"
    "Sell 1 BTC at 158 USD by Nahum\n"
    "Buy 7 BTC at 158 USD by Nahum\n"
    "Sell 7 BTC at 158 USD by Nahum\n"
    "Sell 20 BTC at 2000 USD by Nahum\n"
    "Ofria's Open Orders (in chronological order):\n"
    "Ofria's Filled Orders (in chronological order):\n"
    "Sell 12 ETH at 158 USD by Ofria\n"
    "Sell 10 ETH at 140 USD by Ofria\n"
    "Sell 10 ETH at 1200 USD by Ofria\n"
    "Zaabar's Open Orders (in chronological order):\n"
    "Buy 10 LTC at 450 USD by Zaabar\n"
    "Buy 190 ETH at 1200 USD by Zaabar\n"
    "Zaabar's Filled Orders (in chronological order):\n"
    "Sell 10 LTC at 600 USD by Zaabar\n"
    "Buy 5 BTC at 1500 USD by Zaabar\n"
    "Buy 5 BTC at 1500 USD by Zaabar\n"
    "Buy 10 ETH at 1200 USD by Zaabar\n"
    );
    std::cout << std::endl << std::endl;
    e.PrintBidAskSpread(std::cout);
    oss.str("");
    e.PrintBidAskSpread(oss);
    ASSERT_EQ(oss.str(), 
    "Asset Bid Ask Spread (in alphabetical order):\n"
    "BTC: Highest Open Buy = NA USD and Lowest Open Sell = 158 USD\n"
    "ETH: Highest Open Buy = 1200 USD and Lowest Open Sell = 1423 USD\n"
    "LTC: Highest Open Buy = 600 USD and Lowest Open Sell = NA USD\n"
    );

}


