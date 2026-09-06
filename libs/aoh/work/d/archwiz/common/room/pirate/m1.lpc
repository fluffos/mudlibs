#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a small room");
  SetIntLong("You're in a tiny little passage. "
"There is a sign mounted at one wall.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail("sign","You should read it.\n");
  AddDetail(({"passage","tiny little passage","little passage",
              "room","small room","tiny passage"}),
  QueryIntLong());
  AddDetail(({"walls","wall","ceiling","floor","ground"}),"You see nothing special.\n");
  AddReadMsg("sign","The pirate kings second is surely with.\n");
  AddExit("east","./maze");
  AddExit("north","./m2");
  AddExit(({"west","south"}),"./m1");
}
