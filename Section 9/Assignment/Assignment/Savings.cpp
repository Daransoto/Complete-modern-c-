#include "Savings.h"

Savings::Savings(const std::string &Name, float Balance, float Rate): Account(Name, Balance), m_Rate(Rate)
{
}

Savings::~Savings()
{
}

float Savings::GetInterestRate() const
{
	return m_Rate;
}

void Savings::AccumulateInterest()
{
	m_Balance += (m_Balance * m_Rate);
}
