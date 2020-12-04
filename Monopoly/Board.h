#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "Properties.h"

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

private:
	Space* playerLocation[8];
	Space board[41];
	Space* go;
	Space* gotoBoardwalk;
	Space* gotoIllinoisAvenue;
	Space* gotoStCharlesPlace;
	Space* gotoElectric;
	Space* gotoWater;
	Space* gotoJail;
	Space* gotoReadingRailroad;

	Space SetProperty(DeedName deed);
	Space SetCard(SpaceType type);
};

#endif // !BOARD_H
