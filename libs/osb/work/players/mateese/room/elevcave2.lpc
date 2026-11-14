/* Tunnel leading to Elevator 2 */

#include "/players/mateese/mydefs.h"

#include <properties.h>
#include <rooms.h>

inherit "/std/room";

create() {
  room::create();
  SetIntShort("A tunnel");
  SetIntLong(
"You are in a long dark tunnel, turning from west to north.\n"
             );
  AddExit ("north", MR+"elevcave");
  AddExit ("west", MR+"elevcave3");
  SetIntLight(0);
  Set(P_INDOORS, 1);
}
