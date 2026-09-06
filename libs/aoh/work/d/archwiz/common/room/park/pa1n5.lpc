#include <rooms.h>
#include "path.h"

inherit "std/room";

int do_drink(string str) {
  string what,where;
  if (!this_player()) return 0;
  if ((!str) || (sscanf(str,"%s from %s",what,where)!=2)) return
    notify_fail("Drink what from where?\n"),0;
  if (what!="water") return notify_fail("There's only water around.\n"),0;
  if (where!="pond") return notify_fail("Perhaps drink from the pond?\n"),0;
  if ((this_player()->QueryMaxDrink())-(this_player()->QueryDrink())<10)
    this_player()->SetDrink(this_player()->QueryMaxDrink());
  else this_player()->SetDrink(this_player()->QueryDrink()+10);
  write("You feel refreshed.\n");
  show(capitalize(this_player()->QueryName())+" drinks some water from the\n"
    "pond and looks refreshed afterwards.\n");
  return 1;
}

create() {
  ::create();
  SetIntShort("Ground Hogs Playground");
  SetIntLong(
"This is the playground of the frogs. You see a "
"little pond where they are playing.\n");
  AddDetail(({"playground","play ground"}),#'IntLong);
  AddDetail(({"pond","small pond"}),
"A small pond with some frogs in it.\n");
  SetIndoors(0);
  AddRoomCmd("drink",#'do_drink);
  AddExit("west","./pa2n5");
  AddExit("south","./pa1n6");
  AddExit("north","./pa1n4");
  AddItem(MONSTER("park/frog"),REFRESH_HOME,3);
}
