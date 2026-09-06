/*
 * part of the main gate
 * made by Magictcs - 26 may 97
 *
 * last changes:
 * [m] 15 jan 97
 */

#include <properties.h>
#include <regions.h>
#include <coordinates.h>
#include <moving.h>
#include <sykorath.h>

inherit TOWNWALL;

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("North tower of the townwall");
  SetIntLong(
    "You are in the north tower of the townwall. The north and the south "
    "towers of the inner wall are standing on the left and right side of "
    "the inner town gate.\n");

  SetIndoors(1);
  SetCoordinates( ({ ({500,580,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"tower"}),
    P_ADS:  ({"north"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"two towers"}),
    P_LONG: "You are in one of the both towers.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"townwall"}),
    P_ADS:  ({"high"}),
    P_LONG: "This tower is part of the high townwall.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"gate","towngate"}),
    P_ADS:  ({"inner"}),
    P_LONG: "You can reach the gate by going south!\n" ]) );

  /* exits */
  AddExit("south",INNER("maingate"));
  AddExit("up","./towern_up");

  Set(P_INT_WIZMSG,
    "%^RED%^add something special, change exit north, "
    "add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

