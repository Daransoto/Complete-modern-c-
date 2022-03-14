#include "Checking.h"
#include <iostream>

Checking::Checking(const std::string& name, float balance): Account(name, balance) {

}

void Checking::Withdraw(float amount)
{
	if (amount < m_Balance - 50)
		m_Balance -= amount;
	else
		std::cout << "Insufficient Balance" << std::endl;
}
