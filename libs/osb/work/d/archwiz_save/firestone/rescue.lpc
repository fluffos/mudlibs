#include <rooms.h>
#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("A small room.");
  SetIntLong("A small room. Normally there should be a rescue capsule.\n");
  SetIndoors(1);
  AddExit("east","./transp");
  AddItem(FIRESTONE("cap"),REFRESH_HOME);
}
