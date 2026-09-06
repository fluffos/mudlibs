#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a bottom of a shaft");
  SetIntLong(
"You're at a bottom of a long vertical shaft. A tunnel leads south into "
"the darkness.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"bottom","bottom of a shaft"}),
QueryIntLong());
  AddDetail(({"long shaft","shaft","vertical shaft","long vertical shaft"}),
"It leads up.\n");
  AddDetail(({"tunnel","dark tunnel","east"}),
"The tunnel to the south leads into darkness.\n");
  AddDetail("darkness","You wonder if you should investigate it.\n");
  AddDetail(({"walls","wall","floor","ground"}),
"You see nothing special.\n");
  AddDetail("ceiling","A shaft leads up.\n");
  AddExit("south","./dark3");
  HideExit("south",1);
  AddExit("up","./dark0");
  HideExit("up",1);
}
