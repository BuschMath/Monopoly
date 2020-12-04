#ifndef CARDS_H
#define CARDS_H

#include <string>
#include <stack>

const int deckSize = 17;

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
	BackThree,
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
	std::string text = "";
	CardAction action = CardAction::GoTo;
	CardOutcome outcome = CardOutcome::Jail;
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
	std::stack<Card> deck;
	Card rList[deckSize];
	CardType type;
	int listSize;

	void SetChance();
	void SetCommunityChest();
	void SetError();
	void SetListCard(std::string text, CardAction action, CardOutcome outcome);
};

#endif // !CARDS_H

