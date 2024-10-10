// DriveWiseBackend.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>
#include <cassert>
#include "DriveWise.h"
#include "rapidcsv.h"

using namespace std;

static std::vector<DriveWise::accident> accidents;

void load_accidents() {
	std::cout << "Loading accidents...";
	
	rapidcsv::Document accidentList("lat_long.csv");

	std::vector<double> xCoords = accidentList.GetColumn<double>("XCOORD");
	std::vector<double> yCoords = accidentList.GetColumn<double>("YCOORD");

	assert(xCoords.size() == yCoords.size());
	accidents.reserve(xCoords.size());
	for (size_t i = 0; i < xCoords.size(); i++) {
		accidents.push_back(DriveWise::accident(xCoords.at(i), yCoords.at(i)));
	}
}

int main()
{
	load_accidents();

	return 0;
}
