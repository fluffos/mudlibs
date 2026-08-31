
#include <std.h>
#include <saahr.h>

inherit ROOM;

void create() {
  ::create();
  set_properties(([
    "light":2,
    "indoors":1,
    "town":1
  ]));
  set_short("inside a house");
  set_long(
    "This loft is up near the ceiling, leaving only about four feet of "
    "vertical space. One large bed is spread out to take up much of the "
    "floor, with two smaller cushions across from it. A solid wall at the "
    "edge of the loft floor cuts it off from the rest of the house."
  );
  set_items(([
    "cushions" : "They are earthy greens and browns, with rounded indents in "
      "their centers.",
    "bed" : "A flat pallet style bed, stuffed with hay and feathers.",
    "ceiling" : "The sloped ceiling is very close overhead.",
    "floor" : "The same wood as used in the rest of the house, "
      "worn smooth from use.",
  ]));
  set_exits(([
    "down":VPROOMS"house13_7",
  ]));
}

void reset() {
  ::reset();
  if (!present("nymph"))
    new(MOBS"nymph")->move(this_object());
}

