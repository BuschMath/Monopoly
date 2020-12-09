#include "Monopoly.h"

#ifdef Stats
#include <iostream>
#endif

Monopoly::Monopoly()
{
	std::vector<int> numSides = { 6, 6 };

	dice = new Dice(2, numSides);

	chance = new Cards(CardType::Chance);
	community_chest = new Cards(CardType::CommunityChest);

	for (int i = 0; i < maxPlayers; i++)
	{
		players[i].SetPlayerNo((PlayerNo)(i));
	}

	noPlayers = 0;
	noVictory = true;

#ifdef Stats
	rollCount = 0;

	for (int i = 0; i < 10; i++)
	{
		freq[i] = 0;
	}

	for (int i = 0; i < 29; i++)
	{
		freqProp[i] = 0;
	}
#endif // Stats

}

void Monopoly::Play(int noPlayers_)
{
	noPlayers = noPlayers_;

	PlayChoice choice;
	Space playSpace;

	do
	{
		for (int player = 0; player < noPlayers; player++)
		{
			choice = Choice();

			switch (choice)
			{
			case PlayChoice::roll: playSpace = Roll(player);
			}

			switch (playSpace.type)
			{
			case SpaceType::Chance: ActOnChance(player, playSpace);
				break;
			case SpaceType::CommunityChest: ActOnCommunityChest(player, playSpace);
			default:
				break;
			}

#ifdef Stats
			frequency(playSpace);
#endif // Stats

		}
	} while (noVictory);
}

PlayChoice Monopoly::Choice()
{
	return PlayChoice::roll;
}

Space Monopoly::Roll(int player)
{
	std::vector<int> roll = dice->Roll();

	int total = roll[0] + roll[1];

	return board.Roll(player, total);
}

void Monopoly::ActOnChance(int playerNo, Space& space)
{
	Card temp = chance->Draw();

	CardAction(temp, space, playerNo);
}

void Monopoly::ActOnCommunityChest(int player, Space& playSpace)
{
	Card temp = community_chest->Draw();

	CardAction(temp, playSpace, player);
}

Space Monopoly::GoToSpace(int playerNo, CardOutcome outcome)
{
	int tempLoc = 0;
	switch (outcome)
	{
	case CardOutcome::Go: board.SetPlayerLoc(playerNo, go);
		return board.GetSpace(go);
		break;
	case CardOutcome::IllinoisAve: board.SetPlayerLoc(playerNo, gotoIllinoisAvenue);
		return board.GetSpace(gotoIllinoisAvenue);
		break;
	case CardOutcome::StCharlesPlace: board.SetPlayerLoc(playerNo, gotoStCharlesPlace);
		return board.GetSpace(gotoStCharlesPlace);
		break;
	case CardOutcome::Utility: tempLoc = NearestUtility(playerNo);
		board.SetPlayerLoc(playerNo, tempLoc);
		return board.GetSpace(tempLoc);
		break;
	case CardOutcome::Railroad: tempLoc = NearestRailroad(playerNo);
		board.SetPlayerLoc(playerNo, tempLoc);
		return board.GetSpace(tempLoc);
		break;
	case CardOutcome::ReadingRailroad: board.SetPlayerLoc(playerNo, gotoReadingRailroad);
		return board.GetSpace(gotoReadingRailroad);
		break;
	case CardOutcome::Boardwalk: board.SetPlayerLoc(playerNo, gotoBoardwalk);
		return board.GetSpace(gotoBoardwalk);
		break;
	case CardOutcome::Jail: board.SetPlayerLoc(playerNo, jailLoc);
		return board.GetSpace(jailLoc);
		break;
	case CardOutcome::BackThree: board.SetPlayerLoc(playerNo, board.getPlayerLoc(playerNo) - 3);
		return board.GetSpace(board.getPlayerLoc(playerNo));
		break;
	default:
		break;
	}
	return Space();
}

