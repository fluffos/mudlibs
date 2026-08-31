
#include <std.h>
#include <saahr.h>
#include <rest.h>

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
    "A small living area inside this dark house is dominated by "
    "a short, wide table near the center. A shuttered window in the "
    "wall beside the door is partially obstructed by the stove. "
    "A low pallet in the far corner serves as a bed. Aside from "
    "the basics, the house is pretty bare."
  );
  set_items(([
    "table" : "The table is empty aside from a small incense burner, "
      "which is dirty and unlit.",
    "window" : "The window is covered by shutters.",
    "stove" : "A small stove made of cast iron.",
    "pallet" : "Wooden slats covered with a grass-stuffed mattress.",
  ]));
  set_exits(([
    "out":VPROOMS"town14_7"
  ]));
  load_object(query_exit("out"));
}

void reset() {
  ::reset();
  if (!present("nymph")) {
    object ny = new(MOBS"nymph");
    ny->move(this_object());
    ny->set_rest_type(SIT);
  }
}
