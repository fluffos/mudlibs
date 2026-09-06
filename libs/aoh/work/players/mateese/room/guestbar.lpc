/* Guest Bar */

#include "/players/mateese/mydefs.h"

#include <config.h>
#include <properties.h>
#include <rooms.h>

inherit "/std/room";

create() {
  room::create();
  SetIntShort ("Mateese's Guestroom");
  SetIntLong (
"You are in a dark, cold room. Obviously there hasn't been anyone here for\n"+
"long time.\n"+
"The only exit is west.\n"
              );
  AddExit ("west", MR+"mylobby");
  Set(P_INDOORS, 1);
  SetBright (MAX_SUNBRIGHT/20);
}


