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

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("Inside the north tower");
  SetIntLong(
    "Inside the north tower. A wooden staircase leads up. In one corner "
    "stands a ladder.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({500,580,5}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  /* details */
  AddVItem( ([
    P_IDS:  ({"tower","north tower","tower north"}),
    P_LONG: #'IntLong ]) );
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
    P_ADS:  ({"wooden","oak","old"}),
    P_LONG: "The staircase is old, but fully functional. It leads up to "
            "the platform of this tower. The staircase is made of oak "
            "wood.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"ladder"}),
    P_ADS:  ({"wooden","oak"}),
    P_LONG: "The ladder leads down. It is made of oak wood.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"corner"}),
    P_ADS:  ({"one"}),
    P_LONG: "A ladder is standing there.\n" ]) );

  /* exits */
  AddExit("down", "./towern");
  AddExit("up",   "./towern_2up");
  AddExit("south","./above_maingate");
  AddExit("north","./town50x56");
}

