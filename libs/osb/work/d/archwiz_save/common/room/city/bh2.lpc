inherit "std/room";
#include "path.h"

create() {
  ::create();
  SetIntShort("A path");
  SetIntLong(
"Through the bushes to the southeast you can see a grating. The path "
"continues to the northeast.\n");
  SetIndoors(0);
  AddDetail(({"iron grating","grating"}),"It is made of iron.\n");
  AddDetail("iron","A substance used by smithes.\n");
  AddDetail(({"bushes","bush"}),
"There's a grating hidden behind the bushes.\n");
  AddExit("northeast","./bh1");
  AddExit("southeast","./clearing1");
}
