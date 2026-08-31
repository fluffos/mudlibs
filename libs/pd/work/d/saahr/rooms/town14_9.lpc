
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
    "The river flows nearby beneath a tall willow tree. A small cottage "
    "sits in a bed of flowers. The path through this corner of the village "
    "loops around from the north to the west."
  );
  set_items(([
    "river" : "A clear river flows to the south.",
    ({ "tree", "willow", "willow tree" }) :
      "The willow tree is very large and droopy. Its small leaves cover "
      "a lot of the ground.",
    "cottage" : "The cottage is very humble. Its stained wooden exterior "
      "looks well worn by time and the elements.",
    "flowers" : "Small yellow and white flowers.",
    "path" : "The path is very small and seems rarely used.",
  ]));
  set_smell( ({ "default", "flowers" }),
    "A light, sweet scent is released by the flowers.");
  set_exits(([
    "north":VPROOMS"town14_8",
    "northeast":VPROOMS"town15_8",
    "west":VPROOMS"town13_9",
    "enter house":VPROOMS"house14_9"
  ]));
  check_door();
}


