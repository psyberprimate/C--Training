#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance ) : Account{name, balance} {

}

bool Checking_Account::withdraw(double amount){
    amount += ext_fee;
    //Savings_Account f;
    return Account::withdraw(amount);//f.withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account){
    os << "[Checking Account: " << account.name << ": " << account.balance << ", " << "]";
    return os;
}
