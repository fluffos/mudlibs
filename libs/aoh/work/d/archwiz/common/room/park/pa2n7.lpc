#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Mother Rabbit Area");
  SetIntLong(
"There are several trees that been struck by lightning. "
"A couple of logs are laying on the forest floor which "
"are acting as a hiding place for animals from their enemy.\n");
  SetIndoors(0);
  AddDetail(({"trees","tree","old trees","old tree","trunk"}),
"There are several old trees that been struck by lightning.\n");
  AddDetail(({"logs","log"}),
"There are a couple of logs laying on the ground.\n");
  AddDetail(({"place","hiding place"}),
"There are rabbits hiding between the logs.\n");
  AddDetail(({"rabbit","animals","animal","rabbits"}),
"They hide between the logs.\n");
  AddExit("west","./pa3n7");
  AddExit("east","./pa1n7");
  AddExit("north","./pa2n6");
  AddItem(MONSTER("park/mrabbit"),REFRESH_HOME,2);
}
