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
	const double Alpha = 25.0 * PI / 180.0;
	const double Beta = 65 * PI / 180.0;
	//velocity
	const double basicVelocityX = 0.5;
	// with Y i have formula to calculate it in CROBJECT.
	//Vehical
	const double positionXofVehical_SE = -30;
	const double positionXofVehical_NW = SCREEN_WIDTH + 30;
	//Lane
	const float MAX_ROAD = 10;
	const float SIZE_ROAD_X = 40;
	const float SIZE_ROAD_Y = 160;
	const float HIDDEN_ROAD_X = 8;
	const float HIDDEN_ROAD_Y = SIZE_ROAD_Y * 1.5;
}

#endif // !CONSTANTS_H_
