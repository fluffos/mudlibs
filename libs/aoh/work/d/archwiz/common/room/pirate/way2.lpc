#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a dark tunnel");
  SetIntLong("You're in a dark tunnel. To the north the darkness vanishes.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"tunnel","dark tunnel"}),QueryIntLong());
  AddDetail(({"walls","wall","floor","ground","ceiling"}),
"Everything is covered with dirt.\n");
  AddDetail(({"dirt","mud"}),"It's muddy.\n");
  AddDetail(({"north","junction"}),
"There seems to be a junction to the north.\n");
  AddDetail("darkness","It is dark.\n");
  AddExit("south","./way1");
  AddExit("north","./junc");
}
