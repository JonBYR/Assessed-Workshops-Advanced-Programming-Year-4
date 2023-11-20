#pragma once
#include "Account.h"
#include <string>
#include <iostream>
class Customer
{
private:
    std::string name;
    Account account;

public:
    Customer(const std::string& n, int accountNumber);
    std::string getName() const;
    int getAccountNumber() const;
    double getAccountBalance() const;
    void deposit(double amount);
    void withdraw(double amount);
};

