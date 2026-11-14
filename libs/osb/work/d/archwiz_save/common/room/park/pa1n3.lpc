/* original by Smeagol, reimplemented by Rover. */

#include <rooms.h>
#include "path.h"

inherit "std/room";

create() {
  ::create();
  SetIntShort("Dark Forest Full of Spiders");
  SetIntLong(
"The trees block the sun from reaching the forest floor. "
"There are spider webs hanging in the trees. Some of the "
"webs are touching your scalp. Your skin is crawling.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"forest","trees","tree","dark forest"}),
"This is the darker part of the famous city forest.\n");
  AddDetail("sun","You cannot see it here.\n");
  AddDetail(({"webs","web","spider webs","spider web","cobwebs",
    "cobweb"}),
"There are cobwebs everywhere in the trees.\n");
  AddExit("west","./pa2n3");
  AddExit("south","./pa1n4");
  AddExit("north","./pa1n2");
  AddItem(MONSTER("park/spider"),REFRESH_HOME,3);
}
