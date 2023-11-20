#include "Bank.h"
Bank::Bank(const std::string& name) 
{
	bankName = name;
}
void Bank::addCustomer(const Customer& customer) 
{
	customers.push_back(customer);
}
void Bank::displayCustomerInfo(int accountNumber) const 
{
	for (int i = 0; i < customers.size(); i++) 
	{
		if (accountNumber == customers[i].getAccountNumber()) 
		{
			std::cout << "Customer Information: " << std::endl;
			std::cout << "Name: " << customers[i].getName() << std::endl; 
			std::cout << "Account Number: " << customers[i].getAccountNumber() << std::endl;
			std::cout << "Balance: " << customers[i].getAccountBalance() << std::endl;
			break;
		}
	}
}