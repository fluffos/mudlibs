#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("city sewers");
  SetIntLong("You're in the city sewers. There's a light to the east.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"sewers","city sewers"}),QueryIntLong());
  AddDetail(({"light","east"}),
"Probably you could leave the sewers to the east.\n");
  AddDetail(({"walls","wall","floor","ground","ceiling"}),
"You see nothing new.\n");
  AddExit("west","./sew2");
  AddExit("east","./sew4");
}
