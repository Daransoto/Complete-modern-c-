#pragma once
#include "Account.h"
class Savings :
    public Account
{
    float m_Rate;
public:
    Savings(const std::string& Name, float Balance, float Rate);
    ~Savings();

    float GetInterestRate() const;

    void AccumulateInterest();
};

