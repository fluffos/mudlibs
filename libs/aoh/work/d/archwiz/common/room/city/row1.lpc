#include "path.h"
#include <properties.h>
#include <rooms.h>
inherit "std/room";

create() {
  ::create();
  SetIntShort("Skid Row");
  SetIntLong(
"You are walking down Skid Row. The street is littered with Wall Street "
"business-men-turned-bums and sleazy hookers. Skid Row runs east from here. "
"To the south you can see many trees.\n");
    AddItem("/std/thing",REFRESH_HOME,
      ([P_SHORT:"an interesting sign",
	P_LONG:
"It is a wooden pointer. It points south and bears the words 'Newbie Park' "
"in large friendly letters.\n",
        P_IDS:({"sign","pointer"}),
	P_ADS:({"a","an","interesting","wooden"}),
        P_NOGET:1,
	P_READ_MSG:"To the Newbie Park.\n"]));
  AddExit("east",  "./row2");
  AddExit("south", "./forest1");
  SetIndoors(0);
}
