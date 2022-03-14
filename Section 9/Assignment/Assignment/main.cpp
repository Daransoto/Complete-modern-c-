#include <iostream>
#include "Account.h"
#include "Savings.h"
#include "Checking.h"

int main() {
	/*Account acc("Bob", 1000);
	std::cout << "Initial Balance: " << acc.GetBalance() << std::endl;
	acc.Deposit(200);
	acc.Withdraw(380);
	std::cout << "Balance: " << acc.GetBalance() << std::endl;*/

	/*Savings acc("Bob", 1000, 0.5f);
	std::cout << "Initial Balance: " << acc.GetBalance() << std::endl;
	acc.Deposit(200);
	acc.AccumulateInterest();
	acc.Withdraw(380);
	std::cout << "Balance: " << acc.GetBalance() << std::endl;*/

	Checking acc("Bob", 1000);
	std::cout << "Initial Balance: " << acc.GetBalance() << std::endl;
	acc.Withdraw(980);
	std::cout << "Balance: " << acc.GetBalance() << std::endl;
	return 0;
}