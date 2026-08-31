
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
    "A large oak tree rises into the sky here. Its branches spread out "
    "to cover a wide area of grass. Beneath the tree is a small cottage. "
    "Round windows dot every side of it."
  );
  set_items(([
    ({ "tree", "oak tree", "branches" }) :
      "The oak tree has many branches that create a lot of shade.",
    "grass" : "Thick green blades of grass that provide a nice place to sit.",
    "cottage" : "A simply built wooden house with lots of windows.",
    "windows" : "Oddly, they are all round.",
  ]));
  set_exits(([
    "east":VPROOMS"town14_7",
    "south":VPROOMS"town13_8",
    "southwest":VPROOMS"town12_8",
    "west":VPROOMS"town12_7",
    "enter house":VPROOMS"house13_7"
  ]));
  check_door();
}


