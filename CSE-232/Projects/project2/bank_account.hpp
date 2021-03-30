#pragma once
#include <cassert>
#include <string>
using std::string;
#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <vector>
using std::vector;
#include <algorithm>
#include <fstream>
using std::ifstream; using std::ofstream;
#include <math.h>
#include <cmath>
using std::abs;
#include <sstream>
using std::istringstream; using std::ostringstream;
#include <iomanip>
using std::setprecision; using std::fixed;
#include <math.h>


vector<string> get_input(string filename){
    vector<string> out;
    string line;
    ifstream file(filename);
    while (getline(file, line)){
        out.push_back(line);
    }

    return out;
}

string parse_line(string &inp, string &prev_date, double &prev_balance){
    istringstream iss(inp);
    string on;
    iss >> on;
    if (on == "On"){
        iss >> prev_date; // overwrite date
        // from http://www.cplusplus.com/reference/string/string/pop_back/
        // shows how to remove the last element in a string
        prev_date.pop_back();

        iss.ignore(100, '$');
        iss >> prev_balance; // overwrite balance
    }
    return inp;
}


void deposit(double &balance, const double &deposit){
    /*
    Balances in this program are represented as doubles. The "deposit" 
    function should take a reference to a double (the balance) and a double 
    (the amount to be deposited). The function should modify the balance to 
    reflect the deposit. The function should not return anything. Note: The 
    ASSERT_NEAR function (in the test case) checks that the difference between
    the first two arguments is less than the third argument. I'm using it to 
    test that your result is within a tenth of a penny to the expected result.
    */
    
    balance += deposit;

}

bool withdraw(double &balance, const double &withdraw){
    /*
    The "withdraw" function should take a reference to a double (the balance) 
    and a double (the amount to be withdrawn). The function should modify the 
    balance to reflect the withdrawal (if there is a balance larger than the 
    amount requested). The function should return a bool indicating if the 
    withdraw succeeded (that the balance was reduced).
    */
    if (withdraw < balance){
        balance -= withdraw;
        return true;
    }
    
    return false;

}

void overdraft(double &balance, const double &withdraw){
    /*
    The "overdraft" function should take a reference to a double (the balance) 
    and a double (the amount to be withdrawn). The function should modify the 
    balance to reflect the withdrawal (regardless of if there is a balance 
    larger than the amount requested). The function should not return anything. 
    However, there is a $35 fee for performing an overdraft.
    */

    balance -= (withdraw + 35);

}

double interest_for_month(double &balance, const double &apr){
    /*
    The "interest_for_month" function should take a double (the balance) 
    and a double (the apr). The function should return the interest generated 
    on the balance for one month (one twelfth of the year). Note: As we 
    learned in Superman III and Office Space 
    (https://filmschoolrejects.com/getting-rich-with-richard-pryors-banking-
     scheme-from-superman-iii-7811840a8a0/), 
    the bank keeps fractions of a penny.
    */
    double monthly_rate = (apr / 100) / 12;

    /*
    / from https://www.cplusplus.com/reference/cmath/trunc/?kw=trunc
    / #include <math.h> will allow the use of "trunc"
    / trunc will truncate the values after a float (the fractions of cent)

    / truncate the value * 100 so you dont truncate the first two decimals
    / then divide by 100 to return a number truncated to two decimals
    */

    return trunc((monthly_rate * balance) * 100) / 100;
} 

void string_date_to_int_ptrs(string &date, int *const year, int *const month, 
                             int *const day){
    /*
    The "string_date_to_int_ptrs" function should take a string 
    (representing an ISO 8601 date like "2015-11-30") and three pointers to 
    ints for the year, month, and day. The function should not return anything, 
    but instead process the string into those three pointed at ints. Be sure 
    to use const where appropriate.
    */

    transform(date.begin(), date.end(), date.begin(), [](char &arg){
        if (arg == '-'){
            return ' ';
        } else {
            return arg;
        }
    });

    istringstream iss(date);
    
    iss >> *year >> *month >> *day;


}

void string_date_to_ints(string date, int &year, int &month, int &day){
    /*
    The "string_date_to_ints" function is almost the same as 
    "string_date_to_int_ptrs" but instead of pointers, it uses references.
    */

    string_date_to_int_ptrs(date, &year, &month, &day);

}

int number_of_first_of_months(const string &start_date, 
                              const string &end_date){
    /*
    The "number_of_first_of_months" function is used to help calculate 
    interest. Interest is accrued on the first of the month. So it is 
    important to know how many times interest has compounded between two dates. 
    This function takes two strings (representing a earlier and later date) and 
    returns the number of times interest will accrue.
    */

    int year1, month1, day1, year2, month2, day2 = -1; // init all to -1

    string_date_to_ints(start_date, year1, month1, day1); // get int values
    string_date_to_ints(end_date, year2, month2, day2);

    // from https://www.cplusplus.com/reference/cmath/abs/
    // abs value is from #include <cmath>
    // using in case date2 < date1

    // get the remaining months of the first year
    int remaining_months = abs(12 - month1);

    // total apart is the difference between whole years and add remaining
    // months
    int apart = abs(((year2 - (year1 + 1)) * 12) + remaining_months + month2);
    return apart;

}   

