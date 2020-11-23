#include "Deed.h"

Deed::Deed()
{
	int rent_[6] = { -10000, -10000, -10000, -10000, -10000, -10000 };

	SetValues(DeedName::NameError, "Name Error", DeedColor::ColorError, rent_, -10000, -10000);
}

Deed::Deed(DeedName name)
{
	SetDeed(name);
}

Deed::~Deed()
{
}

void Deed::SetDeed(DeedName name)
{
	switch (name)
	{
	case DeedName::MediterraneanAvenue: SetMediterraneanAvenue();
		break;
	case DeedName::BalticAvenue:	SetBalticAvenue();
		break;
	case DeedName::OrientalAvenue:	SetOrientalAvenue();
		break;
	case DeedName::VermontAvenue:	SetVermontAvenue();
		break;
	case DeedName::ConnecticutAvenue:	SetConnecticutAvenue();
		break;
	case DeedName::StCharlesPlace:	SetStCharlesPlace();
		break;
	case DeedName::StatesAvenue:	SetStatesAvenue();
		break;
	case DeedName::VirginiaAvenue:	SetVirginiaAvenue();
		break;
	case DeedName::StJamesPlace:	SetStJamesPlace();
		break;
	case DeedName::TennesseeAvenue:	SetTennesseeAvenue();
		break;
	case DeedName::NewYorkAvenue:	SetNewYorkAvenue();
		break;
	case DeedName::KentuckyAvenue:	SetKentuckyAvenue();
		break;
	case DeedName::IndianaAvenue:	SetIndianaAvenue();
		break;
	case DeedName::IllinoisAvenue:	SetIllinoisAvenue();
		break;
	case DeedName::AtlanticAvenue:	SetAtlanticAvenue();
		break;
	case DeedName::VentnorAvenue:	SetVentnorAvenue();
		break;
	case DeedName::MarvinGardens:	SetMarvinGardens();
		break;
	case DeedName::PacificAvenue:	SetPacificAvenue();
		break;
	case DeedName::NorthCarolinaAvenue:	SetNorthCarolinaAvenue();
		break;
	case DeedName::PennsylvaniaAvenue:	SetPennsylvaniaAvenue();
		break;
	case DeedName::ParkPlace:	SetParkPlace();
		break;
	case DeedName::Boardwalk:	SetBoardwalk();
		break;
	case DeedName::ReadingRailroad:	SetReadingRailroad();
		break;
	case DeedName::PennsylvaniaRailroad:	SetPennsylvaniaRailroad();
		break;
	case DeedName::BORailroad:	SetBORailroad();
		break;
	case DeedName::ShortLine:	SetShortLine();
		break;
	case DeedName::Electric:	SetElectric();
		break;
	case DeedName::Water:	SetWater();
		break;
	case DeedName::NameError:	SetNameError();
		break;
	default:	SetNameError();
		break;
	}
}

void Deed::SetMediterraneanAvenue()
{
	int rent_[6] = {2, 10, 30, 90, 160, 250};
	
	SetValues(DeedName::MediterraneanAvenue, "Mediterranean Avenue", DeedColor::Brown, rent_, 60, 50);
}

void Deed::SetBalticAvenue()
{
	int rent_[6] = { 4, 20, 60, 180, 320, 450 };

	SetValues(DeedName::BalticAvenue, "Baltic Avenue", DeedColor::Brown, rent_, 60, 50);
}

void Deed::SetOrientalAvenue()
{
	int rent_[6] = { 6, 30, 90, 270, 400, 550 };

	SetValues(DeedName::OrientalAvenue, "Oriental Avenue", DeedColor::LightBlue, rent_, 100, 50);
}

void Deed::SetVermontAvenue()
{
	int rent_[6] = { 6, 30, 90, 270, 400, 550 };

	SetValues(DeedName::VermontAvenue, "Vermont Avenue", DeedColor::LightBlue, rent_, 100, 50);
}

void Deed::SetConnecticutAvenue()
{
	int rent_[6] = { 8, 40, 100, 300, 450, 600 };

	SetValues(DeedName::ConnecticutAvenue, "Connecticut Avenue", DeedColor::LightBlue, rent_, 120, 50);
}

void Deed::SetStCharlesPlace()
{
	int rent_[6] = { 10, 50, 150, 450, 625, 750 };

	SetValues(DeedName::StCharlesPlace, "St. Charles Place", DeedColor::Pink, rent_, 140, 100);
}

void Deed::SetStatesAvenue()
{
	int rent_[6] = { 10, 50, 150, 450, 625, 750 };

	SetValues(DeedName::StatesAvenue, "States Avenue", DeedColor::Pink, rent_, 140, 100);
}

void Deed::SetVirginiaAvenue()
{
	int rent_[6] = { 12, 60, 180, 500, 700, 900 };

	SetValues(DeedName::VirginiaAvenue, "Virginia Avenue", DeedColor::Pink, rent_, 160, 100);
}

void Deed::SetStJamesPlace()
{
	int rent_[6] = { 14, 70, 200, 550, 750, 950 };

	SetValues(DeedName::StJamesPlace, "St. James Place", DeedColor::Orange, rent_, 180, 100);
}

void Deed::SetTennesseeAvenue()
{
	int rent_[6] = { 14, 70, 200, 550, 750, 950 };

	SetValues(DeedName::TennesseeAvenue, "Tennessee Avenue", DeedColor::Orange, rent_, 180, 100);
}

