/*
 * part of the maingate
 * made by Magictcs - 28 may 97
 *
 * last changes:
 * [m] 15 jan 97
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
  SetIntShort("South tower of the townwall");
  SetIntLong(
    "You are in the south tower of the townwall. The north and the south "
    "towers of the inner wall are standing on the left and right side of "
    "the inner town gate.\n");

  SetIndoors(1);
  SetCoordinates( ({ ({500,620,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"tower"}),
    P_ADS:  ({"south"}),
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
    P_LONG: "The gate is further to the north!\n" ]) );

  /* exits */
  AddExit("north",INNER("maingate"));
  AddExit("up","./towers_up");

  Set(P_INT_WIZMSG,
    "%^RED%^add something special, "
    "change exit south, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}
