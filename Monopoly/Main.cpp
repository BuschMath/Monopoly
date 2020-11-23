#include <iostream>
#include "Deed.h"

int main()
{
	Deed prop(DeedName::BalticAvenue);

	std::cout << prop.GetRent(0);

	return 0;
}