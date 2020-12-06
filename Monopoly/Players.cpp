#include "Players.h"

Players::Players()
{
	money.PlayerSetup();
	getOutOfJailFree = false;
	piece = Piece::none;
	playerNo = PlayerNo::none;
	computer = false;
}
