/*
 * main bank for inner city
 * made by magictcs - 4 jun 97
 *
 * last changes:
 * [m] 08 jan 97 - remade
 */

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
    "Look at the teller, if you want to know more!\n");

  SetIndoors(1);
  SetCoordinates( ({ ({560,620,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);
  
  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"citybank","bank","city bank","room"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"counter"}),
    P_ADS:  ({"wooden"}),
    P_LONG: "The counter is made of wood.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"wood"}),
    P_ADS:  ({"polished"}),
    P_LONG: "It is polished wood, but you have no idea of which sort "
            "of tree.\n" ]) );
  AddDetail("north","It leads back to the main plaza.\n");
  AddVItem( ([
    P_IDS:  ({"plaza"}),
    P_ADS:  ({"main"}),
    P_LONG: "You can see the main plaza from here.\n" ]) );

  /* exits */
  AddExit("east", "./mainplazasw");
  AddExit("south","./itemple");
  AddDoor("west","./bank_to_oguild",
    ([ P_SHORT:    "a door",
       P_LONG:     "A nearly broken door.\n",
       P_LOCKSTATE: LOCK_OPEN,
       P_DOORCODE: "bankwestdoor",
       P_ADS:      ({"broken","nearly broken"}),
    ]) );
  AddItem("/p/money/obj/cbteller",REFRESH_HOME);

  Set(P_INT_WIZMSG,
    "%^RED%^correct exit west, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

