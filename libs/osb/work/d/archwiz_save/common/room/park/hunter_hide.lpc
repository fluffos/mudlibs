#include "path.h"
#include <rooms.h>
#include <config.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Somewhere between the bushes");
  SetIntLong(
"You are somewhere deep beween the bushes in the hiding place of the "
"hunter. Leaves and thorns are everywhere and you are glad that you have "
"room to stand still.\n");
  SetIndoors(0);
  SetBright(MAX_SUNBRIGHT/3);
  AddExit("out","./pa3n6");
  AddItem(MONSTER("park/hunter"),REFRESH_HOME);
}
