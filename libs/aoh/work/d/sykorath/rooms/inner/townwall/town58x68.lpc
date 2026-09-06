/*
 * part of the townwall
 *
 * last changes:
 * [m] 8 feb 98 - first version
 */

#include <properties.h>
#include <regions.h>
#include <coordinates.h>
#include <moving.h>
#include <nightday.h>
#include <sykorath.h>

inherit TOWNWALL;

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("Inside the townwall");
  SetIntLong(
    "You are inside the townwall.\n");

  SetIndoors(1);
  SetCoordinates( ({ ({580,680,5}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  /* details */
  AddVItem( ([
    P_IDS:  ({"townwall"}),
    P_ADS:  ({"inside"}),
    P_LONG: #'IntLong ]) );

  /* exits */
  AddExit("east","./town61x68");
  AddExit("west","./town54x68");

  Set(P_INT_WIZMSG,
    "%^RED%^add something special, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

