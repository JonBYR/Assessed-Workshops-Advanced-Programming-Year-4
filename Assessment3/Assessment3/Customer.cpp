#include "Customer.h"
Customer::Customer(const std::string& n, int accountNumber) : account(Account(accountNumber))
{
	name = n;
}
int Customer::getAccountNumber() const 
{
	return account.getAccountNumber();
}
double Customer::getAccountBalance() const 
{
	return account.getBalance();
}
void Customer::deposit(double amount) 
{
	std::cout << "Depositing " << amount << " into " << name << " account" << std::endl;
	account.deposit(amount);
}
void Customer::withdraw(double amount) 
{
	std::cout << "Withdrawing " << amount << " into " << name << " account" << std::endl;
	if (account.getBalance() - amount <= 0) 
	{
		return;
	}
	account.withdraw(amount);
}
std::string Customer::getName() const 
{
	return name;
}