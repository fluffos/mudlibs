
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
    "Heavy logs have been stacked to create a large cabin here. "
    "A rocking chair sits on the porch facing west. A few flowers "
    "sprout near the cabin's base, but most of the ground is bare. "
    "The main path circles around the house and goes in every direction."
  );
  set_items(([
    "logs" : "Dark wood, notched and stacked together to form a cabin.",
    "cabin" : "It seems rather large. A window can be seen on one side.",
    "window" : "The window faces south. A shelf can be seen inside.",
    "shelf" : "It is too hard to make out anything on it from here.",
    "chair" : "The chair looks like it was carved by hand.",
    "porch" : "A nice covered addition to the front of the cabin.",
    "flowers" : "Blue and yellow wildflowers.",
    "ground" : "The ground is mostly bare dirt.",
  ]));
  set_exits(([
    "north":VPROOMS"town13_7",
    "east":VPROOMS"town14_8",
    "south":VPROOMS"town13_9",
    "west":VPROOMS"town12_8",
    "enter house":VPROOMS"house13_8"
  ]));
  check_door();
}


