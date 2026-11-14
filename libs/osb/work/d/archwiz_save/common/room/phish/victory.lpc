inherit "/std/room";
#include "path.h"
#include <rooms.h>

create(){
  ::create();
  SetIntShort("A broom closet");
  SetIntLong(
"You are in a broom closet.  There is an exit to the south.\n");
  AddItem(PHISH("broom"),REFRESH_REMOVE);
  AddExit("south","./maze_entrance");
 }
