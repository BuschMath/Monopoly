#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <string>
#include <vector>
#include <algorithm>
#include "Deed.h"

class Properties
{
public:
	Properties();
	~Properties();
	int FindDeed(DeedName name);
	Deed GetDeed(DeedName name);
	void PushDeed(Deed newDeed);
	void PopDeed(DeedName name);
	bool CheckMonopoly(DeedColor color);
	int CountRR();

private:
	std::vector<Deed> properties;
};

#endif // !PROPERTIES_H
