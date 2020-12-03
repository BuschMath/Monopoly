#include "Cards.h"

Cards::Cards(CardType type_)
{
	loc = 0;
	type = type_;

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
}

Card Cards::Draw()
{
	return cards[loc++];
}

void Cards::SetChance()
{
}

void Cards::SetCommunityChest()
{
}

void Cards::SetError()
{
}
