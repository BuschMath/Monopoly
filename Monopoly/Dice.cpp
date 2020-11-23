#include "Dice.h"

Dice::Dice(int numberOfDie, std::vector<int> numberOfSides)
{
	for (int i = 0; i < numberOfDie; i++)
	{
		dice.push_back(Die(numberOfSides[i]));
	}
}

std::vector<int> Dice::Roll()
{
	std::vector<int> outcome;
	for (int i = 0; i < dice.size(); i++)
		outcome.push_back(dice[i].Roll());

	return outcome;
}
