#include "Properties.h"

Properties::Properties()
{
}

Properties::~Properties()
{
	properties.clear();
}

int Properties::FindDeed(DeedName name)
{
	for (int i = 0; i < properties.size(); i++)
	{
		if (properties[i].GetDName() == name)
			return i;
	}
	return -1;
}

Deed Properties::GetDeed(DeedName name)
{
	for (int i = 0; i < properties.size(); i++)
	{
		if (properties[i].GetDName() == name)
			return properties[i];
	}
	return Deed();
}

void Properties::PushDeed(Deed newDeed)
{
	properties.push_back(newDeed);
}

void Properties::PopDeed(DeedName name)
{
	int loc = FindDeed(name);

	if(loc != -1)
		properties.erase(properties.begin() + loc);
}

bool Properties::CheckMonopoly(DeedColor color)
{
	int count = 0;

	for (int i = 0; i < properties.size(); i++)
	{
		if (properties[i].GetColor() == color)
			count++;
	}

	switch (color)
	{
	case DeedColor::Brown:	if (count == 2) return true;
		break;
	case DeedColor::LightBlue:	if (count == 3) return true;
		break;
	case DeedColor::Pink:	if (count == 3) return true;
		break;
	case DeedColor::Orange:	if (count == 3) return true;
		break;
	case DeedColor::Red:	if (count == 3) return true;
		break;
	case DeedColor::Yellow:	if (count == 3) return true;
		break;
	case DeedColor::Green:	if (count == 3) return true;
		break;
	case DeedColor::DarkBlue:	if (count == 2) return true;
		break;
	case DeedColor::Stations:	return false;
		break;
	case DeedColor::Utility:	return false;
		break;
	case DeedColor::ColorError:	return false;
		break;
	default:	return false;
		break;
	}

	return false;
}

int Properties::CountRR()
{
	int count = 0;

	for (int i = 0; i < properties.size(); i++)
	{
		if (properties[i].GetColor() == DeedColor::Stations)
			count++;
	}

	return count;
}
