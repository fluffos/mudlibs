#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("At the gates of the adventurer park");
  SetIntLong(
"You stand before the gates of the low-level-adventurer-park of Nightfall. "
"Be sure to put on wimpy-mode, and have an eye on your health. "
"The management of the park doesn't guarantee for your life in any case "
"But you can take all things you find for free.\n"
"One last thing: This park is meant as training area for Newbies, so be "
"be fair and don't slay all monsters inside if you are strong enough to "
"fight somewhere else.\n"
"                       The Management\n\n\n");
  SetIndoors(0);
  AddExit("west","./pa1n4");
  AddExit("east",CITY("forest1"));
  AddItem(MONSTER("park/ent"),REFRESH_HOME);
}
