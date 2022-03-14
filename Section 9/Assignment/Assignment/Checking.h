#pragma once
#include "Account.h"
class Checking :
    public Account
{
public:
    Checking(const std::string &name, float balance);

    void Withdraw(float amount);
};

