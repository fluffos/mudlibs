//
// part of south street
// initial version - magictcs - 13 sept 98
//

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <skills.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("On a small path");
  SetIntLong(
    "This is part of the orc street. To the north is a closed door.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({400,700,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);
  SetMap("outer");

  // details:

  // Exits
  AddDoor("north","./shoemaker_nailed_shut",
    ([ P_SHORT:    "a oak door",
       P_LONG:     "A oak wooden door. It is nailed shut. Noone is able "
                   "to open it.\n",
       P_DOORCODE: "syko_shoemakerdoor_nailed",
       P_CHECKDOOR: DACT_CHECK,             // needed to use CheckAction
       P_CHECKOBJ:  TO,                     // needed to use CheckAction
       P_ADS:      ({"oak"}),
    ]) );
  AddExit("northwest","./orcstreet4");
  AddExit("south","./orcstreet6");
}

// block commands for the door
// no open/lock/unlock
// but allow passing for ghosts
int CheckAction (string action, string verb, string arg, int method) {
  switch (action) {
    case "lock":
           notify_fail("The door is nailed shut.\n");
           return 0;           // no locking of this door allowed
    case "door":
         if (verb=="open") {
             notify_fail("The door is nailed shut.\n",NOTIFY_NOT_VALID);
             return 0;                 // door cannot be opened!
         }
    default: break;
  }
  return ::CheckAction(action,verb,arg,method);
}

