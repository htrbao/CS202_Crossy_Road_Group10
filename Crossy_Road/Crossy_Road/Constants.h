#ifndef CONSTANTS_

#define CONSTANTS_

#include <iostream>

namespace Constants {
	const double PI = 3.14159265359;
	const int SCREEN_WIDTH = 473;
	const int SCREEN_HEIGHT = 957;
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
	//const double basicX = 0.5;
	const double positionXofVehical_SE = -30;
	const double positionXofVehical_NW = 503;
	//lane
	const int MAX_ROAD = 10;
	const int SIZE_ROAD_X = 58;
	const int SIZE_ROAD_Y = 68;
	const int HIDDEN_ROAD_Y = 312;
	const int HIDDEN_ROAD_X = 78;
}

#endif // !CONSTANTS_H_
