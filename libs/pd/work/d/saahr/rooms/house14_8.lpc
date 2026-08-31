
#include <std.h>
#include <saahr.h>

inherit VAULT;

void create() {
  ::create();
  set_properties(([
    "light":2,
    "indoors":1,
    "town":1
  ]));
  set_short("inside a house");
  set_long(
    "A high ceiling creates a sense of openness inside this house. "
    "The windows near the tops of the walls let in a lot of light during "
    "the day, highlighting the bright colors on the walls and furnishings. "
    "Two beds, two tables, and half a dozen chairs take up the northwest "
    "section while a long couch and moderately sized kitchen make use of "
    "the rest of the space."
  );
  set_items(([
    "ceiling" : "The ceiling is only slightly pointed, and about fifteen "
      "feet high. Some lightweight tapestries have been stretched across it.",
    "tapestries" : "They are bright blue and green spiral designs.",
    "windows" : "Windows set into the upper portions of each wall allow "
      "sunlight to brighten the house.",
    "beds" : "The beds are each large enough for two. One has a bright "
      "yellow blanket and pillows, the other has green coverings.",
    "tables" : "Set with their sides touching, these tables are well-worn "
      "but clean. A candle sits in the center of each.",
    "chairs" : "The chairs have intricately carved wooden backs and cushions "
      "stuffed with grass.",
    "couch" : "The couch is long enough to sit three or four people at once. "
      "The purple covering is soft to the touch.",
    "kitchen" : "A stove and food storage area.",
  ]));
  set_exits(([
    "out":VPROOMS"town14_8"
  ]));
  load_object(query_exit("out"));
  set_inventory( ([
    MOBS"nymph" : 2,
    MOBS"satyr" : 2,
  ]) );
}

void reset() {
  ::reset();
}
