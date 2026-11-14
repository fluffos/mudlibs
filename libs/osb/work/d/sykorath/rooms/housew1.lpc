// part of the town
// made by magictcs - 3 jul 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("In a huge house");
  SetIntLong(
    "You are standing in a huge house. It is one of richer people of this\n"
    "town, because it has many more rooms than the normal ones.\n"
    "A door is to the south.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"house","huge house"}),#'IntLong);

  /* exits */
  AddDoor("south","./beforehugehouse",
    ([ P_SHORT:    "a door",
       P_LONG:     "A small wooden door, some words are written on it.\n",
       P_DOORCODE: "hugehousedoor",
       P_ADS:      ({"wooden"}),
       P_SUB_DETAILS: (["words": "You can read it.\n",
                        "word":  "More than one word is written on it.\n"]),
       P_SUB_READMSGS:
           ([({"words","word","some words"}):
                    "You read: 'Please don't steal in my house'.\n"])
    ]) );
  HideDoor("south",HIDE_ALWAYS);
  AddExit("east","./housee1");
  AddExit("north","./housen1");
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

