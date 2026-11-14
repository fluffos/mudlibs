/*
 * old guild with only the walls and doors left
 * made by magictcs - 22 may 97
 *
 * last changes:
 * [m] 08 jan 97 - remade
 */

#include <properties.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit SY_STREET;

create() {
  ::create();
  SetIntShort("A former guild");
  SetIntLong(
    "You are standing in one of the former guilds of this town.\n");

  SetIndoors(0);                       // it is not ahouse!
  SetCoordinates( ({ ({540,640,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"guild","guilds"}),
    P_ADS:  ({"former"}),
    P_LONG: #'IntLong ]) );
  AddDetail("town","You are standing in it.\n");

  /* exits */
  AddDoor("north","./bank_to_oguild",
    ([ P_SHORT:    "a door",
       P_LONG:     "A wooden door.\n",
       P_LOCKSTATE: LOCK_OPEN,
       P_DOORCODE: "oguild_door",
       P_ADS:      ({"wooden"}),
    ]) );
  AddExit("southeast","./empty");

  Set(P_INT_WIZMSG,
    "%^RED%^correct exit north, add details, make it friendlier!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

