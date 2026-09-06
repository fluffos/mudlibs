// part of the town
// made by magictcs - 22 may 97
// TODO: add a secret way to leave the inner city here
// TODO: change the path to hartward and replace it by another nice path!!!!
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

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
  TP->move("/d/archwiz/common/room/city/shop",M_GO,"into the door");
  return 1;
}

create() {
  ::create();
  SetIntShort("A dead end");
  SetIntLong(
    "The road ends directly before the huge townwall. There is only a way\n"
    "back to the mainplaza.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"end","dead end","road"}),#'IntLong);
  AddDetail(({"townwall","huge townwall"}),
    "There is actually no way to pass the townwall here - maybe in future?\n");
  AddDetail(({"way","way back","mainplaza"}),
    "The way leads back to the mainplaza.\n");

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
  AddExit("northwest","./mainroadse2");
}

