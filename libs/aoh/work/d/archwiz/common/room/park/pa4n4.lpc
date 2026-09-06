#include "path.h"
#include <moving.h>

inherit "/std/room";

int do_enter(string str) {
  if (!this_player()) return 0;
  if (!str) return notify_fail("Enter what?\n"),0;
  if (str!="hut") return notify_fail(
"Are you sure this is here?\n"),0;
  return this_player()->move(PARK("hutentry"),M_GO,"northeast");
}

create() {
  ::create();
  SetIntShort("In The City Forest");
  SetIntLong(
"The path again splits into four ways.  You can see the edge of the "
"forest. There's a little hut standing right to the northwest.\n");
  AddDetail(({"hut","small hut","little hut","white hut",
    "little white hut","small white hut"}),
"It is a little white hut with a beautiful red roof and looks well cared "
"about.\n");
  AddDetail(({"roof","red roof","beautiful roof","beautiful red roof"}),
"It is light red gives a nice contrast to the white walls of the hut.\n");
  AddDetail(({"walls","wall","white walls","white wall"}),
"The white walls look very clean.\n");
  AddDetail("path",#'IntLong);
  AddDetail(({"forest","edge of the forest","edge of a forest"}),
"The forest continues north\n");
  SetIndoors(0);
  AddExit("enter",#'do_enter);
  AddExit("northwest","./hutentry");
  HideExit(({"northwest","enter"}),1);
  AddExit("west","./pa5n4");
  AddExit("east","./pa3n4");
  AddExit("south","./pa4n5");
  AddExit("north","./pa4n3");
}
