// made by magictcs - 11 jun 97
// old guild with only the walls and doors left
// TODO: make it friendlier
// TODO: update coords

#include <properties.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("A former guild");
  SetIntLong(
    "You are standing in one of the former guilds of this town.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"guild","former guild"}),#'IntLong);
  AddDetail("town","you are standing in it.\n");

  /* exits */
  AddDoor("north","./bank",
    ([ P_SHORT:    "a door",
       P_LONG:     "A nearly broken door.\n",
       P_LOCKSTATE: LOCK_OPEN,
       P_DOORCODE: "banksouthdoor",
       P_ADS:      ({"broken","nearly broken"}),
    ]) );
  AddDoor("southeast","./empty",
    ([ P_SHORT:    "a door",
       P_LONG:     "This door hangs in its rusty hinges.\n",
       P_LOCKSTATE: LOCK_OPEN,
       P_DOORCODE: "emptyroomdoor",
    ]) );
}

