#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
#include <iostream>


class Account{
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
    protected:
        double balance;
        std::string name;
    public:
        
        //std::string name; 
        void deposit(double amount);
        void withdraw(double amount);
        Account();
        Account(double balance);
        ~Account();
};
#endif // _ACCOUNT_H_