void Monopoly::CardAction(Card card, Space& space, int playerNo)
{
	switch (card.action)
	{
	case CardAction::GoTo: space = GoToSpace(playerNo, card.outcome);
		break;
	case CardAction::Get:
		break;
	case CardAction::Pay:
		break;
	case CardAction::GetOutOfJailFree:
		break;
	default:
		break;
	}
}
int Monopoly::NearestRailroad(int playerNo)
{
	int loc = board.getPlayerLoc(playerNo);

	if (loc > gotoReadingRailroad && loc < gotoPennsylvaniaRailroad)
		return gotoPennsylvaniaRailroad;
	else if (loc > gotoPennsylvaniaRailroad && loc < gotoBORailroad)
		return gotoBORailroad;
	else if (loc > gotoBORailroad && loc < gotoShortLine)
		return gotoShortLine;
	else
		return gotoReadingRailroad;

}
int Monopoly::NearestUtility(int playerNo)
{
	int loc = board.getPlayerLoc(playerNo);

	if (loc > gotoElectric && loc < gotoWater)
		return gotoWater;
	else
		return gotoElectric;
}

#ifdef Stats
void Monopoly::frequency(Space playSpace)
{
	rollCount++;

	switch (playSpace.type)
	{
	case SpaceType::Property: freq[0]++;
		break;
	case SpaceType::Chance: freq[1]++;
		break;
	case SpaceType::CommunityChest: freq[2]++;
		break;
	case SpaceType::IncomeTax: freq[3]++;
		break;
	case SpaceType::LuxuryTax: freq[4]++;
		break;
	case SpaceType::JustVisiting: freq[5]++;
		break;
	case SpaceType::Jail: freq[6]++;
		break;
	case SpaceType::GoToJail: freq[7]++;
		break;
	case SpaceType::FreeParking: freq[8]++;
		break;
	case SpaceType::Go: freq[9]++;
		break;
	default:
		break;
	}

	DeedName name = playSpace.info.GetDName();

	switch (name)
	{
	case DeedName::MediterraneanAvenue: freqProp[0]++;
		break;
	case DeedName::BalticAvenue: freqProp[1]++;
		break;
	case DeedName::OrientalAvenue: freqProp[2]++;
		break;
	case DeedName::VermontAvenue: freqProp[3]++;
		break;
	case DeedName::ConnecticutAvenue: freqProp[4]++;
		break;
	case DeedName::StCharlesPlace: freqProp[5]++;
		break;
	case DeedName::StatesAvenue: freqProp[6]++;
		break;
	case DeedName::VirginiaAvenue: freqProp[7]++;
		break;
	case DeedName::StJamesPlace: freqProp[8]++;
		break;
	case DeedName::TennesseeAvenue: freqProp[9]++;
		break;
	case DeedName::NewYorkAvenue: freqProp[10]++;
		break;
	case DeedName::KentuckyAvenue: freqProp[11]++;
		break;
	case DeedName::IndianaAvenue: freqProp[12]++;
		break;
	case DeedName::IllinoisAvenue: freqProp[13]++;
		break;
	case DeedName::AtlanticAvenue: freqProp[14]++;
		break;
	case DeedName::VentnorAvenue: freqProp[15]++;
		break;
	case DeedName::MarvinGardens: freqProp[16]++;
		break;
	case DeedName::PacificAvenue: freqProp[17]++;
		break;
	case DeedName::NorthCarolinaAvenue: freqProp[18]++;
		break;
	case DeedName::PennsylvaniaAvenue: freqProp[19]++;
		break;
	case DeedName::ParkPlace: freqProp[20]++;
		break;
	case DeedName::Boardwalk: freqProp[21]++;
		break;
	case DeedName::ReadingRailroad: freqProp[22]++;
		break;
	case DeedName::PennsylvaniaRailroad: freqProp[23]++;
		break;
	case DeedName::BORailroad: freqProp[24]++;
		break;
	case DeedName::ShortLine: freqProp[25]++;
		break;
	case DeedName::Electric: freqProp[26]++;
		break;
	case DeedName::Water: freqProp[27]++;
		break;
	case DeedName::NameError: freqProp[28]++;
		break;
	default:
		break;
	}

	if (rollCount % 100000000 == 0)
		std::cout << 100 * float(rollCount) / float(totalRolls) << "% Complete\n";

	if (rollCount >= totalRolls)
		noVictory = false;
}
#endif // Stats