void Deed::SetNewYorkAvenue()
{
	int rent_[6] = { 16, 80, 220, 600, 800, 1000 };

	SetValues(DeedName::NewYorkAvenue, "New York Avenue", DeedColor::Orange, rent_, 200, 100);
}

void Deed::SetKentuckyAvenue()
{
	int rent_[6] = { 18, 90, 250, 700, 875, 1050 };

	SetValues(DeedName::KentuckyAvenue, "Kentucky Avenue", DeedColor::Red, rent_, 220, 150);
}

void Deed::SetIndianaAvenue()
{
	int rent_[6] = { 18, 90, 250, 700, 875, 1050 };

	SetValues(DeedName::IndianaAvenue, "Indiana Avenue", DeedColor::Red, rent_, 220, 150);
}

void Deed::SetIllinoisAvenue()
{
	int rent_[6] = { 20, 100, 300, 750, 925, 1100 };

	SetValues(DeedName::IllinoisAvenue, "Illinois Avenue", DeedColor::Red, rent_, 240, 150);
}

void Deed::SetAtlanticAvenue()
{
	int rent_[6] = { 22, 110, 330, 800, 975, 1150 };

	SetValues(DeedName::AtlanticAvenue, "Atlantic Avenue", DeedColor::Yellow, rent_, 260, 150);
}

void Deed::SetVentnorAvenue()
{
	int rent_[6] = { 22, 110, 330, 800, 975, 1150 };

	SetValues(DeedName::VentnorAvenue, "Ventnor Avenue", DeedColor::Yellow, rent_, 260, 150);
}

void Deed::SetMarvinGardens()
{
	int rent_[6] = { 24, 120, 360, 850, 1025, 1200 };

	SetValues(DeedName::MarvinGardens, "Marvin Gardens", DeedColor::Yellow, rent_, 280, 150);
}

void Deed::SetPacificAvenue()
{
	int rent_[6] = { 26, 130, 390, 900, 1100, 1275 };

	SetValues(DeedName::PacificAvenue, "Pacific Avenue", DeedColor::Green, rent_, 300, 200);
}

void Deed::SetNorthCarolinaAvenue()
{
	int rent_[6] = { 26, 130, 390, 900, 1100, 1275 };

	SetValues(DeedName::NorthCarolinaAvenue, "North Carolina Avenue", DeedColor::Green, rent_, 300, 200);
}

void Deed::SetPennsylvaniaAvenue()
{
	int rent_[6] = { 28, 150, 450, 1000, 1200, 1400 };

	SetValues(DeedName::PennsylvaniaAvenue, "Pennsylvania Avenue", DeedColor::Green, rent_, 320, 200);
}

void Deed::SetParkPlace()
{
	int rent_[6] = { 35, 175, 500, 1100, 1300, 1500 };

	SetValues(DeedName::ParkPlace, "Park Place", DeedColor::DarkBlue, rent_, 350, 200);
}

void Deed::SetBoardwalk()
{
	int rent_[6] = { 50, 200, 600, 1400, 1700, 2000 };

	SetValues(DeedName::Boardwalk, "Boardwalk", DeedColor::DarkBlue, rent_, 400, 200);
}

void Deed::SetReadingRailroad()
{
	int rent_[6] = { 25, 50, 100, 200, -10000, -10000 };

	SetValues(DeedName::ReadingRailroad, "Reading Railroad", DeedColor::Stations, rent_, 200, -10000);
}

void Deed::SetPennsylvaniaRailroad()
{
	int rent_[6] = { 25, 50, 100, 200, -10000, -10000 };

	SetValues(DeedName::PennsylvaniaRailroad, "Pennsylvania Railroad", DeedColor::Stations, rent_, 200, -10000);
}

void Deed::SetBORailroad()
{
	int rent_[6] = { 25, 50, 100, 200, -10000, -10000 };

	SetValues(DeedName::BORailroad, "B&O Railroad", DeedColor::Stations, rent_, 200, -10000);
}

void Deed::SetShortLine()
{
	int rent_[6] = { 25, 50, 100, 200, -10000, -10000 };

	SetValues(DeedName::ShortLine, "ShortLine", DeedColor::Stations, rent_, 200, -10000);
}

void Deed::SetElectric()
{
	int rent_[6] = { 4, 10, -10000, -10000, -10000, -10000 };

	SetValues(DeedName::Electric, "Electric Company", DeedColor::Utility, rent_, 150, -10000);
}

void Deed::SetWater()
{
	int rent_[6] = { 4, 10, -10000, -10000, -10000, -10000 };

	SetValues(DeedName::Water, "Water Works", DeedColor::Utility, rent_, 150, -10000);
}

void Deed::SetNameError()
{
	int rent_[6] = { -10000, -10000, -10000, -10000, -10000, -10000 };

	SetValues(DeedName::NameError, "Name Error", DeedColor::ColorError, rent_, -10000, -10000);
}

void Deed::SetValues(DeedName d_name_, std::string s_name_, DeedColor color_, int* rent_, int cost_, int houseCost_)
{
	d_name = d_name_;
	s_name = s_name_;
	color = color_;

	for (int i = 0; i < 6; i++)
	{
		rent[i] = rent_[i];
	}

	cost = cost_;
	houseCost = houseCost_;
}
