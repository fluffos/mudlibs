inherit "std/room";
#include "path.h"
#include <rooms.h>

create() {
  ::create();
  SetIntShort("Nightfall City post office");
  SetIntLong(
"You are standing in the post office of Nightfall City. Usually a mailbox "
"can be found here. The exit is to the north.\n");
  AddExit("north", "./narr_alley");
  AddItem("/mail/dpost", REFRESH_HOME);
}

