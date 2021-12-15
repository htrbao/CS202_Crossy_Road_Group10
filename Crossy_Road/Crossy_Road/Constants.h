#ifndef CONSTANTS_

#define CONSTANTS_

#include <iostream>

namespace Constants {
	const double PI = 3.14159265359;
	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 730;

	//--------
	//\Alpha) |
	// \      |
	//  \     |
	//...\   B|
	//    \  e|
	//     \ t|
	//      \a|
	//       \|
	const double Alpha = 27 * PI / 180.0;
	const double Beta = 63 * PI / 180.0;
	//velocity
	const double basicVelocityX = 0.5;
	// with Y i have formula to calculate it in CROBJECT.
	//Vehical
	const double positionXofVehical_SE = -30.0;
	const double positionXofVehical_NW = SCREEN_WIDTH + 30.0;
	//Lane
	const float MAX_ROAD = 10;
	const float SIZE_ROAD_X = 40;
	const float SIZE_ROAD_Y = 160;
	const float HIDDEN_ROAD_X = SIZE_ROAD_X / 4;
	const float HIDDEN_ROAD_Y = SIZE_ROAD_Y * 1.5;
	const float bias = 12;
	//Speed
	const float speed = sqrt(pow((SIZE_ROAD_Y + bias) / 2, 2) / (1 + pow(tan(Beta), 2)));
	//Car
	const std::string CARNAME[] = { "ambulance_","car_1_","car_2_","delivery_","deliveryFlat_","firetruck_","garbageTruck_","police_","race_","raceFuture_" };
	const float CARSPEED[] = { 85, 70, 70, 75, 80, 68, 68, 85, 120, 130 };
	const std::string CARDIR[] = { "NW" , "SE" };
	//type
	const int BLOCK = 0;
	const int CAR = 1;
	const int COIN = 2;
};

#endif // !CONSTANTS_H_
