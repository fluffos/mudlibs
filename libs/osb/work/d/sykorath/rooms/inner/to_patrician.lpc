/*
 * part of the town
 * made by magictcs - 18 jan 98
 * way to the house of the patrician
 *
 * last changes:
 */

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>
#include <skills.h>

inherit SY_STREET;

create() {
  ::create();
  SetIntShort("On a road");
  SetIntLong(
    "The dirty road leads further to the southeast. To the east is a "
    "was the house of the patrician. \n");

  SetIndoors(0);
  SetCoordinates( ({ ({640,620,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"road","dirt"}),
    P_ADS:  ({"dirty"}),
    P_LONG: "The road is a little bit dirty. It leads directly to the "
            "house of one of the old patricians of the city to the "
            "east.\n" ]) );
  AddDetail("east",
    "A small house is standing there.\n");
  AddDetail("west","This way leads back to the main plaza.\n");
  AddDetail("townwall","You cannot see much of it from here.\n");
  AddVItem( ([
    P_IDS:  ({"house"}),
    P_ADS:  ({"small"}),
    P_LONG: "The house was the home of the patrician. Not it is a "
            "little bit damaged. You can enter it.\n" ]) );

  AddSkill(SK_SEARCH,"dirt",75,({"dirty road","road","dirt"}));

  /* exits */
  AddExit("west","./mainplazase");
  AddExit("east","./patrician");

  Set(P_INT_WIZMSG,
    "%^RED%^add details, add clean command, "
    "make it friendlier!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

