#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("dead end");
  SetIntLong("This is a dead end. Bones cover the floor. "
"There is a sign at the wall.\n");
  AddDetail(({"bones","bone","pirate bone","pirate bones"}),
    "The bones are milky white. You think that they must either be from "
"another adventurer like you or from one of the pirates. "
"They form the letters 'SW'.\n");
  AddDetail("sign","You should try to read it.\n");
  AddReadMsg("sign",
"As the pirate king has said, the third is passion if you have love and live.\n");
  AddExit("north","./doorx");
}
