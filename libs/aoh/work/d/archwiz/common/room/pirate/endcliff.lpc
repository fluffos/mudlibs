#include "path.h"
#include <moving.h>

inherit "/std/room";

int down() {
  int help;
  help=this_player()->QueryDex() * 2;
  help+=this_player()->QueryStr();
  if (help<30) {
    write(
"It seems that you're not agile enough to enter this narrow small path.\n");
    return 1;
    }
  if (!this_player()) return 0;
  write("You slowly begin to climb down.\n");
  this_player()->move(PIRATE("downcliff"),M_GO,"down");
  return 1;
}

create() {
  ::create();
  SetIntShort("on a cliff");
  SetIntLong(
"You're standing on a high cliff above the ocean. A small narrow path leads "
"down. The cliff continues to the southeast and to the south into the distance.\n");
  AddDetail(({"cliff","high cliff"}),
QueryIntLong());
  AddDetail(({"ocean","sea","wide ocean","wide sea","blue sea","blue ocean",
  "wide blue ocean","wide blue sea"}),
"It is the wide blue Sea.\n");
  AddDetail(({"small path","path","narrow path","small narrow path"}),
"It leads down.\n");
  SetIndoors(0);
  AddExit("northwest","./cliff");
  AddExit("down",#'down);
}
