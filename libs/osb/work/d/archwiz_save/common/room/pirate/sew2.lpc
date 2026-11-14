#include "path.h"
#include <rooms.h>
#include <properties.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("City sewers");
  SetIntLong("You are in the City sewers. You don't like the smell here.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"sewers","sewer","city sewers"}),QueryIntLong());
  AddDetail(({"smell","bad smell"}),"It stinks.\n");
  AddDetail(({"walls","walls","ceiling","floor","ground"}),
"You see nothing special.\n");
  SetIntSmell("You don't like it here too much.\n");
  AddExit("west","./sew1");
  AddExit("east","./sew3");
  AddItem("std/npc",REFRESH_HOME,
    ([P_NAME:"rat",
      P_SHORT:"a rat",
      P_LONG:"A stinking grey rat.\n",
      P_AGGRESSIVE:1,
      P_AC:2,
      P_LEVEL:2,
      P_HP:50,
      P_XP:10,
      P_ALIGN:0,
      P_HANDS:({ ({"its long teeth",0,4}),({"its claws",0,5})})]));
}
