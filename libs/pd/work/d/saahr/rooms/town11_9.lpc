
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
    "A little green house rises from the grass here, with a row of trees "
    "growing closely together behind it. Some benches sit in front of the "
    "house, surrounded by brightly colored flowers."
  );
  set_items(([
    "house" : "The house is mostly green with a little white trim. "
      "It has two windows on the front and is rather squarish.",
    "grass" : "Lots of grass covers the ground.",
    "trees" : "The trees seem to be growing right at the top of a "
      "river bank.",
    ({ "bank", "river bank" }) : "It is very steep and goes down pretty far. "
      "Too dangerous to climb down.",
    "benches" : "Wooden benches that have been painted bright white. "
      "There are two of them, and each can hold two or three people.",
    "flowers" : "Several varieties of flowers brighten up the yard.",
  ]));
  set_exits(([
    "north":VPROOMS"town11_8",
    "northeast":VPROOMS"town12_8",
    "east":VPROOMS"town12_9",
    "west":VPROOMS"town10_9",
    "enter house":VPROOMS"house11_9"
  ]));
  check_door();
}


