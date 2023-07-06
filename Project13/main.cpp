#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    // test your code here
    std::unique_ptr<Account> acc1;
    std::unique_ptr<Account> acc2;

    try{
        acc1 = std::make_unique<Checking_Account> ("Account1", 100);
        std::cout << *acc1 << std::endl;
        acc2 = std::make_unique<Checking_Account> ("Account2", -100);


    }
    catch(const IllegalBalanceException &ex){
        std::cerr << ex.what() << std::endl;
    }
    try{
        std::unique_ptr<Account> acc3 = std::make_unique<Checking_Account> ("Account2", -100);

        acc1->withdraw(200);
        std::cout << *acc2 << std::endl;
        std::cout << *acc1 << std::endl;
        acc1->withdraw(150);
    }
    catch(const IllegalBalanceException &ex){
        std::cerr << ex.what() << std::endl;
    }
    catch(const InsufficientFundsException &ex){
        std::cerr << ex.what() << std::endl;
    }
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

