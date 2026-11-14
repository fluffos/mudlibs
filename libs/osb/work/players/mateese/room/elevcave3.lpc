/* Tunnel leading to Elevator 3 */

#include "/players/mateese/mydefs.h"

#include <properties.h>
#include <rooms.h>

inherit "/std/room";

create() {
  room::create();
  SetIntShort("A tunnel");
  SetIntLong(
"You are in a dark tunnel leading east, dimly lit through a hole above.\n"
             );
  AddExit ("east", MR+"elevcave2");
/* AddExit ("up", MR+"dp/hmountbot"); */
  AddExit ("up", "/d/archwiz/common/lpc/entrance");
  /* SetIntLight(1); */
  Set(P_INDOORS, 1);
}
