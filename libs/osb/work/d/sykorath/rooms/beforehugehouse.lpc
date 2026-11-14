// part of the town
// made by magictcs - 3 jul 97
// TODO: add details, special commands, exits, items
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <lock.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("Right before a house");
  SetIntLong(
    "You are on north-south road. To the north is a huge house.\n"
    "The way south leads back to the main part of the outer city.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"road","north south road","north-south road"}),#'IntLong);
  AddDetail(({"house","huge house"}),
    "There is a door in the wall of the house.\n");
  AddDetail(({"wall","wall of house","wall of the house"}),
    "The wall is painted white. Not like the other walls of the other\n"
    "houses in this city. This house has to be the property of a richer\n"
    "man.\n");
  AddDetail(({"way south","way back","south"}),
    "The way leads back top the south.\n");
  AddDetail("outer city","You are standing in it.\n");
  AddDetail("city","Yes this road is part of it.\n");
  AddDetail("north","The huge house stands there.\n");

  /* exits */
  AddDoor("north","./housew1",
    ([ P_SHORT:    "a door",
       P_LONG:     "A small wooden door, some words are written on it.\n",
       P_DOORCODE: "hugehousedoor",
       P_ADS:      ({"wooden"}),
       P_SUB_DETAILS: (["words": "You can read it.\n",
                        "word":  "More than one word is written on it.\n"]),
       P_SUB_READMSGS:
           ([({"words","word","some words"}):
                    "You read: Sir Eduard Patrick.\n"])
    ]) );
  HideDoor("north",HIDE_ALWAYS);
  AddExit("south","./roadw1");
}

//***************
// close the door
//***************
reset() {
  object door;
  ::reset();
  door=present("door");
  if (door) {
    if (door->QueryLockState()==LOCK_OPEN) {
      tell_room(TO,"You hear a loud BUMM as the door is closed.\n");
      door->SetLockState(LOCK_CLOSED);
    }
  }
}

