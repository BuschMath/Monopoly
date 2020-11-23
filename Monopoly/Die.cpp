#include "Die.h"

Die::Die()
{
	srand(unsigned int(time(NULL)));
	sides = 6;
}

Die::Die(int sides_)
{
	srand(unsigned int(time(NULL)));
	sides = sides_;
}

int Die::Roll()
{
	return rand() % sides + 1;
}
