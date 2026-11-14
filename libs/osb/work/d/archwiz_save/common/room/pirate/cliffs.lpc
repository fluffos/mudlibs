#include <rooms.h>
#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("On a cliff");
  SetIntLong(
"You're standing on the top of a high cliff. The Ocean is deep down below. "
"Seagulls are flying high in the air.\n");
  AddDetail(({"seagull","seagulls"}),"They are hovering high in the air.\n");
  AddDetail(({"steep cliff","high cliff","cliff"}),
"It goes deep down here.\n");
  AddDetail(({"top","top of the cliff"}),QueryIntLong());
  AddDetail(({"ocean","sea","blue ocean","blue sea","wide sea","wide ocean",
  "wide blue sea","wide blue ocean"}),
"It is just the wide blue Sea.\n");
  SetIndoors(0);
  AddExit("north","./cliff");
  AddExit("southeast","./endcliff");
  AddItem(MONSTER("pirateguy"),REFRESH_HOME);
}
