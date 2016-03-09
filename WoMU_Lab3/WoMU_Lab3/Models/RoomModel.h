#pragma once

#include "WallModel.h"

#using <mscorlib.dll>

class RoomModel {

public:
	RoomModel();
    ~RoomModel();

    int areaCm2();
    int volumeCm3();

	System::String^ title;
	System::String^ description;

	float longitude;
    float latitude,

	WallModel^ ceiling;
	WallModel^ floor;
	WallModel^ east;
	WallModel^ south;
	WallModel^ north;
	WallModel^ west;

private:

};
