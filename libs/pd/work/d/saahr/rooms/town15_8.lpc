
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
    "The forest to the east ends abruptly here, just a stone's throw "
    "from the back side of a house. A light grass is peppered all over "
    "the ground. A small town spreads to the west, surrounded by the tall "
    "trees of the forest. Several chimneys are letting out thin plumes of "
    "smoke."
  );
  set_items(([
    "forest" : "The forest surrounds the town.",
    "house" : "It is a sturdy building made entirely of wood. "
      "The roof slants steeply down on either side, and the two "
      "windows are dark.",
    "grass" : "Wispy green that is dotted around the area.",
    "town" : "Several other houses are visible in the town, as well "
      "as some walking paths.",
    "chimneys" : "Mostly brick constructions, several are emitting puffs "
      "of smoke."
  ]));
  set_exits(([
    "east":VPROOMS"f16_8",
    "southwest":VPROOMS"town14_9",
    "west":VPROOMS"town14_8",
    "northwest":VPROOMS"town14_7",
    "enter house":VPROOMS"house15_8"
  ]));
  check_door();
}


