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
	const float basicVelocityX = 0.0140625;
	const float shiftVelocityX = 1.5;
	// with Y i have formula to calculate it in CROBJECT.
	//Vehical
	const double positionXofVehical_SE = -30.0;
	const double positionXofVehical_NW = SCREEN_WIDTH + 30.0;
	//Lane
	const float MAX_ROAD = 12;
	const float SIZE_ROAD_X = 40;
	const float SIZE_ROAD_Y = 160;
	const float HIDDEN_ROAD_X = SIZE_ROAD_X / 4;
	const float HIDDEN_ROAD_Y = SIZE_ROAD_Y * 1.5;
	const float bias = 12;
	//Speed
	const float speed = sqrt(pow((SIZE_ROAD_Y + bias) / 2, 2) / (1 + pow(tan(Beta), 2)));
	//Car
	const std::string CARNAME[] = { "car_1_","car_2_","race_","raceFuture_","ambulance_","delivery_","deliveryFlat_","firetruck_","garbageTruck_","police_" };
	const float CARSPEED[] = { 90, 80, 125, 135, 75, 80, 85, 80, 77, 95};
	const std::string CARDIR[] = { "NW" , "SE" };
	//Block
	const std::string BLOCKNAME[] = { "COIN_1", "COIN_2", "BLOCK_1","BLOCK_3","BLOCK_4","BLOCK_5","BLOCK_SNOW_2","BLOCK_SNOW_1","BLOCK_2","BLOCK_SNOW_3", "TREE", "TREESNOW", "TREELARGE", "TREEPINE"};
	//Sond
	const std::string SOUNDNAME[] = { "CAR_LARGE", "CAR_SMALL", "POLICE", "BIRDS" };
	//Traffic
	const std::string TRAFFICNAME = "TRAFFICLIGHT";
	//type
	const int BLOCK = 0;
	const int CAR = 1;
	const int COIN = 2;
};

#endif // !CONSTANTS_H_
