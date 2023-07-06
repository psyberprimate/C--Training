#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include "Account.h"

class Checking_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_ext_fee = 1.5;
protected:
    double ext_fee;
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);    
    //bool deposit(double amount); // Inherits the Savings::deposit method
    bool withdraw(double amount);
    // Inherits the Account::withdraw method
};


#endif // _CHECKING_ACCOUNT_H_