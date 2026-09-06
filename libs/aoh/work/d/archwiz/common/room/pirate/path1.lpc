#include "path.h"
#include <moving.h>

inherit "/std/room";

int go_west() {
  if (!this_player()) return 0;
  if (!query_once_interactive(this_player())) return 1;
  this_player()->move(CITY("field"),M_GO,"west");
  return 1;
}

create() {
  ::create();
  SetIntShort("a small path");
  SetIntLong(
"You're travelling on a small path. Far to the east you see the shoreline "
"of the ocean. Bees are flying around and birds are singing everywhere.\n");
  SetIntNoise("You hear the bees humming and the birds singing.\n");
  AddNoise(({"bees","bee","humming"}),
"You hear the humming of the bees.\n");
  AddNoise(({"bird","birds","singing"}),
"You hear the birds singing.\n");
  AddDetail(({"path","small path"}),"It leads east/west.\n");
  AddDetail(({"shoreline","shore","beach"}),
"The shoreline of the ocean is far to the east.\n");
  AddDetail(({"ocean","sea","blue ocean","blue sea"}),
"Far to the east you see the blue ocean.\n");
  AddDetail(({"bee","bees"}),"The bees are humming around.\n");
  AddDetail(({"bird","birds"}),
"Different birds are to be seen. The fly around and seem to like this place.\n");
  AddDetail(({"place"}),QueryIntLong());
  SetIndoors(0);
  AddExit("west",#'go_west);
  AddExit("east","./path2");
}
