
#include <std.h>
#include <saahr.h>

inherit ROOM;

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
    "A small stand of lemon and apple trees grows just beside "
    "the path. Bright grasses grow all around. Houses can be seen "
    "to the north and west, and a footbridge leads over the river "
    "and into the forest."
  );
  set_items(([
    "stand" : "Several trees growing only a few feet apart.",
    "trees" : "Lemons and apples hang from the upper branches.",
    "path" : "A well traveled dirt road.",
    "grasses" : "Thick and green, the grass covers the ground.",
    "houses" : "They are hard to see from here, but seem to be in "
      "different styles.",
    "river" : "It can just be seen below the bank, flowing "
      "east and west.",
    "footbridge" : "A sturdy bridge with tall side rails. It crosses "
      "southeast over the river.",
  ]));
  set_listen("default", "Running water can be heard faintly.");
  set_exits(([
    "north":VPROOMS"town13_8",    
    "east":VPROOMS"town14_9",    
    "west":VPROOMS"town12_9",    
    "northwest":VPROOMS"town12_8",
    "southeast":VPROOMS"f14_10",
  ]));
}


