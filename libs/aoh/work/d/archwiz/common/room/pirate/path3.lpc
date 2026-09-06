#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a small path");
  SetIntLong(
"You're travelling on a small path. To the east you see a steep cliff and the "
"ocean beyond.\n");
  AddDetail(({"small path","path"}),QueryIntLong());
  AddDetail(({"cliff","steep cliff"}),
"It is a steep cliff. You wonder if there is any possibility to find a "
"way there.\n");
  AddDetail(({"ocean","sea","wide ocean","wide sea","wide blue sea",
  "wide blue ocean"}),
"It is the wide blue Sea.\n");
  SetIndoors(0);
  AddExit("west","./path2");
  AddExit("east","./cliff");
//  AddItem(MONSTER("harriet"),REFRESH_DESTRUCT);
}
