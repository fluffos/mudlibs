#include "path.h"
inherit "/std/room";

create() {
  ::create();
  SetIntShort("Blue Highway (blocked and overgrown)");
  SetIntLong(
"This is the southern tip of the road that was once known as the "
"Blue Highway.  You see that it has grown into disuse and has become "
"weed-ridden and overgrown.  The only way out is north.\n");
  AddDetail(({"weed-ridden road","road","weed","weeds"}),
"This is the end of an overgrown weed-ridden road.\n");
  AddDetail(({"highway","blue highway"}),QueryIntLong());
  AddExit("north","./row7");
  SetIndoors(0);
}
