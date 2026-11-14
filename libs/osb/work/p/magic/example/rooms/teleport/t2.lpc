inherit "/std/room";
#include <properties.h>
#include <rooms.h>

void create() {
  (::create());

  SetIntShort("Teleport testing and example room (t2)");
  SetIntLong(
"You are in a teleport testing and example room. "
"No teleports allowed here. Neither into nor out.\n"
"To forbid all teleports into or from a room you have to insert\n"
"  SetTPort(TPORT_NO)\n"
"An example is this room.\n");
  AddExit("east","./t1");
  
/* This is the all what must be done to prevent telep. into or from a room:*/

SetTPort(TPORT_NO);  

}
