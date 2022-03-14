#pragma once
#include <string>
class Account
{
	std::string m_Name;
	int m_AcctNo;
	static int s_ANGenerator;
protected:
	float m_Balance;
public:
	Account(const std::string &Name, float Balance);
	~Account();
	std::string GetName() const;
	float GetBalance() const;
	int GetAcctNo() const;
	float GetInterestRate() const;

	void AccumulateInterest();
	void Withdraw(float amount);
	void Deposit(float amount);
};

