#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a small room");
  SetIntLong("You're in a tiny little passage.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"room","small room","passage","small passage",
  "little passage","tiny passage","tiny little passage"}),QueryIntLong());
  AddDetail(({"floor","ground","walls","wall","ceiling"}),"You see nothing special.\n");
  AddExit("east","./m1");
  AddExit("north","./out");
  AddExit("west","./m5");
  AddExit("south","./m4");
}
