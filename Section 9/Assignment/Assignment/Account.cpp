#include "Account.h"
#include <iostream>

int Account::s_ANGenerator = 1000;

Account::Account(const std::string& Name, float Balance): m_Name(Name), m_Balance(Balance)
{
	m_AcctNo = ++s_ANGenerator;
}

Account::~Account()
{
}

std::string Account::GetName() const
{
	return m_Name;
}

float Account::GetBalance() const
{
	return m_Balance;
}

int Account::GetAcctNo() const
{
	return m_AcctNo;
}

float Account::GetInterestRate() const
{
	return 0.0f;
}

void Account::AccumulateInterest()
{
}

void Account::Withdraw(float amount)
{
	if (amount < m_Balance)
		m_Balance -= amount;
	else
		std::cout << "Insufficient Balance" << std::endl;
}

void Account::Deposit(float amount)
{
	m_Balance += amount;
}
