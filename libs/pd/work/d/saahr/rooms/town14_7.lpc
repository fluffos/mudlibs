
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
    "Surrounded by light grasses, a house sits quietly against the forest's "
    "edge here. A large window on the front of the house is covered "
    "by a pair of shutters."
  );
  set_items(([
    "grasses" : "Wispy greens sprinkled around the ground.",
    "house" : "A stately looking house, painted brown and white.",
    "window" : "It would give a great view if it weren't covered.",
    "shutters" : "Heavy wooden shutters that are latched from the inside.",
  ]));
  set_listen("default", "Birds chirp all around.");
  set_exits(([
    "southeast":VPROOMS"town15_8",    
    "south":VPROOMS"town14_8",    
    "west":VPROOMS"town13_7",
    "enter house":VPROOMS"house14_7"
  ]));
  check_door();
}


