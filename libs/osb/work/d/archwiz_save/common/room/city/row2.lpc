#include "path.h"
inherit "std/room";

create() {
  ::create();
  SetIntShort("Skid Row");
  SetIntLong(
"You are on Skid Row. There are filthy street thugs all over the place. "
"You'd better guard your wallet. Skid Row runs east and a bridge  "
"crosses the stream that flows through Nightfall to the west.\n");
  AddDetail("wallet", "It's still there. Phew!\n");
  AddDetail(({"thugs", "thug" }),
"Filthy and looking non-to-friendly, they stay on distance. Yet.\n"
	   );
  AddExit("east", "./row3");
  AddExit("west", "./row1");
  SetIndoors(0);
}
