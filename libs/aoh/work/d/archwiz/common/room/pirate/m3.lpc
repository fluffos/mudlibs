#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a small room");
  SetIntLong("You're in a tiny little passage.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"small room","room","passage","small passage",
  "tiny passage","tiny little passage"}),QueryIntLong());
  AddDetail(({"walls","wall","floor","ground","ceiling"}),"You see nothing special.\n");
  AddExit("east","./m2");
  AddExit("north","./mx");
  AddExit("west","./m4");
  AddExit("south","./m3");
}
