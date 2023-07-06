#ifndef __INSUFFICIENT_FUNDS_EXCEPTION_H_
#define __INSUFFICIENT_FUNDS_EXCEPTION_H_

class InsufficientFundsException : public std::exception
{
public:
    InsufficientFundsException() noexcept = default;
    ~InsufficientFundsException() = default;
    virtual const char* what() const noexcept {
        return "Balance too low for witdrawal";
    }
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__