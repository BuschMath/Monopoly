#include <iostream>
#include <string>
#include "Monopoly.h"

int main()
{
	Monopoly game;

	game.Play(1);

	int* freq = game.getFreq();
	std::string titles[10];
	titles[0] = "Property";
	titles[1] = "Chance";
	titles[2] = "CommunityChest";
	titles[3] = "IncomeTax";
	titles[4] = "LuxuryTax";
	titles[5] = "JustVisiting";
	titles[6] = "Jail";
	titles[7] = "GoToJail";
	titles[8] = "FreeParking";
	titles[9] = "Go";

	for (int i = 0; i < 10; i++)
	{
		std::cout << titles[i] << ": " << freq[i] << std::endl;
	}

	return 0;
}