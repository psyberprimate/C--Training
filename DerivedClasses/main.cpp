#include <iostream>
#include "Account.h"
#include "Savings_Account.h"

int main(){

    std::cout << "\n========== Account ==============================" << std::endl;
    Account acc{};
    acc.deposit(2000);
    acc.withdraw(500);
    std::cout << acc << std::endl;
    std::cout << std::endl;

    Account *p_acc {nullptr};
    p_acc = new Account();
    p_acc -> deposit(1000);
    p_acc -> withdraw(500);
    std::cout << &p_acc << std::endl;
    delete p_acc;

    //Savings account class

    std::cout << "\n========== Savings Account ======================" << std::endl;
    Savings_Account sav_acc{};
    sav_acc.deposit(2000);
    sav_acc.withdraw(500);
    sav_acc.withdraw(2000);
    std::cout << sav_acc << std::endl;

    std::cout << std::endl;

    Savings_Account *p_sav_acc{nullptr};
    p_sav_acc = new Savings_Account();
    p_sav_acc ->deposit(1000);
    p_sav_acc-> withdraw(500);
    std::cout << &p_sav_acc << std::endl;
    delete p_sav_acc;

    std::cout << "\n========== Ended=================================" << std::endl;
    return 0;
}