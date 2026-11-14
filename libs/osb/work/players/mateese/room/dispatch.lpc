/* Dispatch Room
** From here I can go (almost) everywhere I want to in Nightfall.
*/

#include "/players/mateese/mydefs.h"
#include <properties.h>
#include <moving.h>
#include <rooms.h>
#include <stdrooms.h>

#define AP "/d/archwiz/common/"
#define ACP "/d/archwiz/common/city/"

inherit "/std/room";

create() {
  room::create();
  SetIntLight(1);
  SetIntShort("Enlighted void");
  SetIntLong (
"You are floating in the void, which is enlighted out of itself.\n"+
"Above you can see a home.\n"
             );
  AddExit ("up",     MR+"home");
  AddExit ("church", CHURCH);
  AddExit ("tower",  CENTER);
  AddExit ("lpc",    AP+"lpc/office");
  Set(P_TPORT, TPORT_OUT);
  Set(P_INDOORS, 0);
}

init() {
  room::init();
  if (!PL_WLEVEL) {
    write ("Your environment flickers and reappears.\n");
    this_player()->move(CHURCH, M_TELEPORT);
  }
}
