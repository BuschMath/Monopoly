#ifndef DICE_H
#define DICE_H

// Rolling multiple die

#include "Die.h"
#include <vector>

class Dice
{
public:
	Dice(int numberOfDie, std::vector<int> numberOfSides);
	std::vector<int>  Roll();

private:
	std::vector<Die> dice;
};

#endif // !DICE_H
