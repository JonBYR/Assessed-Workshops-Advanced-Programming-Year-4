#pragma once
class Account 
{
private:
    int accountNumber;
    double balance;

public:
    Account(int accountNum);
    int getAccountNumber() const;
    double getBalance() const;
    void deposit(double amount);
    void withdraw(double amount);
};

