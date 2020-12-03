#include "Cards.h"
#include <cstdlib>
#include <time.h>

Cards::Cards(CardType type_)
{
	type = type_;
	srand(time(NULL));

	switch (type)
	{
	case CardType::Chance:	SetChance();
		break;
	case CardType::CommunityChest:	SetCommunityChest();
		break;
	default:	SetError();
		break;
	}
}

Cards::~Cards()
{
}

void Cards::Shuffle()
{
	Card item;
	bool Success = false;
	int num = 0;

	while (list.ListLength() != 0)
	{
		num = rand() % list.ListLength() + 1;
		list.ListRetrieve(num, item, Success);
		stack.Push(item);
		list.ListDelete(num, Success);
	}
}

Card Cards::Draw()
{
	if (stack.IsEmpty() == true)
		Shuffle();

	Card item;
	stack.Pop(item);

	bool temp;
	list.ListInsert(list.ListLength() + 1, item, temp);

	return item;
}

void Cards::SetChance()
{
	SetListCard("Advance to \"Go.\" Collect $200.", CardAction::GoTo, CardOutcome::Go);
	SetListCard("Advance to Illinois Ave. If you pass Go, collect $200.", CardAction::GoTo, CardOutcome::IllinoisAve);
	SetListCard("Advance to St. Charles Place. If you pass Go, collect $200.", CardAction::GoTo, CardOutcome::StCharlesPlace);
	SetListCard("Advance token to nearest Utility. If unowned, you may buy it from the Bank. If owned, throw dice and pay owner "
		"a total ten times the amount thrown.", CardAction::GoTo, CardOutcome::Utility);
	SetListCard("Advance token to the nearest Railroad and pay owner twice the rental to which he/she is otherwise entitled."
		" If Railroad is unowned, you may buy it from the Bank.", CardAction::GoTo, CardOutcome::Railroad);

	SetListCard("Advance token to the nearest Railroad and pay owner twice the rental to which he/she is otherwise entitled."
		" If Railroad is unowned, you may buy it from the Bank.", CardAction::GoTo, CardOutcome::Railroad);
	SetListCard("Bank pays you dividend of $50.", CardAction::Get, CardOutcome::GetAllFifty);
	SetListCard("Get out of Jail Free. This card may be kept until needed, or traded/sold.", CardAction::GetOutOfJailFree, 
		CardOutcome::GetOutOfJailFree);
	SetListCard("Go Back Three Spaces.", CardAction::GoTo, CardOutcome::BackThree);
	SetListCard("Go to Jail. Go directly to Jail. Do not pass GO, do not collect $200.", CardAction::GoTo, CardOutcome::Jail);

	SetListCard("Make general repairs on all your property: For each house pay $25, For each hotel pay $100.", CardAction::Pay,
		CardOutcome::GeneralRepairs);
	SetListCard("Pay poor tax of $15.", CardAction::Pay, CardOutcome::PayFifteen);
	SetListCard("Take a trip to Reading Railroad. If you pass Go, collect $200.", CardAction::GoTo, CardOutcome::ReadingRailroad);
	SetListCard("Take a walk on the Boardwalk. Advance token to Boardwalk.", CardAction::GoTo, CardOutcome::Boardwalk);
	SetListCard("You have been elected Chairman of the Board. Pay each player $50.", CardAction::Pay, CardOutcome::PayAllFifty);

	SetListCard("Your building loan matures. Receive $150.", CardAction::Get, CardOutcome::GetOneHundredFifty);
	SetListCard("You have won a crossword competition. Collect $100.", CardAction::Get, CardOutcome::GetOneHundred);

	Shuffle();
}

void Cards::SetCommunityChest()
{
	SetListCard("Advance to \"Go\". Collect $200", CardAction::GoTo, CardOutcome::Go);
	SetListCard("Bank error in your favor. Collect $200.", CardAction::Get, CardOutcome::GetTwoHundred);
	SetListCard("Doctor's fees. Pay $50.", CardAction::Pay, CardOutcome::PayFifty);
	SetListCard("From sale of stock you get $50.", CardAction::Get, CardOutcome::GetFifty);
	SetListCard("Get Out of Jail Free. This card may be kept until needed or sold/traded.", CardAction::GetOutOfJailFree, 
		CardOutcome::GetOutOfJailFree);

	SetListCard("Go to Jail. Go directly to jail. Do not pass Go, Do not collect $200.", CardAction::GoTo, CardOutcome::Jail);
	SetListCard("Grand Opera Night. Collect $50 from every player for opening night seats.", CardAction::Get, 
		CardOutcome::GetAllFifty);
	SetListCard("Holiday Fund matures. Receive $100.", CardAction::Get, CardOutcome::GetOneHundred);
	SetListCard("Income tax refund. Collect $20.", CardAction::Get, CardOutcome::GetTwenty);
	SetListCard("It is your birthday. Collect $10 from every player.", CardAction::Get, CardOutcome::GetAllTen);

	SetListCard("Life insurance matures, Collect $100.", CardAction::Get, CardOutcome::GetOneHundred);
	SetListCard("Hospital Fees. Pay $50.", CardAction::Pay, CardOutcome::PayFifty);
	SetListCard("School fees. Pay $50.", CardAction::Pay, CardOutcome::PayFifteen);
	SetListCard("Receive $25 consultancy fee.", CardAction::Get, CardOutcome::GetTwentyFive);
	SetListCard("You are assessed for street repairs: Pay $40 per house and $115 per hotel you own.", CardAction::Pay, 
		CardOutcome::StreetRepairs);

	SetListCard("You have won second prize in a beauty contest. Collect $10.", CardAction::Get, CardOutcome::GetTen);
	SetListCard("You inherit $100.", CardAction::Get, CardOutcome::GetOneHundred);

	Shuffle();
}

void Cards::SetError()
{
	SetListCard("ErrorCard", CardAction::GoTo, CardOutcome::Jail);
}

void Cards::SetListCard(std::string text, CardAction action, CardOutcome outcome)
{
	bool Success = false;
	list.ListInsert(list.ListLength() + 1, Card{ text, action, outcome }, Success);
}