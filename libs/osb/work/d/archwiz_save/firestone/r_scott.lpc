#include <rooms.h>
#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("In a corridor");
  SetIntLong("You are in a corridor.\n");
  SetIndoors(1);
  AddExit("east","./r_t2");
  AddItem(FIRESTONE("scott"),REFRESH_HOME);
}

init() {
  ::init();
  tell_room(this_object(),"Suddenly you hear an announcement:\n"
"  Mr. Scott, Mr. Scott! Please come to the transporter. Immediately!\n");
}
