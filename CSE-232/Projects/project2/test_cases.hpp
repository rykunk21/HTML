
void print_success(const int &num){
    std::cout << "All " << num << " test cases have passed" << '\n';
}

template <typename T>
void ASSERT_EQ(T arg1, T arg2){
    assert(arg1 == arg2);
}

template <typename T>
void ASSERT_DOUBLE_EQ(T arg1, T arg2){
    assert(arg1 == arg2);
}

template <typename T>
void ASSERT_NEAR(T arg1, T arg2, T arg3){
    assert((arg1 < (arg2 + arg3)) && (arg1 > (arg2 - arg3)));
}

void final_goal(){
    /*
    Don't expect to pass this until all the other test cases are working.
    */
    cout << "this test is from test cases" << '\n';
}

void test_deposit(){
    /*CXX_FLAGS -Wall -Wpedantic -Werror*/
    double balance = 13.49;
    double amount = 23.10;
    deposit(balance, amount);
    ASSERT_NEAR(balance, 36.59, 0.001);
}

void test_withdraw(){
    double balance = 13.49;
    double amount = 23.10;
    bool result = withdraw(balance, amount);
    ASSERT_NEAR(balance, 13.49, 0.001);
    ASSERT_EQ(result, false);
    balance = 33.49;
    amount = 23.10;
    result = withdraw(balance, amount);
    ASSERT_NEAR(balance, 10.39, 0.001);
    ASSERT_EQ(result, true);
}

void test_overdraft(){
    double balance = 13.49;
    double amount = 23.10;
    overdraft(balance, amount);
    ASSERT_DOUBLE_EQ(balance, -44.61);
    double balance2 = 133.45;
    double amount2 = 23.10;
    overdraft(balance2, amount2);
    ASSERT_DOUBLE_EQ(balance2, 75.35);
}

void test_interst_per_month(){
    double balance = 13.49;
    double apr = 12.0;
    double result = interest_for_month(balance, apr);
    ASSERT_NEAR(result, 0.13, 0.001);
    balance = 133.45;
    apr = 7.8;
    result = interest_for_month(balance, apr);
    ASSERT_NEAR(result, 0.86, 0.001);
    balance = 1.00;
    apr = 3;
    result = interest_for_month(balance, apr);
    ASSERT_NEAR(result, 0.00, 0.001);
}

void test_string_date_to_int_ptrs(){
    std::string date = "2015-11-30";
    int year, month, day;
    string_date_to_int_ptrs(date, &year, &month, &day);
    ASSERT_EQ(year, 2015);
    ASSERT_EQ(month, 11);
    ASSERT_EQ(day, 30);
    date = "2019-02-01";
    string_date_to_int_ptrs(date, &year, &month, &day);
    ASSERT_EQ(year, 2019);
    ASSERT_EQ(month, 2);
    ASSERT_EQ(day, 1);
}

void test_string_date_to_ints(){
    std::string date = "2015-11-30";
    int year, month, day;
    string_date_to_ints(date, year, month, day);
    ASSERT_EQ(year, 2015);
    ASSERT_EQ(month, 11);
    ASSERT_EQ(day, 30);
}

void test_number_of_first_of_months(){
    std::string date_early = "2015-05-03";
    std::string date_late = "2015-08-30";
    int result = number_of_first_of_months(date_early, date_late);
    ASSERT_EQ(result, 3);
    date_early = "2015-11-03";
    date_late = "2019-03-30";
    result = number_of_first_of_months(date_early, date_late);
    ASSERT_EQ(result, 40);
    date_early = "2015-11-03";
    date_late = "2015-11-30";
    result = number_of_first_of_months(date_early, date_late);
    ASSERT_EQ(result, 0);
    date_early = "2015-11-01";
    date_late = "2015-11-01";
    result = number_of_first_of_months(date_early, date_late);
    ASSERT_EQ(result, 0);
}

