#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Grandma's bedroom");
  SetIntLong(
"You've entered grandma's bedroom. Are you sure that you should be here?\n"
"A large bed stands in the centre of the room, but it looks like a wild beast "
"would have slept in it.\n");
  SetIndoors(1);
  SetBright(20);
  AddDetail(({"room","bedroom","grandma's bedroom"}),#'IntLong);
  AddDetail(({"bed","large bed","grandma's bed"}),
"The bed is a mess. Everything is screwed up. There are some clawprints of a "
"wild beast on the pillows. Perhaps you should try to investigate what has "
"happened?\n");
  AddDetail(({"handmade pillow","handmade pillows","pillow","pillows"}),
"Beautiful handmade pillows. But they are full of scratches and dirt in the "
"moment.\n");
  AddDetail("under bed",
"You find nothing special under the bed.\n");
  AddDetail(({"scratches","scratch"}),
"As you look more carefully, you get sure that these are the scratches a wolf "
"would make.\n");
  AddDetail(({"clawprints","clawprint","print","prints"}),
"Looks as if either a wolf or a large dog turned the bed upside "
"down short time ago.\n");
  AddDetail("dirt",
"It's quite unusual that grandma leaves such a mess behind.\n");
  AddExit("south","./hutentry");
}
