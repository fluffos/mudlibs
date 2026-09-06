inherit "/std/room";
#include <properties.h>
#include <rooms.h>

void create() {
  (::create());

  SetIntShort("Teleport testing and example room (t4)");
  SetIntLong(
"You are in a teleport testing and example room. "
"No teleports out of this room are allowed here.\n"
"To forbid all teleports out of a room you have to insert\n"
"  SetTPort(TPORT_IN)\n"
"An example is this room.\n");
  AddExit("west","./t1");
  
/* This is the all what must be done to prevent telep. from a room:
   TPORT_IN Means that all you only allowed to teleport into this room*/

SetTPort(TPORT_IN);

}
