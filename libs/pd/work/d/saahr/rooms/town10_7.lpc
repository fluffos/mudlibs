
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
    "A few shrubs and some grass lie on the sides of the path. "
    "On the north side is a house. There are no plants visible around "
    "the house, and no obvious windows either."
  );
  set_items(([
    "shrubs" : "Average shrubs that have been trimmed at some point.",
    "grass" : "The grass is scraggly from being walked on a lot.",
    "path" : "A packed dirt path that leads around the town.",
    "house" : "It's a plain looking wooden house with a door."
  ]));
  set_exits(([
    "enter house":VPROOMS"house10_7",
    "east":VPROOMS"town11_7",
    "south":VPROOMS"town10_8",
    "southwest":VPROOMS"town9_8"
  ]));
  check_door();
}

