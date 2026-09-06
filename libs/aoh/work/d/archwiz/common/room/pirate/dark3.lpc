#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a dark tunnel");
  SetIntLong(
"You're in a tunnel. There seem to exist nicer places than this one.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"tunnel","dark tunnel","place"}),QueryIntLong());
  AddDetail(({"places","nicer places"}),"They have to exist - somewhere!\n");
  AddDetail(({"walls","wall","floor","ground","ceiling"}),
"You don't see anything special.\n");
  AddExit("north","./dark1");
  AddExit("east","./dark4");
}