void test_interest_earned(){
    double balance = 100.00;
    double apr = 12.0;
    std::string date_early = "2015-05-03";
    std::string date_late = "2015-06-30";
    double result = interest_earned(balance, apr, date_early, date_late);
    ASSERT_DOUBLE_EQ(balance, 100.00);
    ASSERT_DOUBLE_EQ(result, 1.00);
    balance = 10.00;
    apr = 12.0;
    date_early = "2015-05-03";
    date_late = "2015-07-30";
    result = interest_earned(balance, apr, date_early, date_late);
    ASSERT_NEAR(result, 0.20, 0.001);
    balance = 1000.00;
    apr = 12.0;
    date_early = "2015-05-03";
    date_late = "2015-12-30";
    result = interest_earned(balance, apr, date_early, date_late);
    cout << result << endl;

    ASSERT_NEAR(result, 72.12, 0.001);
}

void test_process_command(){  
    std::string input = 
    "2016-09-02 Deposit $500\n"
    "2016-09-02 Withdraw $23.54\n"
    "2016-09-04 Withdraw $58\n"
    "2016-11-02 Deposit $200\n"
    "2017-03-02 Withdraw $1000\n"
    "2019-11-02 Deposit $5000\n"
    "2020-11-02 Deposit $500\n";
    std::string result = process_commands(input, 7);
    std::string expected = 
    "On 2016-09-02: Instructed to perform \"Deposit $500\"\n"
    "Balance: 500.00\n"
    "On 2016-09-02: Instructed to perform \"Withdraw $23.54\"\n"
    "Balance: 476.46\n"
    "On 2016-09-04: Instructed to perform \"Withdraw $58\"\n"
    "Balance: 418.46\n"
    "On 2016-11-02: Instructed to perform \"Deposit $200\"\n"
    "Since 2016-09-04, interest has accrued 2 times.\n"
    "$4.89 interest has been earned.\n"
    "Balance: 623.35\n"
    "On 2017-03-02: Instructed to perform \"Withdraw $1000\"\n"
    "Since 2016-11-02, interest has accrued 4 times.\n"
    "$14.65 interest has been earned.\n"
    "Overdraft!\nBalance: -397.00\n"
    "On 2019-11-02: Instructed to perform \"Deposit $5000\"\n"
    "Since 2017-03-02, interest has accrued 32 times.\n"
    "$0.00 interest has been earned.\n"
    "Balance: 4603.00\n"
    "On 2020-11-02: Instructed to perform \"Deposit $500\"\n"
    "Since 2019-11-02, interest has accrued 12 times.\n"
    "$332.69 interest has been earned.\n"
    "Balance: 5435.69\n";
    std::cout << "Expected:" << std::endl << expected << std::endl;
    std::cout << "Result:" << std::endl << result << std::endl;
    ASSERT_EQ(result, expected);
}

void tpc_deposit(){
    // DEPOSIT
    std::string line = "2015-09-03 Deposit $100";
    std::string previous_date = "2015-09-02";
    double balance = 10.00;
    double apr = 12.0;
    std::string expected = "On 2015-09-03: Instructed to perform \"Deposit $100\"\nBalance: 110.00\n";
    std::string result = process_command(line, previous_date, balance, apr);
    cout << result << endl;
    cout << expected << endl;
    ASSERT_NEAR(balance, 110.00, 0.001);
    ASSERT_EQ(result, expected);
}

void tpc_withdraw(){
    //WITHDRAW
    std::string line = "2015-09-03 Withdraw $8.50";
    std::string previous_date = "2015-09-30";
    double balance = 100.00;
    double apr = 12.0;
    std::string expected = "On 2015-09-03: Instructed to perform \"Withdraw $8.50\"\nBalance: 91.50\n";
    std::cout << "Expected: " << std::endl << expected << std::endl;
    std::string result = process_command(line, previous_date, balance, apr);
    std::cout << "Result: " << std::endl << result << std::endl;

    ASSERT_NEAR(balance, 91.50, 0.001);
    ASSERT_EQ(result, expected);
}

void tpc_overdraft(){
    std::string line = "2015-09-03 Withdraw $400.50";
    std::string previous_date = "2015-09-30";
    double balance = 100.00;
    double apr = 12.0;
    std::string expected = "On 2015-09-03: Instructed to perform \"Withdraw $400.50\"\nOverdraft!\nBalance: -335.50\n";
    std::cout << "Expected: " << std::endl << expected << std::endl;
    std::string result = process_command(line, previous_date, balance, apr);
    std::cout << "Result: " << std::endl << result << std::endl;
}

