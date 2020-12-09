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
const long long totalRolls = 32000000000;
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
	void ActOnCommunityChest(int player, Space& playSpace);
	Space GoToSpace(int playerNo, CardOutcome outcome);

#ifdef Stats
	void frequency(Space playSpace);
	int* getFreq() { return freq; };
	int* getFreqProp() { return freqProp; };
#endif // Stats

private:
	Board board;
	Dice* dice;
	Players players[maxPlayers];
	Bank bank;
	Cards* chance;
	Cards* community_chest;
	int noPlayers;
	bool noVictory;

	void CardAction(Card card, Space& space, int playerNo);
	int NearestRailroad(int playerNo);
	int NearestUtility(int playerNo);

#ifdef Stats
	int freq[10];
	int freqProp[29];
	long long rollCount;
#endif // Stats

};

#endif // !MONOPOLY_H