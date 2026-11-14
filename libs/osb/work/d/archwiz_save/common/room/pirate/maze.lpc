#include "path.h"
#include <moving.h>

inherit "/std/room";

int go_east() {
  if (!this_player()) return 0;
  return this_player()->move(PIRATE("doors"),M_SPECIAL,
    ({"enters the field and suddenly disappears",
      "steps out of a whole in the ground",
      "enter the field and are teleported away"}));
}

create() {
  ::create();
  SetIntShort("a room");
  SetIntLong(
"You're in a small room. To the east a pulsating magic field can "
"be seen. To the west some tiny little passages are starting.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"room","small room"}),QueryIntLong());
  AddDetail(({"walls","wall","floor","ground","ceiling"}),
  "You see nothing special.\n");
  AddDetail(({"passage","passages","little passages","little passage",
	      "tiny passage","tiny passages","tiny little passages","tiny little passage"}),
  "It seems to be a strange maze.\n");
  AddDetail(({"field","magic field"}),
"Well, it pulsates ... and doesn't look dangerous to you.\n");
  AddExit("east",#'go_east);
  AddExit("west","./m1");
}
