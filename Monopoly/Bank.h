#ifndef BANK_H
#define BANK_H

#include "Money.h"
#include "Properties.h"

class Bank
{
public:
	Bank();

private:
	Money money;
	Properties properties;
	int houses;
	int hotels;

	void SetupProperties();
};

#endif // !BANK_H
