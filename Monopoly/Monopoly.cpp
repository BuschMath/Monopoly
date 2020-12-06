#include "Monopoly.h"

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

	switch (temp.action)
	{
	case CardAction::GoTo: space = GoToSpace(playerNo, temp.outcome);
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

Space Monopoly::GoToSpace(int playerNo, CardOutcome outcome)
{
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
	case CardOutcome::Utility:
		break;
	case CardOutcome::Railroad:
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

	if (rollCount > totalRolls)
		noVictory = false;
}
#endif // Stats