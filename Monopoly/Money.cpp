#include "Money.h"

Money::Money()
{
	total = 0;
	noOnes = 0;
	noFives = 0;
	noTens = 0;
	noTwenties = 0;
	noFifties = 0;
	noHundreds = 0;
	noFiveHundreds = 0;
}

void Money::SetupBank()
{
	total = 20580;
	noOnes = 30;
	noFives = 30;
	noTens = 30;
	noTwenties = 30;
	noFifties = 30;
	noHundreds = 30;
	noFiveHundreds = 30;
}

bool Money::Give(int ones, int fives, int tens, int twenties, int fifties, int hundreds, int fiveHundreds)
{
	int trans = (ones + 5 * fives + 10 * tens + 20 * twenties + 50 * fifties + 100 * hundreds +
		500 * fiveHundreds);

	if (total - trans >= 0 && noOnes - ones >= 0 && noFives - fives >= 0 && noTens - tens >= 0 &&
		noTwenties - twenties >= 0 && noFifties - fifties >= 0 && noHundreds - hundreds >= 0 &&
		noFiveHundreds - fiveHundreds >= 0)
	{
		total -= trans;

		noOnes -= ones;
		noFives -= fives;
		noTens -= tens;
		noTwenties -= twenties;
		noFifties -= fifties;
		noHundreds -= hundreds;
		noFiveHundreds -= fiveHundreds;

		return true;
	}
	else
		return false;
}

void Money::Get(int ones, int fives, int tens, int twenties, int fifties, int hundreds, int fiveHundreds)
{
	int trans = (ones + 5 * fives + 10 * tens + 20 * twenties + 50 * fifties + 100 * hundreds +
		500 * fiveHundreds);

	total += trans;

	noOnes += ones;
	noFives += fives;
	noTens += tens;
	noTwenties += twenties;
	noFifties += fifties;
	noHundreds += hundreds;
	noFiveHundreds += fiveHundreds;
}
