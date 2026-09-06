#include "path.h"
#include <rooms.h>
#include <moving.h>

inherit "/std/room";

public int fenter(string arg);

create() {
  ::create();
  SetIntShort("Wicked Witch of the West House");
  SetIntLong(
"A black house with a huge pot of boiling water in front of it. "
"You hear an evil laughter! Where is it coming from?!\n");
  SetIndoors(0);
  AddDetail(({"house","black house","west house"}),
"It is a black house which looks not well cared about.\n");
  AddDetail(({"huge pot","pot"}),
"Be careful noone pushes you into it.\n");
  AddDetail(({"water","boiling water"}),
"The water is boiling.\n");
  AddNoise("laughter","You don't know where it comes from.\n");
  AddExit("east","./pa4n1");
  AddExit("south","./pa5n2");
  AddRoomCmd("enter", #'fenter);
  AddItem(MONSTER("park/witch"),REFRESH_HOME);
}

public int fenter(string arg) {
  if (!arg)
    return 0;
  if (-1 == member(({"hut", "house", "black house", "west house" })
		  , norm_id(arg))
     )
  {
    notify_fail("You can't enter "+arg+".\n");
    return 0;
  }
  return UseExit("south", 0, M_GO);
}