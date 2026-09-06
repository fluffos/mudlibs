/*
 * part of the town
 * made by magictcs
 *
 * last changes:
 * [m] 15 jan 98 - first version
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
  SetIntShort("A dirty road");
  SetIntLong(
    "The dirty road leads further to the southeast back to the main "
    "plaza. To the west is a dead end.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({560,580,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"road"}),
    P_ADS:  ({"dirty"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"west"}),
    P_LONG: "You see a big stone table there.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"end"}),
    P_ADS:  ({"dead"}),
    P_LONG: "You see a big stone table there.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"plaza","mainplaza"}),
    P_ADS:  ({"main"}),
    P_LONG: "You can reach it by going southeast.\n" ]) );

  AddDetail("southeast","The main plaza is there.\n");
  AddDetail("townwall","You cannot see much of it from here.\n");

  AddSkill(SK_SEARCH,"dirt",75,({"dirty road","road"}));

  /* exits */
  AddExit("west",     "./plateplace");
  AddExit("southeast","./mainplazaw");

  Set(P_INT_WIZMSG,
    "%^RED%^add details, add clean command, "
    "make it friendlier!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

