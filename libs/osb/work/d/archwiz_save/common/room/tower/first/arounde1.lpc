#include "path.h"
inherit "/std/room";

create() {
  ::create();
  SetIntShort("a path around a dark tower");
  SetIntLong(
"You're on a small path which leads around a shimmering tower. "
"Small bushes cover the bottom.\n");
  SetIndoors(0);
  AddDetail(({"bush","bushes"}),"They are next to the path.\n");
  AddDetail(({"path","small path"}),QueryIntLong());
  AddDetail(({"tower","shimmering tower","administration tower"}),
"It is the administration tower of Nightfall.\n");
  AddDetail(({"bottom","ground","floor"}),
"You stand on it.\n");
  AddExit("northwest",CITY("boul2"));
  AddExit("northeast","./arounde2");
}
