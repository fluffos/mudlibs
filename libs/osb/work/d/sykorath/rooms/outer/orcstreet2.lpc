//
// part of south street
// initial version - magictcs - 13 sept 98
//

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <skills.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("On a small path");
  SetIntLong(
    "You stand on a small path.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({360,640,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);
  SetMap("outer");

  // details:

  // Exits
  AddExit("north","./orcstreet1");
  AddExit("southeast","./orcstreet3");
}

