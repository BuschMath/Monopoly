#ifndef MONOPOLY_H
#define MONOPOLY_H

#include <vector>
#include "Dice.h"
#include "Bank.h"
#include "Board.h"

class Monopoly
{
public:

private:
	Board board;
	Dice dice;
	Pieces pieces;
	Players[8] players;
	Bank bank;
	Cards chance;
	Cards community_chest;
};

#endif // !MONOPOLY_H