// a stage coach port
// made by magictcs 18 jul 97
// TODO: update coords

#include <properties.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit "/room/port";

//*******
// create
//*******
create() {
  port::create();
  SetIntShort("A stage coach station");
  SetIntLong(
    "You are standing at a stage coach station and waiting for the next stage\n"
    "coach,\n");
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  AddShip(OBJ("transport/stagecoach"));
  AddExit("west","./silvereport");
}

// needed for the ship handling
init() {
  port::init();
}

