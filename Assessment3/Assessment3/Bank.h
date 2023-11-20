#pragma once
#include <vector>
#include <string>
#include "Customer.h"
#include <iostream>
class Bank
{
private:
    std::string bankName;
    std::vector<Customer> customers;

public:
    Bank(const std::string& name);
    void addCustomer(const Customer& customer);
    void displayCustomerInfo(int accountNumber) const;
};

