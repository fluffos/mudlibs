#include "path.h"

inherit "std/room";

create() {
  ::create();
  SetIntShort("Ruins of the Psionics' Guild");
  SetIntLong(
"This once was the entrance hall to the Guild of Psionics. "
"Above you see the sky, even the walls are broken down. You get "
"a sad feeling, seeing all this devastation.\n"
"The ruins stretch forth to the south, but you can as well leave "
"this place to the north.\n"
            );
  AddDetail(({"wall","walls"}),"The walls are all broken down.\n");
  AddDetail(({"ruin","ruins"}),"There is nearly no stone unturned here.\n");
  AddExit("north",CITY("southave3"));
  SetIndoors(0);
}
