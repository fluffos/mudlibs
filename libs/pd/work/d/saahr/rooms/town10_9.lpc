
#include <std.h>
#include <saahr.h>

inherit HOUSE_ROOM;

void create() {
  ::create();
  set_properties(([
    "light":2,
    "night light":1,
    "indoors":0,
    "town":1
  ]));
  set_short("a small town");
  set_long(
    "A flowerbed lines on one side of the path here. "
    "A small but tidy looking house sits just a little back from "
    "the main road. The chimney on top smokes lightly."
  );
  set_items(([
    "flowerbed" : "It holds a few yellow flowers.",
    "house" : "The house has two large windows on the front "
      "and a covered porch.",
    "porch" : "Covered against the rain, the porch has a "
      "couple chairs and a table.",
    "windows" : "There are curtains on the inside of the windows "
      "which block your view.",
    "chimney" : "A brick chimney sticks out from the top of "
      "the wooden house, with a thin trail of wood smoke "
      "slowly drifting away.",
  ]));
  set_exits(([
    "north":VPROOMS"town10_8",
    "east":VPROOMS"town11_9",
    "northwest":VPROOMS"town9_8",
    "enter house":VPROOMS"house10_9"
  ]));
  check_door();
}


