/* part of the mainplaza of the town
 *
 * last changes:
 * [m] 08 jan 97 - first version
 */

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <ansi.h>
#include <sykorath.h>

inherit BASEROOM;

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("The main plaza");
  SetIntLong(
    "This place is part of the main plaza of the town. To the west is the "
    "main bank of the inner city.\n");
 
  SetIndoors(0);
  SetCoordinates( ({ ({580,620,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"plaza","place"}),
    P_ADS:  ({"this","main"}),
    P_LONG: #'IntLong ]) );
  AddDetail("town","You are standing inmids the town.\n");
  AddVItem( ([
    P_IDS:  ({"city"}),
    P_ADS:  ({"inner"}),
    P_LONG: "You are standing in it.\n" 
    ]) );
  AddVItem( ([
    P_IDS:  ({"bank"}),
    P_ADS:  ({"main"}),
    P_LONG: "It is to the west.\n" ]) );

  /* Exits */
  AddExit("north",    "./mainplazaw");
  AddExit("east",     "./mainplazas");
  AddExit("northeast","./mainplazam");
  AddExit("west","./bank");
  AddDoor("down","./never_opene?!",
    ([ P_SHORT:    "a trap door",
       P_LONG:     ({"A steel trap door leading to a cave, where prisoners "
                   "are waiting for their punishment.\n",
                   "A steel trap door leading to a cave, where prisoners "
                   "are waiting for their punishment. "
                   "Be careful no to be inside this cave.\n"}),
       P_LOCKSTATE: LOCK_LOCKED,
       P_DOORCODE: "trapdoor_to_prison_inner_sykorath",
       P_ADS:      ({"steel","trap"}),
    ]) );


  Set(P_INT_WIZMSG,
    "%^RED%^add something special, "
    "check the coords, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

