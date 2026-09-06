#include <moving.h>
#include "path.h"
#include <rooms.h>
#include <properties.h>
#include <money.h>

inherit "/std/room";

int down() {
  if (!this_player()) return 0;
  if (present("pirtroll3",this_object())) {
    write("The troll bars your way.\n");
    return 1;
    }
  this_player()->move(PIRATE("bottomcliff"),M_GO,"down");
  return 1;
}

create() {
  ::create();
  SetIntShort("a small & narrow path");
  SetIntLong(
"You're on a small and narrow path, which leads down to a small "
"part of beach.\n");
  AddDetail(({"small path","path","narrow path","small narrow path",
  "small and narrow path","narrow and small path"}),QueryIntLong());
  AddDetail(({"beach","small beach","small part of beach","part of beach"}),
(PIRATE("bottomcliff"))->QueryIntLong()+(PIRATE("bottomcliff"))->Content());
  SetIndoors(0);
  AddExit("up","./endcliff");
  AddExit("down",#'down);
  AddItem("/std/npc",REFRESH_HOME,
    ([P_NAME:"troll",
      P_SHORT:"a nasty troll",
      P_LONG:"This is a nasty troll which blocks the way down. "
"The troll doesn't look very happy about your arrival.\n",
      P_LEVEL:12,
      P_IDS:({"troll","pirtroll3"}),
      P_ADS:({"nasty","a"}),
      P_HP:140,
      P_HANDS:({ ({"its left hand",0,12}),({"its right hand",0,12}) }),
      P_AC:6,
      P_ITEMS_REFRESH:({({"/obj/money",REFRESH_REMOVE,
	(["Money":MONEY_DEMON->CreateMoney((random(20)+20),({"copper"}))]),0})
	}) ]));
}
