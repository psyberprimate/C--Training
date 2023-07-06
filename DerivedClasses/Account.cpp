#include <iostream>
#include "Account.h"


Account::Account() :Account(0.0){

}
Account::Account(double balance): balance{balance}, name{"Account X"}{

}

Account::~Account(){

}
void Account::deposit(double amount){
    std::cout << "Account deposited called with " << amount << std::endl;
    balance += amount;
}
void Account::withdraw(double amount){
    std::cout << "Account widraw called with " << amount << std::endl;
    if(balance-amount >= 0){
        balance-=amount;
        std::cout << "Account widraw succesful for: " << amount << std::endl;
    }
    else{
        std::cout << "Insufficient funds for the deposit" << std::endl;
    }
}
std::ostream &operator<<(std::ostream &os, const Account &account){
    os << "Account balance: " << account.balance;
    return os;
}



