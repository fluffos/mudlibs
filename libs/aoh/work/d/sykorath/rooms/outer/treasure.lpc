// a special room with a special door :)
// just part of a new quest
// made by Magictcs - 29 jun 97

// TODO: check the door handling
// TODO: add the special item here

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <money.h>
#include <moving.h>
#include <sykorath.h>

inherit BASEROOM;
inherit MONEY_LIB;

//**********************
// special move function
//**********************
int enter_door() {
  object door;
  write("You enter the door to the south and close the door behind you.\n");
  TP->move(OUTER("safe"),M_GO,"south");
  door=present("door");
  if (door) {
//    door->SetLockState(LOCK_LOCKED);
  }
  return 1;
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("A treasure chamber");
  SetIntLong(
    "You are standing in a huge treasure chamber. The walls are completely\n"
    "made of pure steel - unbreakable. You expect gold and silver and\n"
    "diamonds and so on.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({42,48,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"chamber","treasure chamber","huge chamber",
    "huge treasure chamber"}),#'IntLong);
  AddDetail(({"wall","walls"}),
    "The walls are made of pure steel. Noone is able to come into this room\n"
    "without opening the south door.\n");
  AddDetail(({"steel","pure steel"}),
    "Yes steel. Some scientists invented the method for making steel from\n"
    "simple iron.\n");
  AddDetail("gold","Haha nice joke - there is no gold here.\n");
  AddDetail("silver",
    "Yes it is a treasure chamber, but there isn't any silver here.\n");
  AddDetail(({"diamond","diamonds"}),
    "You can't see any.\n");

  /* items */
//  AddItem(WEAPON("pstaff"),REFRESH_REMOVE);

  /* exits */
  AddDoor("south",#'enter_door,
    ([ P_SHORT:     "a steel door",
       P_LONG:      "A huge steel door with some wheels is blocking the way "
                    "to the south.\n",
       P_LOCKSTATE: LOCK_OPEN,
       P_DOORCODE:  "tresordoor",
       P_ADS:       ({"steel"}),
    ]) );
}

