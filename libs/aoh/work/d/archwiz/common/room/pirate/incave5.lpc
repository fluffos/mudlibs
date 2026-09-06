#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a cave");
  SetIntLong(
"You're in a cave with walls which seem to absorb the light. There is "
"a sign at one of the walls and a stone stairway leads down.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail("cave",QueryIntLong());
  AddDetail(({"wall","walls"}),"The walls seem to absorb the light.\n");
  AddDetail(({"stairway","stone stairway","stairs","stair","stone stairs"}),
"The stairway leads down.\n");
  AddDetail(({"normal stone","stone"}),"It is normal stone.\n");
  AddDetail(({"ceiling","ground","floor"}),"It looks pretty normal.\n");
  AddDetail("sign","There is something written on it.\n");
  AddReadMsg("sign","We speak of the one god Deepthought, eternal is he (or better not)\n");
  AddExit("down","./incave4");
  AddExit("northwest","./incave6");
}
