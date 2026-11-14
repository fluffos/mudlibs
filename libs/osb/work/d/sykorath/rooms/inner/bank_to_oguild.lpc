/*
 * connection between bank and oguild
 * made by magictcs - 15 jan 98
 *
 * last changes:
 * [m] 15 jan 98 - first version introduced
 */

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>
#include <skills.h>

inherit BASEROOM;

void create() {
  ::create();
  SetIntShort("Inside a dark passage");
  SetIntLong(
    "You are in a dark passage. To the east you see an nearly broken "
    "door, leading to the bank of the inner city. To the south is "
    "one of the older guild of the city, that are destroyed during "
    "the great war.\n");

  SetIntLight(20);
  SetIndoors(0);
  SetCoordinates( ({ ({540,620,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);
  
  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"citybank","bank","city bank","room"}),
    P_LONG: "You can see the bank to the east.\n"]) );
  AddVItem( ([
    P_IDS:  ({"passage"}),
    P_ADS:  ({"dark"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"guild"}),
    P_ADS:  ({"former","older","old"}),
    P_LONG: "The guild seems to be to the south, but it is too dark "
            "to see anything more from here.\n" ]) );

  /* exits */
  AddDoor("south","./oguild",
    ([ P_SHORT:    "a door",
       P_LONG:     "A wooden door.\n",
       P_LOCKSTATE: LOCK_OPEN,
       P_DOORCODE: "oguild_door",
       P_ADS:      ({"wooden"}),
    ]) );
  AddDoor("east","./bank",
    ([ P_SHORT:    "a door",
       P_LONG:     "A nearly broken door.\n",
       P_LOCKSTATE: LOCK_OPEN,
       P_DOORCODE: "bankwestdoor",
       P_ADS:      ({"broken","nearly broken"}),
    ]) );

  Set(P_INT_WIZMSG,
    "%^RED%^add details and somethign special!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

