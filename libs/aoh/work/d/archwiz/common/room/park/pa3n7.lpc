#include "path.h"
#include <rooms.h>

inherit "/std/room";

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
  show(capitalize(this_player()->QueryName())+" drinks some water from the "
    "pond and looks refreshed afterwards.\n");
  return 1;
}

create() {
  ::create();
  SetIntShort("Father Fox Area");
  SetIntLong(
"A small pond is in the shade.  This is the area where all "
"the animals in the forest comes to drink.\n");
  SetIndoors(0);
  AddDetail(({"pond","small pond"}),
"You wonder if you could drink the water.\n");
  AddDetail("area",#'IntLong);
  AddRoomCmd("drink",#'do_drink);
  AddExit("west","./pa4n7");
  AddExit("east","./pa2n7");
  AddExit("north","./pa3n6");
  AddItem(MONSTER("park/fatherfox"),REFRESH_HOME);
}
