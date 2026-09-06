#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Raven Holding");
  SetIntLong(
"Sounds of the raven cries are everywhere in the sky. "
"There is some white stuff on the floor.  What is it? "
"You feel something evil in the air.\n");
  SetIndoors(0);
  SetIntNoise("KRAH!!!! KRAH!!!!!\n");
  AddNoise(({"cries","cry"}),
"It's loud.\n");
  AddDetail(({"stuff","white stuff"}),
"It looks like the birds s***.\n");
  AddExit("west","./pa3n2");
  AddExit("east","./pa1n2");
  AddExit("south","./pa2n3");
  AddExit("north","./pa2n1");
  AddItem(MONSTER("park/raven"),REFRESH_HOME,3);
}
