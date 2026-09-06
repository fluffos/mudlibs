/* This room (and all adjacent) refer to the noice of the central C.A.R.T.
 * station. Of course, the C.A.R.T. is not in use anymore...
 */

#include "path.h"
#include <moving.h>

inherit "/std/room";

int east() {
  if (!this_player()) return 0;
  if (this_player()->QueryLevel()<10) return notify_fail(
    "You don't dare to enter this place. (At least not now)\n"),0;
  if (!query_once_interactive(this_player())) return 0;
  write("You step into the adjacent room and suddenly ...\n\n"
"The floor vanishes under your feet !\n"
"You enter a downleading chute.... Hey thats funny, you think.\n"
"The chute has many left'n right bends. You can't see where it leads.\n"
"You pass a magic force field.\n"
"Then, suddenly, you fall into a room. OUCH !\n\n");
  this_player()->move(PIRATE("cell"),M_GO,"east");
  return 1;
}

create() {
  ::create();
  SetIntShort("a noisy and dark tunnel");
  SetIntLong(
"You're in a tunnel. You hear rumbling noises from above. You must be "
"directly under the central C.A.R.T. station! You hope that the ceiling "
"will not crash down in this very moment. "
"To the north a small passage is built into the wall. "
"The way to the east is very dark. The walls seem to absorb the light.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"tunnel","noisy tunnel","dark tunnel","noisy and dark tunnel",
  "noisy dark tunnel"}),#'IntLong);
  AddDetail(({"noise","rumbling","rumbling noises","noises","rumbling noises"}),
"It is extremely loud here.\n");
  AddDetail(({"passage","small passage"}),
"It seems to be more quiet there.\n");
  AddDetail(({"ceiling"}),"It seems to vibrate.\n");
  AddDetail(({"walls","wall","floor","ground"}),
"You see nothing special.\n");
  AddDetail(({"way","east","way to the east"}),
"It looks not like a good place to be.\n");
  SetIntNoise("It is loud in here.\n");
  AddExit("west","./dark6");
  AddExit("east",#'east);
  AddExit("north","./downch1");
}
