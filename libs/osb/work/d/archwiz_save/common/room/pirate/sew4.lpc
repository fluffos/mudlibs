#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("city sewers");
  SetIntLong(
"You're at an exit. You see the ocean below. At least... Fresh air.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"exit","sewers","sewer","city sewers"}),QueryIntLong());
  AddDetail(({"ocean","blue ocean","wide ocean",
  "blue sea","sea","wide sea","wide blue sea",
  "wide blue ocean"}),
"This is the wide blue Sea.\n");
  AddDetail(({"air","fresh air"}),"It is fresh.\n");
  AddDetail(({"walls","wall","floor","ground","ceiling"}),
"Looks quite normal.\n");
  AddExit("west","./sew3");
  AddExit("east",CITY("sea"));
}
