// part of the town
// made by magictcs - 4 jun 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

void create() {
  ::create();
  SetIntShort("The bank");
  SetIntLong(
    "This is the bank of the inner city. A large counter fills half "
    "of the room. Here you can deposit your money if you open an account. "
    "Ask the teller, if you want to know more!\n");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);
  

  /* details */
  AddDetail(({"citybank","bank","city bank","room"}),QueryIntLong());
  AddDetail(({"counter","wooden counter"}),"The counter is made of wood.\n");
  AddDetail(({"wood","polished wood"}),
    "It is polished wood, but you have no idea of which sort of tree.\n");
  AddDetail("north","It leads back to the main plaza.\n");
  AddDetail(({"plaza","main plaza"}),
    "You can see the main plaza from here.\n");

  /* exits */
  AddExit("east", "./mainroadsw");
  AddDoor("south","./oguild",
    ([ P_SHORT:    "a door",
       P_LONG:     "A nearly broken door.\n",
       P_LOCKSTATE: LOCK_OPEN,
       P_DOORCODE: "banksouthdoor",
       P_ADS:      ({"broken","nearly broken"}),
    ]) );
  AddItem("/p/money/obj/cbteller",REFRESH_HOME);
    // hope that works correctly ?!
}