double interest_earned(double balance, const double apr, 
                       const string &start_date, const string &end_date){
    /*
    The "interest_earned" function is used to calculate interest. 
    Interest is accrued on the first of the month 
    (see "number_of_first_of_months").This function has 4 parameters: a 
    double (representing the account balance at the earlier date), 
    a double (representing the apr (annual percentage rate), a string 
    (representing a begin date), a string (representing an end date). The 
    function should return a double indicating the amount of interest accrued. 
    Note: interest compounds, meaning that interest earned in earlier months 
    is added to the balance prior to earning interest on later months.

    NOTE THAT COMPOUND INTEREST FORMULA DOES NOT YIELD CORRECT RESULTS :(
    (P * (1 + R/12) ^ (12T)) - P
    where P is the balance, R is the rate and T is the time in months
    */
    int months = number_of_first_of_months(start_date, end_date);
    double monthly_rate = (apr/1200); // .01
    double initial_balance = balance;
    double interest = 0.0;
    for (int i=1; i <= months; i++){
        interest = trunc((balance * monthly_rate) * 100) / 100;
        balance += interest;
    }

    return balance - initial_balance;
}


string process_command(const string &line, string &prev_date, double &prev_balance, 
                       const double &apr){
    /*
    The "process_command" function is the last helper function you need to write. 
    It processes a single command (as opposed to the "process_commands" that 
    does many. This function has 4 parameters: a string (representing a 
    line to be processed), a string (representing the date of the previous 
    line (empty if this is the first time being called)), a double (representing 
    the previous balance), a double (representing the apr). The function should 
    return a string (possible with multiple lines) indicating the work done to 
    perform the instruction. It should also update the balance to reflect any 
    changes. It should also update the previous_date to the current date of 
    the line it is processing.
    */

    // decl values that appear in the line 
    string date, command;
    double amount;

    // Read the lines into the corresponding values
    istringstream iss(line); 
    iss >> date >> command;
    iss.ignore(2, '$');
    iss >> amount;

    
    // get dates as ints
    int year, month, day = -1;
    string_date_to_ints(date, year, month, day);
    
    if (prev_date != ""){ // dont assign the next date on iter 1
        int prev_year, prev_month, prev_day = -1;
        string_date_to_ints(prev_date, prev_year, prev_month, prev_day);
    }


    ostringstream oss;
    // why we dont have consistnacy in output is beyond me
    if (trunc(amount) != amount){
        oss << fixed << setprecision(2); // output varies based on amount
    }
    oss << "On " << date << ": Instructed to perform \"" << command
        << " $" << amount << "\"\n";


    // necessary to get the interest value before updating balance
    double interest = prev_balance > 0? 
                        interest_earned(prev_balance, apr, prev_date, date) 
                        : 0;

    oss << fixed << setprecision(2);
    if (command == "Deposit"){
        deposit(prev_balance, amount);
    } 
    
    // apply interest
    if (prev_date != ""){
        int interest_applied = 0;
        interest_applied = number_of_first_of_months(prev_date, date);

        if (interest_applied != 0){ // ie, more than 1 month has elapsed
            
            oss << "Since " << prev_date << ", interest has accrued "
                << interest_applied << " times.\n";
            oss << "$" << interest << " interest has been earned.\n";

            prev_balance += interest; // apply the interest
        }

    }
    
    if (command == "Withdraw"){
        bool overdrafted = !withdraw(prev_balance, amount);
        if (overdrafted){ // if withdraw returns false
            overdraft(prev_balance, amount); // overdraft the account
            oss << "Overdraft!\n" << "Balance: " << prev_balance << '\n';
            prev_date = date;
            return oss.str(); 
        }
    }

    // handle the first input, there will never be interest so stop here
    if (prev_date == ""){
        oss << "Balance: " << prev_balance << '\n';
        prev_date = date;
        return oss.str();
    }


    oss << "Balance: " << prev_balance << '\n';

    prev_date = date;
    return oss.str();
    
}

string process_commands(const string &inp, const double apr){
    /*
    accepts a string and an annual percentage, returns a string denoting what
    the transaction has done based on various commands. 
    */

    ostringstream out;

    string date = "";
    string line;
    double balance = 0;

    istringstream iss(inp);

    while (getline(iss, line)){
        out << process_command(line, date, balance, apr);
    }
    
    return out.str();
    
}
