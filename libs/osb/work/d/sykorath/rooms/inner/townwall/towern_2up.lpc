/*
 * part of the townwall
 * north tower near maingate
 *
 * last changes:
 * [m] 17 jun 97 - first version
 * [m] 21 jan 98 - remade
 */

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit TOWNWALL;

create() {
  ::create();
  SetIntShort("On the platform of the north tower");
  SetIntLong(
    "You are standing on the platform of this tower. To the south you "
    "see the south tower of the townwall of the inner city. A staircase "
    "leads down.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({500,580,10}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  /* details */
  AddVItem( ([
    P_IDS:  ({"tower","north tower","tower north"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"city"}),
    P_ADS:  ({"inner","outer"}),
    P_LONG: "If you look around you will see some parts of the inner city "
            "to the east and some parts of the outer city to the "
            "west.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"platform"}),
    P_LONG: "You are standing on it.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"south tower","tower south"}),
    P_LONG: "You see this tower to the south. It is not far from here.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"towers"}),
    P_ADS:  ({"two"}),
    P_LONG: "You are in one of the both towers.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"townwall"}),
    P_ADS:  ({"high"}),
    P_LONG: "This tower is part of the high townwall.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"gate","towngate"}),
    P_ADS:  ({"inner"}),
    P_LONG: "You can't see it from here!\n" ]) );
  AddVItem( ([
    P_IDS:  ({"staircase"}),
    P_ADS:  ({"oak","wooden","old"}),
    P_LONG: "It is the old oak staircase where you come from. You can use "
            "it to go back to the north tower.\n" ]) );

  /* exits */
  AddExit("down","./towern_up");
}

