#include "Board.h"

Board::Board()
{
	board[0] = SetSpace(DeedName::NameError, Owner::Bank, SpaceType::Go);
	
	for (int i = 0; i < 8; i++)
	{
		playerLocation[i] = 0;
	}

	board[1] = SetProperty(DeedName::MediterraneanAvenue);
	board[2] = SetCard(SpaceType::CommunityChest);
	board[3] = SetProperty(DeedName::BalticAvenue);
	board[4] = SetCard(SpaceType::IncomeTax);
	board[5] = SetProperty(DeedName::ReadingRailroad);
	board[6] = SetProperty(DeedName::OrientalAvenue);
	board[7] = SetCard(SpaceType::Chance);
	board[8] = SetProperty(DeedName::VermontAvenue);
	board[9] = SetProperty(DeedName::ConnecticutAvenue);
	board[10] = SetCard(SpaceType::JustVisiting);
	board[11] = SetCard(SpaceType::Jail);
	board[12] = SetProperty(DeedName::StCharlesPlace);
	board[13] = SetProperty(DeedName::Electric);
	board[14] = SetProperty(DeedName::StatesAvenue);
	board[15] = SetProperty(DeedName::VirginiaAvenue);
	board[16] = SetProperty(DeedName::PennsylvaniaRailroad);
	board[17] = SetProperty(DeedName::StJamesPlace);
	board[18] = SetCard(SpaceType::CommunityChest);
	board[19] = SetProperty(DeedName::TennesseeAvenue);
	board[20] = SetProperty(DeedName::NewYorkAvenue);
	board[21] = SetCard(SpaceType::FreeParking);
	board[22] = SetProperty(DeedName::KentuckyAvenue);
	board[23] = SetCard(SpaceType::Chance);
	board[24] = SetProperty(DeedName::IndianaAvenue);
	board[25] = SetProperty(DeedName::IllinoisAvenue);
	board[26] = SetProperty(DeedName::BORailroad);
	board[27] = SetProperty(DeedName::AtlanticAvenue);
	board[28] = SetProperty(DeedName::VentnorAvenue);
	board[29] = SetProperty(DeedName::Water);
	board[30] = SetProperty(DeedName::MarvinGardens);
	board[31] = SetCard(SpaceType::GoToJail);
	board[32] = SetProperty(DeedName::PacificAvenue);
	board[33] = SetProperty(DeedName::NorthCarolinaAvenue);
	board[34] = SetCard(SpaceType::CommunityChest);
	board[35] = SetProperty(DeedName::PennsylvaniaAvenue);
	board[36] = SetProperty(DeedName::ShortLine);
	board[37] = SetCard(SpaceType::Chance);
	board[38] = SetProperty(DeedName::ParkPlace);
	board[39] = SetCard(SpaceType::LuxuryTax);
	board[40] = SetProperty(DeedName::Boardwalk);
}

Board::~Board()
{
}

Space Board::SetSpace(DeedName deed, Owner owner, SpaceType type)
{
	Space temp;
	temp.info.SetDeed(deed);
	temp.owner = owner;
	temp.type = type;


	return temp;
}

Space Board::Roll(int playerNo, int rollTotal)
{
	if(playerLocation[playerNo] + rollTotal <= totalBoardSpaces - 1)
		playerLocation[playerNo] += rollTotal;
	else
	{
		playerLocation[playerNo] = playerLocation[playerNo] + rollTotal - totalBoardSpaces;
	}

	if (playerLocation[playerNo] == jailLoc)
		playerLocation[playerNo]++;

	if (playerLocation[playerNo] == goToJailLoc)
		playerLocation[playerNo] = jailLoc;
	
	return GetSpace(playerLocation[playerNo]);
}

void Board::SetPlayerLoc(int playerNo, int loc)
{
	playerLocation[playerNo] = loc;
}

Space Board::SetProperty(DeedName deed)
{
	return SetSpace(deed, Owner::Bank, SpaceType::Property);
}

Space Board::SetCard(SpaceType type)
{
	return SetSpace(DeedName::NameError, Owner::Bank, type);
}