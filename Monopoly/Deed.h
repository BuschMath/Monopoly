#ifndef DEED_H
#define DEED_H

#include <string>
#include <vector>

enum class DeedName
{
	MediterraneanAvenue,
	BalticAvenue,
	OrientalAvenue,
	VermontAvenue,
	ConnecticutAvenue,
	StCharlesPlace,
	StatesAvenue,
	VirginiaAvenue,
	StJamesPlace,
	TennesseeAvenue,
	NewYorkAvenue,
	KentuckyAvenue,
	IndianaAvenue,
	IllinoisAvenue,
	AtlanticAvenue,
	VentnorAvenue,
	MarvinGardens,
	PacificAvenue,
	NorthCarolinaAvenue,
	PennsylvaniaAvenue,
	ParkPlace,
	Boardwalk,
	ReadingRailroad,
	PennsylvaniaRailroad,
	BORailroad,
	ShortLine,
	Electric,
	Water,
	NameError
};

enum class DeedColor
{
	Brown,
	LightBlue,
	Pink,
	Orange,
	Red,
	Yellow,
	Green,
	DarkBlue,
	Stations,
	Utility,
	ColorError
};

class Deed
{
public:
	Deed();
	Deed(DeedName name);
	~Deed();

	void SetDeed(DeedName name);

	DeedName GetDName() { return d_name; }
	std::string GetSName() { return s_name; }
	int GetRent(int type) { return rent[type]; }
	int GetCost() { return cost; }
	int GetHouseCost() { return houseCost; }
	DeedColor GetColor() { return color; }

private:
	DeedName d_name;
	std::string s_name;
	DeedColor color;
	int rent[6];
	int cost;
	int houseCost;

	void SetMediterraneanAvenue();
	void SetBalticAvenue();
	void SetOrientalAvenue();
	void SetVermontAvenue();
	void SetConnecticutAvenue();
	void SetStCharlesPlace();
	void SetStatesAvenue();
	void SetVirginiaAvenue();
	void SetStJamesPlace();
	void SetTennesseeAvenue();
	void SetNewYorkAvenue();
	void SetKentuckyAvenue();
	void SetIndianaAvenue();
	void SetIllinoisAvenue();
	void SetAtlanticAvenue();
	void SetVentnorAvenue();
	void SetMarvinGardens();
	void SetPacificAvenue();
	void SetNorthCarolinaAvenue();
	void SetPennsylvaniaAvenue();
	void SetParkPlace();
	void SetBoardwalk();
	void SetReadingRailroad();
	void SetPennsylvaniaRailroad();
	void SetBORailroad();
	void SetShortLine();
	void SetElectric();
	void SetWater();
	void SetNameError();

	void SetValues(DeedName d_name_, std::string s_name_, DeedColor color_, int* rent_, int cost_, int houseCost_);
};

#endif // !DEED_H

