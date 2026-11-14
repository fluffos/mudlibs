#include "path.h"
#include <moving.h>
#include <properties.h>
#include <rooms.h>
inherit "std/room";

int try_east() {
   write("You try to enter the town hall but the doors are closed. "
"On a sign you can read: Town hall closed due to destructions!\n");
  return 1;
}

int go_west() {
  if (!this_player()) return 0;
  if (!query_once_interactive(this_player())) return 0;
  return this_player()->move(CITY("froffice"),M_GO,"west");
}

create() {
  ::create();
  SetIntShort("Sunset Boulevard");
  SetIntLong(
"This is Sunset Boulevard. It is a wide road leading into the southern "
"districts of the city. Sunset Boulevard ends in a large plaza to the north "
"and continues to the south. To the east is the Town Hall, a large marble "
"building with a dome. This building is a majestic sight.\n"
"To the west is a small inviting house. It must have been built not long "
"ago as the walls are still of a shimmering white colour.\n");
  AddDetail(({"sunset boulevard","boulevard","road","wide road"}),
QueryIntLong());
  AddDetail(({"city","nightfall city","capital"}),
"Nightfall City is the capital of the world.\n");
  AddDetail(({"small house","inviting house","house","small inviting house"}),
"You've heard that the mighty Dr. Frankenstein works there.\n");
  AddDetail(({"sight","majestic sight"}),
"The town hall looks marvellous.\n");
  AddDetail(({"districts","district","southern district"}),
"You heard rumours that there would be the city park in the south but also\n\
a not so good neighbourhood.\n");
  AddDetail(({"neighbourhood","not so good neighbourhood"}),
"YOU don't want to live in the southern district, do you?\n");
  AddDetail(({"plaza","wide plaza","central plaza","large plaza"}),
"It is the central plaza of Nightfall City. You see some workers building\n\
up a fun fair there.\n");
  AddDetail(({"workers","worker"}),"The workers look busy.\n");
  AddDetail(({"fair","fun fair"}),
"It is not yet ready.\n");
  AddDetail(({"walls","wall"}),
"The walls of the small house are of shimmering white colour.\n");
  AddDetail(({"white colour","shimmering colour","shimmering white colour",
  "colour"}),
"It is a shimmering white like moonshine.\n");
  AddDetail(({"town hall","hall","townhall"}),
"It looks closed.\n");
  AddDetail(({"building","marble building","dome","marvellous townhall",
  "marvellous building"}),
"The townhall looks marvellous.\n");
    AddItem("/std/thing",REFRESH_HOME,
      ([P_SHORT:"an interesting sign",
	P_LONG:
"It is a wooden pointer. It points south and bears the words 'Newbie Park' "
"in large friendly letters.\n",
        P_IDS:({"sign","pointer"}),
	P_ADS:({"a","an","interesting","wooden"}),
        P_NOGET:1,
	P_READ_MSG:"To the Newbie Park.\n"]));
  AddExit("north",   "./vill_green");
  AddExit("west",#'go_west);
  AddExit("south",   "./boul2");
  AddExit("east",#'try_east);
  HideExit("east",1);
  SetIndoors(0);
}
