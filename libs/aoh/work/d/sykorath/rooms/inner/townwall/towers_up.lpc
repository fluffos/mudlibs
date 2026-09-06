/*
 * part of the townwall - the south tower (upper stage)
 *
 * last changes:
 * [m] 17 jun 97 - first version
 * [m] 21 jan 98 - remade
 */

// TODO: add get/take of ladder
// TODO: maybe you can pull the ladder up/down?

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
  SetIntShort("Inside the south tower");
  SetIntLong(
    "Inside the south tower. A wooden staircase leads up and a wooden "
    "ladder down.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({500,620,5}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  /* details */
  AddVItem( ([
    P_IDS:  ({"tower","south tower","tower south"}),
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

  /* exits */
  AddExit("down", "./towers");
  AddExit("up",   "./towers_2up");
  AddExit("north","./above_maingate");
  AddExit("south","./town50x64");
}

