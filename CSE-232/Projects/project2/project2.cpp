#include "bank_account.hpp"
#include "test_cases.hpp"

int main(){

    test_deposit();
    test_withdraw();
    test_overdraft();
    test_string_date_to_int_ptrs();
    test_string_date_to_ints();
    test_number_of_first_of_months();
    test_interst_per_month();
    tpc_deposit();
    tpc_withdraw();
    tpc_overdraft();
    tpc_interest();
    tpc_nointerest();
    tpc_no_previous_date_and_set_date();
    test_process_command();
    final_goal_sim();
    print_success(15);
    return 0;
}