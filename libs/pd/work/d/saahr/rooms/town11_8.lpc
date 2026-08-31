
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
    "An open field fills the area here, with a house sitting in the "
    "middle. Most of the ground looks well traveled. "
    "To the east a raised area of some sort can be seen."
  );
  set_items(([
    ({ "ground", "field" }) : "Very short grass and a few stunted flowers, "
      "all packed down from being walked on.",
    "house" : "The house is square, wooden, and very unremarkable.",
    "east" : "A raised platform is visible from here.",
  ]));
  set_listen("default", "Birds tweet quietly somewhere above.");
  set_exits(([
    "north":VPROOMS"town11_7",
    "east":VPROOMS"town12_8",
    "south":VPROOMS"town11_9",
    "west":VPROOMS"town10_8",
    "enter house":VPROOMS"house11_8"
  ]));
  check_door();
}


