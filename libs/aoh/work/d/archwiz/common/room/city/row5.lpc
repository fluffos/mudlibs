#include "path.h"
inherit "std/room";

/* Here the Advent area was intended to begin. However, it ended up in
 * old CART tunnel "yellow", but I like to keep this remnant.
 */
try_south() {
  write("After a few steps south, you notice that the path suddenly ends.\n");
  write("You decide to stay on Skid Row.\n");
  if (!this_player()) return 0;
  say(this_player()->QueryName()+" walks south a few steps and returns.\n");
  return 1;
}

void create() {
  ::create();	
  SetIntShort("Skid Row");
  SetIntLong(
"Skid Row was once a booming small business area but now "
"all the store-fronts are boarded up and decaying. "
"A small path leads south through some former stores into "
"the forest. Another dirty road leads to the north.\n");
  AddExit("east", "./row6");
  AddExit("west", "./row4");
  AddExit("north",RANDY("plaza2"));
  AddExit("south",#'try_south);
  HideExit("south",1);
  SetIndoors(0);
}
