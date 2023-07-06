#include "Savings_Account.h"

Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
    : Account {name, balance}, int_rate{int_rate} {
}

Savings_Account::~Savings_Account(){

}
bool Savings_Account::deposit(double amount) {
    amount += amount * (int_rate/100);
    return Account::deposit(amount);
}
bool Savings_Account::withdraw(double amount){
    if (balance-amount >=0) {
        balance-=amount;
        return true;
    } else
        return false;
}

void Savings_Account::print(std::ostream &os) const{
    os << "[Savings_Account: " << name << ": " << balance << ", " << int_rate << "]";
}

