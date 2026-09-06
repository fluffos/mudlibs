#include <moving.h>
#include "path.h"

inherit "std/room";

go_north() {
  if (!this_player()) return 0;
  this_player()->move(CITY("clear2"),M_GO,"to an unseen direction");
  return 1;
}
 
create() {
  ::create();
  SetIntShort("Clearing");
  SetIntLong(
"You reached a place with no trees on it. Some would call it a clearing, though "
"there are many bushes on it. To the north there seems to be a way to leave the "
"path that still continues east/west.\n");
  SetIndoors(0);
  AddDetail(({"place","clearing"}),"It is as clear as a clearing could be.\n");
  AddDetail(({"tree","trees"}),"The trees get sparse to the north.\n");
  AddDetail("forest","It consists of trees.\n");
  AddDetail(({"bushes","bush"}),"They cover the ground.\n");
  AddDetail("path","it leads from Nightfall City westwards into the wood.\n");
  AddDetail(({"wood","elven wood"}),"Elven wood lies to the west.\n");
  AddExit("east","./wood1");
  AddExit("west","/d/woodland/common/lake/forest2");
  AddExit(({"north","leave"}),#'go_north);
  HideExit(({"north","leave"}),1);
}
