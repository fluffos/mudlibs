inherit "std/room";
#include "path.h"
#include <rooms.h>
#include <doors.h>

create()
{
    ::create();
    SetIntShort("A clearing");
    SetIntLong("You are on a huge clearing behind the white house.\n" +
	       "A path leads to the northwest.\n");
    SetIndoors(0);
    AddDetail(({"house","white house"}),
       "You can find it somewhere to the south.\n");
    AddDetail(({"clearing","huge clearing"}),"You are on the clearing.\n");
    AddDetail(({"tree", "trees" }),
"Trees are all around the clearing, with a particularily high one to the south.\n"
	     );
    AddExit("northwest","./bh2");
    AddExit("south","./clearing2");
    AddDoor("down",WHITEHOUSE("grating_room"),"grating",
      "A massive iron grating with a lock. ",
      "skeleton_grating",DOOR_STATUS_LOCKED);
}

