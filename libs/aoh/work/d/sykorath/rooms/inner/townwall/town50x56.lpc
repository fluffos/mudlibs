/*
 * part of the townwall
 *
 * last changes:
 * [m] 26 jan 98 - first version
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
  SetIntShort("Inside the townwall");
  SetIntLong(
    "You are inside the townwall. It has a slight curve to the northeast "
    "here.\n");

  SetIndoors(1);
  SetCoordinates( ({ ({500,560,5}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  /* details */
  AddVItem( ([
    P_IDS:  ({"townwall"}),
    P_ADS:  ({"inside"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"curve"}),
    P_ADS:  ({"slight"}),
    P_LONG: "The curve leads to the northeast.\n" ]) );

  /* exits */
  AddExit("northeast","./town52x54");
  AddExit("south","./towern_up");

  Set(P_INT_WIZMSG,
    "%^RED%^add something special, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

