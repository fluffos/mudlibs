#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a small room");
  SetIntLong("You're in a tiny little passage.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"passage","room","small room","small passage",
  "little passage","tiny little passage","tiny passage"}),
  QueryIntLong());
  AddDetail(({"floor","ground","ceiling","walls","wall"}),"You see nothing special.\n");
  AddExit("east","./m3");
  AddExit("north","./m1");
  AddExit("west","./m4");
  AddExit("south","./m5");
}
