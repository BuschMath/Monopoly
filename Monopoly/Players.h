#ifndef PLAYERS_H
#define PLAYERS_H

#include "Money.h"
#include "Properties.h"

enum class Piece
{
	car,
	horse,
	ship,
	dog,
	iron,
	wheelbarrow,
	thimble,
	hat,
	none
};

enum class PlayerNo
{
	Player1,
	Player2,
	Player3,
	Player4,
	Player5,
	Player6,
	Player7,
	Player8,
	none
};

class Players
{
public:
	Players();

	void SetPlayerNo(PlayerNo no) { playerNo = no; };
	void SetComputer(bool computer_) { computer = computer_; };

private:
	Money money;
	Properties properties;
	bool getOutOfJailFree;
	Piece piece;
	PlayerNo playerNo;
	bool computer;
};

#endif // !PLAYERS_H

