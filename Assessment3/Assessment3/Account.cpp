#include "Account.h"
Account::Account(int accountNum) 
{
	accountNumber = accountNum;
	balance = 0;
}
int Account::getAccountNumber() const 
{
	return accountNumber;
}
double Account::getBalance() const 
{
	return balance;
}
void Account::deposit(double amount) 
{
	balance += amount;
}
void Account::withdraw(double amount) 
{
	balance -= amount;
}