void tpc_interest(){
    std::string line = "2016-09-03 Deposit $400.50";
    std::string previous_date = "2015-09-30";
    double balance = 100.00;
    double apr = 12.0;
    std::string expected = "On 2016-09-03: Instructed to perform \"Deposit $400.50\"\nSince 2015-09-30, interest has accrued 12 times.\n$12.66 interest has been earned.\nBalance: 513.16\n";
    std::cout << "Expected: " << std::endl << expected << std::endl;
    std::string result = process_command(line, previous_date, balance, apr);
    std::cout << "Result: " << std::endl << result << std::endl;


    ASSERT_NEAR(balance, 513.16, 0.001);
    ASSERT_EQ(result, expected);
}

void tpc_nointerest(){
    std::string line = "2019-09-03 Deposit $400.50";
    std::string previous_date = "2015-09-30";
    double balance = -100.00;
    double apr = 12.0;
    std::string expected = "On 2019-09-03: Instructed to perform \"Deposit $400.50\"\nSince 2015-09-30, interest has accrued 48 times.\n$0.00 interest has been earned.\nBalance: 300.50\n";
    std::cout << "Expected: " << std::endl << expected << std::endl;
    std::string result = process_command(line, previous_date, balance, apr);
    std::cout << "Result: " << std::endl << result << std::endl;
    ASSERT_NEAR(balance, 300.50, 0.001);
    ASSERT_EQ(result, expected);
}

void tpc_no_previous_date_and_set_date(){
    std::string line = "2019-09-03 Deposit $400.50";
    std::string previous_date = "2015-09-30";
    double balance = -100.00;
    double apr = 12.0;
    process_command(line, previous_date, balance, apr);
    ASSERT_NEAR(balance, 300.50, 0.001);
    string date = "2019-09-03";
    ASSERT_EQ(previous_date, date);
    line = "2011-09-03 Deposit $400.50";
    previous_date = "";
    balance = 3450.00;
    apr = 13.0;
    process_command(line, previous_date, balance, apr);
    ASSERT_NEAR(balance, 3850.50, 0.001);
    date = "2011-09-03";
    ASSERT_EQ(previous_date, date);
}

void final_goal_sim(){
    std::string input = 
    "2016-09-02 Deposit $600\n"
    "2016-09-02 Withdraw $23.54\n"
    "2016-09-04 Withdraw $58\n"
    "2016-11-02 Deposit $200\n"
    "2017-03-02 Withdraw $1200\n"
    "2019-11-02 Deposit $1500\n"
    "2020-03-02 Withdraw $100\n"
    "2021-03-02 Deposit $100\n";
    std::string result = process_commands(input, 7);
    std::string expected = 
    "On 2016-09-02: Instructed to perform \"Deposit $600\"\n"
    "Balance: 600.00\n"
    "On 2016-09-02: Instructed to perform \"Withdraw $23.54\"\n"
    "Balance: 576.46\n"
    "On 2016-09-04: Instructed to perform \"Withdraw $58\"\n"
    "Balance: 518.46\n"
    "On 2016-11-02: Instructed to perform \"Deposit $200\"\n"
    "Since 2016-09-04, interest has accrued 2 times.\n"
    "$6.06 interest has been earned.\n"
    "Balance: 724.52\n"
    "On 2017-03-02: Instructed to perform \"Withdraw $1200\"\n"
    "Since 2016-11-02, interest has accrued 4 times.\n"
    "$17.04 interest has been earned.\n"
    "Overdraft!\n"
    "Balance: -493.44\n"
    "On 2019-11-02: Instructed to perform \"Deposit $1500\"\n"
    "Since 2017-03-02, interest has accrued 32 times.\n"
    "$0.00 interest has been earned.\n"
    "Balance: 1006.56\n"
    "On 2020-03-02: Instructed to perform \"Withdraw $100\"\n"
    "Since 2019-11-02, interest has accrued 4 times.\n"
    "$23.68 interest has been earned.\n"
    "Balance: 930.24\n"
    "On 2021-03-02: Instructed to perform \"Deposit $100\"\n"
    "Since 2020-03-02, interest has accrued 12 times.\n"
    "$67.18 interest has been earned.\nBalance: 1097.42\n";
    ASSERT_EQ(result, expected);
}
