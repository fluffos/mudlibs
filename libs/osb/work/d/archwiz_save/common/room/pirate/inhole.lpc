#include "path.h"
#include <properties.h>
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Small underground cave");
  SetIntLong(
"You are in a small underground cave. Dirt from the ocean covers "
"the floor. There is a bronze sign mounted on one of the walls.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"cave","small cave","underground cave",
    "small underground cave"}),QueryIntLong());
  AddDetail(({"dirt","dirt from the ocean","wet dirt","mud"}),
"It covers the ground. Seems as if this cave could come under water "
"some times.\n");
  AddDetail(({"sign","bronze sign","old sign","old bronze sign"}),
"It seems to be an old bronze sign. There is something written on it.\n");
  AddDetail(({"walls","wall"}),
"There is a sign mounted on one of the walls.\n");
  AddDetail(({"ceiling"}),
"It is close above your head.\n");
  AddReadMsg(({"sign","bronze sign","old sign","old bronze sign"}),
"You read:\n"
"Do not scry, the first is lie ...\n");
  AddExit(({"exit","out"}),"./bottomcliff");
  HideExit("exit",1);
  AddItem(PIROBJ("fly"),REFRESH_HOME);
    // even if it looks strange.. this 'fly' is an object, not an npc
}
