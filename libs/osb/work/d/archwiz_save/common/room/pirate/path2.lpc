#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a small path");
  SetIntLong(
"You're travelling on a small path. The vegetation vanishes to the east "
"where you can see the ocean. Some bushes grow next to the path.\n");
  AddDetail(({"path","small path"}),QueryIntLong());
  AddDetail(({"vegetation","plant","plants"}),
"There are some bushes near the path, but further to the east you "
"see less plants.\n");
  AddDetail(({"bush","bushes"}),
"They grow next to you.\n");
  AddDetail(({"sea","ocean","blue sea","blue ocean","wide ocean",
  "wide sea","wide blue ocean","wide blue sea"}),
"It is the wide blue Sea you see to the east.\n");
  SetIndoors(0);
  AddExit("west","./path1");
  AddExit("east","./path3");
}
