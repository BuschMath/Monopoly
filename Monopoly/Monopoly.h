#ifndef MONOPOLY_H
#define MONOPOLY_H

#define Stats

#include <vector>
#include "Dice.h"
#include "Bank.h"
#include "Board.h"
#include "Cards.h"
#include "Players.h"

const int maxPlayers = 8;

#ifdef Stats
const int totalRolls = 100000;
#endif // Stats


enum class PlayChoice
{
	roll
};

class Monopoly
{
public:
	Monopoly();

	void Play(int noPlayers_);
	virtual PlayChoice Choice();
	Space Roll(int player);
	void ActOnChance(int playerNo, Space& space);
	Space GoToSpace(int playerNo, CardOutcome outcome);

#ifdef Stats
	void frequency(Space playSpace);
	int* getFreq() { return freq; };
#endif // Stats

private:
	Board board;
	Dice* dice;
	Players players[8];
	Bank bank;
	Cards* chance;
	Cards* community_chest;
	int noPlayers;
	bool noVictory;

#ifdef Stats
	int freq[10];
	int rollCount;
#endif // Stats

};

#endif // !MONOPOLY_H