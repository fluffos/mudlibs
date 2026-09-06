#include "path.h"
#include <moving.h>
#include <properties.h>
inherit "std/room";

dive() {
  object ob;
  if (!this_player()) return 0;
  if (!this_player()->Query(P_WATERBREATHING)) {
    ob = first_inventory(this_player());
    while(ob) {
      if (ob->IsObjBag()) {
        this_player()->move(CITY("sea_bottom"),M_GO,"down");
        return 1;
        }
      ob = next_inventory(ob);
      }
    write("You can't breathe under water !\n");
    write("You should try to get some portable air supply!\n");
    return 1;
    }
  return this_player()->move(CITY("sea_bottom"),M_GO,"down");
}

void create() {
  ::create();
  SetIntShort("All at sea");
  SetIntLong(
	     "You are swimming out at the sea. To the west you can see a jetty.\n");
  AddDetail(({"sea","blue sea","wide sea","wide blue sea",
    "ocean","wide ocean","blue ocean","wide blue ocean"}),
"You swim within the wide blue ocean.\n");
  AddDetail(({"water","clear water","saltwater"}),
"It is clear water.\n");
  AddDetail(({"jetty","wooden jetty"}),
"You see a wooden jetty to the west.\n");
  AddDetail(({"wood","wet wood"}),
"It is just the wet wood the jetty is made of.\n");
  AddExit("dive",#'dive);
  HideExit("dive",1);
  AddExit("west",    "./jetty2");
  SetIndoors(0);
}
