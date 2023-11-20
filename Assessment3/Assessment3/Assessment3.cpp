// Assessment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
#include "Bank.h"
#include "Customer.h"
int main()
{
    // Create Bank object
    Bank bank("XYZ Bank");

    // Create Customer objects and add them to the bank
    Customer alice("Alice", 12345);
    Customer bob("Bob", 67890);
    alice.deposit(1000);
    bob.deposit(1000);
    bob.withdraw(300);
    bank.addCustomer(alice);
    bank.addCustomer(bob);
    bank.displayCustomerInfo(12345);
    bank.displayCustomerInfo(67890);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
