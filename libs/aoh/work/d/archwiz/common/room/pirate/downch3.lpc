#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a stairway");
  SetIntLong(
"You're at the end of a long stairway. Down below you see the room of Leo "
"the Archwizard. The floor is about 10 feet below, but you think that you're "
"able to jump down.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"stair","stairs","stairway","long stairs",
  "long stair","long stairway","end","end of stairs",
  "end of stairway","end of stair"}),QueryIntLong());
  AddDetail("down",
(CITY("wiz_hall"))->QueryIntLong()+(CITY("wiz_hall"))->Content());
  AddDetail("leo","Jump down, perhaps you'll meet him.\n");
  AddDetail(({"floor","ground"}),"It is about 10 feet below you.\n");
  AddDetail(({"walls","wall","ceiling"}),
"You don't see anything special.\n");
  AddExit("up","./downch2");
  AddExit(({"down","jump"}),CITY("wiz_hall"));
  HideExit("down",1);
  HideExit("jump",1);
}
