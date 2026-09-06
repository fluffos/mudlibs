#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a small room");
  SetIntLong("You're in a tiny little passage.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"passage","small passage","little passage","tiny passage","tiny little passage",
  "small room","room"}),QueryIntLong());
  AddDetail(({"walls","wall","floor","ground","ceiling"}),"You see nothing special.\n");
  AddExit(({"east","west"}),"./m1");
  AddExit("north","./m2");
  AddExit("south","./m3");
}
