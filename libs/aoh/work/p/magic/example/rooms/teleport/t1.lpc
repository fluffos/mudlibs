inherit "/std/room";
#include <properties.h>
#include <rooms.h>

void create() {
  (::create());

  SetIntShort("Teleport testing and example room (t1)");
  SetIntLong(
"You are in a teleport testing and example room. "
"All teleports are allowed here.\n"
"Allowing all teleport is default of a room. Nothing must be changed. "
"An example is this room.\n");
  AddExit("east","./t4");
  AddExit("north","./t3");
  AddExit("west","./t2");
  AddExit("south","../d_hallway");
}
