#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Jetty");
  SetIntLong(
"You are at a jetty. The waves roll in from the east. A small path leads "
"back west towards the city.\n");
  AddDetail(({"waves","wave"}),"They roll the wide blue Sea.\n");
  AddDetail(({"sea","ocean","wide sea","wide ocean","blue sea","blue ocean",
	      "wide blue sea","wide blue ocean"}),"It looks wide.\n");
  AddDetail(({"jetty","peaceful jetty"}),"It looks peaceful.\n");
  AddDetail(({"path","small path"}),"It leads back towards the city to the west.\n");
  AddDetail(({"city","town","capital","nightfall city","nf city"}),"It's to the west.\n");
  AddExit("west", "./vill_shore2");
  AddExit("east", "./sea");
  AddItem("/obj/bag",REFRESH_REMOVE);
  SetIndoors(0);
}
