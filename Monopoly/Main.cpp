#include <iostream>
#include <fstream>
#include <string>
#include "Monopoly.h"

int main()
{
	Monopoly game;

	game.Play(1);

	long long* freq = game.getFreq();
	long long* freqProp = game.getFreqProp();

	std::ofstream outfile;
	outfile.open("MonopolySpaceRelativeFrequency.dat");

	outfile << "Monopoly probability of landing on a space.\nSample Size = 32,000,000,000\n\n";

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
		std::cout << titles[i] << ": " << float(freq[i]) / float(totalRolls) * 100 << "%" << std::endl;
		outfile << titles[i] << ": " << float(freq[i]) / float(totalRolls) * 100 << "%" << std::endl;
	}

	std::cout << std::endl;

	std::string propNames[29] = { "Mediterranean Avenue", "Baltic Avenue", "Oriental Avenue", "Vermont Avenue", "Connecticut Avenue", 
	"St. Charles Place", "States Avenue", "Virginia Avenue", "St. James Place", "Tennessee Avenue", "New York Avenue", 
	"Kentucky Avenue", "Indiana Avenue", "Illinois Avenue", "Atlantic Avenue", "Ventnor Avenue", "Marvin Gardens", "Pacific Avenue", 
	"North Carolina Avenue", "Pennsylvania Avenue", "Park Place", "Boardwalk", "Reading Railroad", "Pennsylvania Railroad", 
	"B&O Railroad", "Short Line", "Electric", "Water", "Other" };

	for (int i = 0; i < 29; i++)
	{
		std::cout << propNames[i] << ": " << float(freqProp[i]) / float(totalRolls) * 100 << "%" << std::endl;
		outfile << propNames[i] << ": " << float(freqProp[i]) / float(totalRolls) * 100 << "%" << std::endl;
	}

	return 0;
}