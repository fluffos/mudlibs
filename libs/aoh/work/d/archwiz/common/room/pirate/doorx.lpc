#include "path.h"
#include <doors.h>
#include <properties.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("small chamber");
  SetIntLong("You're in a small chamber with a door to the west.\n");
  SetIndoors(1);
  SetBright(0);
  AddReadMsg(({"rune","runes"}),"You read the runes but don't understand them.\n");
  AddDetail(({"rune","runes"}),"You don't understand them.\n");
  AddDetail(({"chamber","small chamber"}),QueryIntLong());
  AddDetail(({"standard lock","lock"}),"A standard lock.\n");
  AddDetail(({"walls","wall","ground","floor","ceiling"}),
"Everything looks pretty normal.\n");
  AddExit("north","./doorn");
  AddExit("south","./doors");
  AddExit("east","./incave6");
  AddDoor("west","./maze",
    ([P_SHORT:"odd door",
      P_LONG:"This is an odd door with a lock and some strange runes on it.\n",
      P_ADS:({"small"}),
      P_DOORCODE:"odd door",
      P_DIRECTION:"west",
      P_KEYIDS:({"pirkey"}),
      P_LOCKSTATE:LOCK_LOCKED,
      P_OTHERROOM:0
    ]) );
}
