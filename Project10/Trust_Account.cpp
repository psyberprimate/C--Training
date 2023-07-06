#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate) : Savings_Account{name, balance, int_rate}, withdraw_count{0} {

}

bool Trust_Account::deposit(double amount){
    if(amount >= 5000){
        amount += 50;
        std::cout << "Deposit is over 5000, 50 credits added as reward to account: " << std::endl;
    }
    return Savings_Account::deposit(amount);
}
bool Trust_Account::withdraw(double amount){
    if((amount < balance*0.2) || withdraw_count >= 3){
        return false;
    }
    else{
        withdraw_count++;
        return Savings_Account::withdraw(amount);
    }
    
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account){
    os << "[Trust Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%, withdrawals: "<< account.withdraw_count <<  "]";
    return os;
}