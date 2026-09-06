/* part of the mainplaza of the town
 *
 * last changes:
 * [m] 08 jan 97 - first version
 */

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <ansi.h>
#include <sykorath.h>

inherit BASEROOM;

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("The main plaza");
  SetIntLong(
    "This place is part of the main plaza of the town.\n");
 
  SetIndoors(0);
  SetCoordinates( ({ ({620,620,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"plaza","place"}),
    P_ADS:  ({"this","main"}),
    P_LONG: #'IntLong ]) );
  AddDetail("town","You are standing inmids the town.\n");

  /* Exits */
  AddExit("north",    "./mainplazae");
  AddExit("west",     "./mainplazas");
  AddExit("east",     "./to_patrician");
  AddExit("northwest","./mainplazam");
  AddExit("southeast","./to_hurxel");

  Set(P_INT_WIZMSG,
    "%^RED%^add something special, "
    "check the coords, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

