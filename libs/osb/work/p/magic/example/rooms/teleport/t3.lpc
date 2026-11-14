inherit "/std/room";
#include <properties.h>
#include <rooms.h>

void create() {
  (::create());

  SetIntShort("Teleport testing and example room (t3)");
  SetIntLong(
"You are in a teleport testing and example room. "
"No teleports into this room allowed.\n"
"To forbid all teleports in a room you have to insert\n"
"  SetTPort(TPORT_OUT)\n"
"An example is this room.\n");
  AddExit("south","./t1");
  
/* This is the all what must be done to prevent teleports in a room:
   TPORT_OUT means that yo uare only allowed to teleport out of this room*/

SetTPort(TPORT_OUT);  

}
