inherit "std/room";
#include "path.h"
#include <rooms.h>;
#include <config.h>;

create() {
 ::create();
  SetIntShort("In a big forest");
SetIntLong("\
It is rather dark in here because of the many trees. "
"You fear to run straight into one of them, so you decide to "
"leave and go to a better lit part of the wood if you can find it.\n");
  SetIndoors(0);
  SetSunBright(MAX_SUNBRIGHT/3);
  AddDetail("trees","They are very dense here.\n");
  AddDetail(({"tree"}),
  "As it is too dark you can't recognize its species, but "
"whatever it is, it is a fine specimen.\n");
  AddDetail(({"wood","elvenwood","Elvenwood"}),
  "This wood is inhabitated by Elves.\n");
/*
  AddExit("west","./clearing");
*/
  AddExit("east","./wild1");
  AddExit( "west", "/players/mica/dp/rooms/darkportal/road4" );
  AddItem(OBJ("jacket"),REFRESH_REMOVE);
}
