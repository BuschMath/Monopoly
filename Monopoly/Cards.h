#ifndef CARDS_H
#define CARDS_H

#include <string>

enum class CardAction
{
	GoTo,
	Get,
	GetOutOfJailFree,
	Pay
};

enum class CardOutcome
{
	Go,
	IllinoisAve,
	StCharlesPlace,
	Utility,
	Railroad,
	ReadingRailroad,
	Boardwalk,
	Jail,
	GetOutOfJailFree,
	GetFifty,
	GetOneHundredFifty,
	GetOneHundred,
	GetTwoHundred,
	GetAllFifty,
	GetAllTen,
	GetTwenty,
	GetTwentyFive,
	GetTen,
	GeneralRepairs,
	StreetRepairs,
	PayFifteen,
	PayAllFifty,
	PayFifty
};

struct Card
{
	std::string text;
	CardAction action;
	CardOutcome outcome;
};

enum class CardType
{
	Chance,
	CommunityChest,
	ErrorCardType
};

class Cards
{
public:
	Cards(CardType type_);
	~Cards();

	void Shuffle();
	Card Draw();

private:
	Card cards[17];
	CardType type;
	int loc;

	void SetChance();
	void SetCommunityChest();
	void SetError();
};

#endif // !CARDS_H

