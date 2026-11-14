#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a vertical shaft");
  SetIntLong("You are in a vertical shaft leading up and down.\n");
  SetIndoors(1);
  AddDetail(({"shaft","vertical shaft","long shaft"}),QueryIntLong());
  AddDetail(({"walls","wall"}),
"You see nothing special.\n");
  AddDetail(({"ceiling","floor","ground"}),
"You cannot see it from here.\n");
  AddExit("up",CITY("clear2"));
  HideExit("up",1);
  AddExit("down","./dark1");
  HideExit("down",1);
}
