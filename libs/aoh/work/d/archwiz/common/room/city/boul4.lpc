inherit "/std/room";
#include "path.h"
#include <rooms.h>

void create() {
  ::create();
  SetIntShort("Sunset Boulevard");
  SetIntLong(
"You are walking along Sunset Boulevard. Looking south, you notice the "
"buildings become more and more shabby. The street isn't cleaned as often "
"as further to the north. Your hand automatically checks if your wallet is "
"still there. \n");
  AddDetail("wallet", "It's still there. Phew!\n");
  AddExit("north", "./boul3");
  AddExit("south", "./row3");
  SetIndoors(0);
}
