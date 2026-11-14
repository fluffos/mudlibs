// a stage coach port
// made by magictcs 18 jul 97
// TODO: update coords

#include <regions.h>
#include <coordinates.h>
#include <properties.h>
#include <sykorath.h>

inherit "/room/port";

//*******
// create
//*******
create() {
  port::create();
  SetIntShort("A stage coach station");
  SetIntLong(
    "Silvere coach station.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  AddShip(OBJ("transport/stagecoach"));

  /* exits */
  AddExit("east","./coachport");
}

// needed for the ship handling
init() {
  port::init();
}

