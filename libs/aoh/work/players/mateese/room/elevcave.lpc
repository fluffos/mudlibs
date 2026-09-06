/* Tunnel leading to Elevator */

#include "/players/mateese/mydefs.h"

#include <properties.h>
#include <rooms.h>

inherit "/std/room";

create() {
  room::create();
  SetIntShort("A tunnel");
  SetIntLong(
"You are in long tunnel, dimly lit by its phosphorizing walls.\n"+
"To the north you see some shimmering light, to the south is darkness.\n"
             );
  AddExit ("north", MR+"elevbot");
  AddExit ("south", MR+"elevcave2");
  /* SetIntLight(1); */
  Set(P_INDOORS, 1);
}

