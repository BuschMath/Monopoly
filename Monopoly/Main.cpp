#include <iostream>
#include "Cards.h"

int main()
{
	Cards chance(CardType::Chance);

	for (int i = 0; i < 17; i++)
	{
		std::cout << chance.Draw().text << std::endl;
	}

	return 0;
}