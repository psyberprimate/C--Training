#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "Account.h"

class Savings_Account: public Account{
    friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);
    protected:
        double int_rate;
    public:
        Savings_Account();
        Savings_Account(double balance, double int_rate);
        ~Savings_Account();
        void deposit(double amount);
        //void withdraw(double amount); Widraw is inherited
};

#endif //_SAVINGS_ACCOUNT_H_