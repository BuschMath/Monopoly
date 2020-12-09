#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "Properties.h"

const int totalBoardSpaces = 41;
const int jailLoc = 11;
const int goToJailLoc = 31;
const int go = 0;
const int gotoBoardwalk = 40;
const int gotoIllinoisAvenue = 25;
const int gotoStCharlesPlace = 12;
const int gotoElectric = 13;
const int gotoWater = 29;
const int gotoReadingRailroad = 5;
const int gotoPennsylvaniaRailroad = 16;
const int gotoBORailroad = 26;
const int gotoShortLine = 36;

enum class Owner
{
	Bank,
	Player1,
	Player2,
	Player3,
	Player4,
	Player5,
	Player6,
	Player7,
	Player8
};

enum class SpaceType
{
	Property,
	Chance,
	CommunityChest,
	IncomeTax,
	LuxuryTax,
	JustVisiting,
	Jail,
	GoToJail,
	FreeParking,
	Go
};

struct Space
{
	Deed info;
	SpaceType type = SpaceType::Jail;
	Owner owner = Owner::Bank;
};

class Board
{
public:
	Board();
	~Board();

	Space SetSpace(DeedName deed, Owner owner, SpaceType type);
	Space GetSpace(int spaceNo) { return board[spaceNo]; };
	Space Roll(int playerNo, int rollTotal);
	void SetPlayerLoc(int playerNo, int loc);
	int getPlayerLoc(int playerNo) { return playerLocation[playerNo]; };

private:
	int playerLocation[8];
	Space board[totalBoardSpaces];

	Space SetProperty(DeedName deed);
	Space SetCard(SpaceType type);
};

#endif // !BOARD_H
