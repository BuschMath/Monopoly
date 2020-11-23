#ifndef DIE_H
#define DIE_H

// Die rolling simulator

#include <cstdlib>
#include <time.h>

class Die
{
public:

	Die();
	Die(int sides_);
	int Roll();

private:
	int sides;
};

#endif // !DIE_H
