#ifndef MONEY_H
#define MONEY_H

class Money
{
public:
	Money();

	void SetupBank();
	bool Give(int ones, int fives, int tens, int twenties, int fifties, int hundreds, int fiveHundreds);
	void Get(int ones, int fives, int tens, int twenties, int fifties, int hundreds, int fiveHundreds);
	int CountTotal() { return total; };
	int CountOnes() { return noOnes; };
	int CountFives() { return noFives; };
	int CountTens() { return noTens; };
	int CountTwenties() { return noTwenties; };
	int CountFifties() { return noFifties; };
	int CountHundreds() { return noHundreds; };
	int CountFiveHundreds() { return noFiveHundreds; };

private:
	int total;
	int noOnes;
	int noFives;
	int noTens;
	int noTwenties;
	int noFifties;
	int noHundreds;
	int noFiveHundreds;
};

#endif // !MONEY_H

