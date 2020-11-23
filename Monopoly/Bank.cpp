#include "Bank.h"

Bank::Bank()
{
	money.SetupBank();

	SetupProperties();

	houses = 32;
	hotels = 12;
}

void Bank::SetupProperties()
{
	DeedName names[28] = { DeedName::MediterraneanAvenue, DeedName::BalticAvenue, DeedName::OrientalAvenue, DeedName::VermontAvenue,
	DeedName::ConnecticutAvenue, DeedName::StCharlesPlace, DeedName::StatesAvenue, DeedName::VirginiaAvenue, DeedName::StJamesPlace,
	DeedName::TennesseeAvenue, DeedName::NewYorkAvenue, DeedName::KentuckyAvenue, DeedName::IndianaAvenue, DeedName::IllinoisAvenue,
	DeedName::AtlanticAvenue, DeedName::VentnorAvenue, DeedName::MarvinGardens, DeedName::PacificAvenue, 
	DeedName::NorthCarolinaAvenue, DeedName::PennsylvaniaAvenue, DeedName::ParkPlace, DeedName::Boardwalk, DeedName::ReadingRailroad,
	DeedName::PennsylvaniaRailroad, DeedName::BORailroad, DeedName::ShortLine, DeedName::Electric, DeedName::Water };

	for (int i = 0; i < 28; i++)
	{
		properties.PushDeed(names[i]);
	}
}
