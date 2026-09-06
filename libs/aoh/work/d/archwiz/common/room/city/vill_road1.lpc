#include "path.h"
#include <rooms.h>
inherit "std/room";

create() {
  ::create();
  SetIntShort("Main & Pub Crossing");
  SetIntLong(
"This is the crossing of Main Street and Pub Street. Main Street runs west to "
"east, Pub Street runs north to south. Busy people running along these streets. "
"They seem to know where to go. Maybe they are citizens of the worlds most "
"famous town? There is a tall building to be seen to the southeast. A sign "
"above the entrance shows you that this is the local tailor's house. It seems "
"to be a very expensive tailor.\n");
  AddDetail( ({"crossing"}),"This is a large crossing with lots of traffic.\n");
  AddDetail(({"floor","ground"}),"Just a normal street.\n");
  AddDetail( ({"streets","street"}),
"A city consists of streets. You stand at the crossing of two of them.\n");
  AddDetail("entrance","It is the entrance to the tailor's house.\n");
  AddDetail( ({"main street"}),
"Main street runs east-west from the shore to the forest through the whole city.\n");
  AddDetail( ({"pub street"}),
"Pub street runs north-south through the center of the town.\n");
  AddDetail( ({"people","busy people","citizens"}),
"They are too busy to talk to you.\n");
  AddDetail( ({"town","city","village","nightfall city","capital"}),
"This is the worlds biggest town. Its capital. In former times every "
"adventurer's carreer started here.\n");
  AddDetail( ({"house","building","southeast building","tailor"}),
"It is a huge building. The owner must be one of Nightfall's richest people.\n");
  AddDetail( ({"sign"}),
"The sign reads: Court tailor. Every wiz buys his wizcloak here!\n");

  AddExit("west", "./vill_track");
  AddExit("east", "./vill_road2");
  AddExit("north","./yard");
  AddExit("south","./narr_alley");
  AddExit("southeast","./tailor");
// BEGONE AddItem(DREAMMONSTER,REFRESH_DESTRUCT);
  SetIndoors(0);
}

