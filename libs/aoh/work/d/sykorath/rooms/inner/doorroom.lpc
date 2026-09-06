/*
 * part of the town, you can leave the inner city through the small door
 * made by magictcs - 22 may 97
 *
 * last changes:
 * [m] 08 jan 97 - remade
 */

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit SY_STREET;

#define TARGET "notdefined"

//*********************
// enter the small door
//*********************
int enterdoor() {
  object door;
  write(
    "You enter the door. It is a very small door for you to pass.\n"
    "You close the door behind you.\n");
  door=present("door");
  door->SetLockState(LOCK_LOCKED);
  TP->move(TARGET,M_GO,"into the door");
  return 1;
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("A dead end");
  SetIntLong(
    "The road ends directly before the huge townwall. There is only a way "
    "back to the mainplaza.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({660,660,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"end","dead end","road"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"townwall"}),
    P_ADS:  ({"huge"}),
    P_LONG: "There is actually no way to pass the townwall here - "
            "maybe in future?\n" ]) );
  AddVItem( ([
    P_IDS:  ({"way","way back","mainplaza"}),
    P_LONG: "The way leads back to the mainplaza.\n" ]) );

  AddDoor("southeast",#'enterdoor,
    ([
    P_SHORT:     "small steel door",
    P_LONG:      "A small steel door is built into the townwall.\n",
    P_ADS:       ({"small","steel"}),
    P_LOCKSTATE: LOCK_LOCKED,
    P_DOORCODE:  "secret town wall key",
    P_KEYIDS:    ({"small","steel"}),
    P_KEYCODE:   "secret town wall key"
    ]) );

  /* exits */
  AddExit("northwest","./to_hurxel");

  Set(P_INT_WIZMSG,
    "%^RED%^correct the exit through the door, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

