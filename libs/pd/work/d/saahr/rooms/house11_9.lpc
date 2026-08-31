
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
    "A small fireplace sits against one wall, with a lit fire warming "
    "the house. Across from it is a long table and two chairs. In the back, "
    "a ladder leads up through a hole in the floor of the loft above. Around "
    "the ladder are small shelves and sacks holding food and other supplies."
  );
  set_items(([
    "fireplace" : "A brick enclosure to hold a fire, it looks like "
                  "it was made of mud bricks.",
    "fire" : "A bright fire burns, warming the house.",
    "table" : "Just a plain wooden table with nothing on it.",
    "chairs" : "Two chairs sit on adjacent sides of the table.",
    "ladder" : "The ladder is sturdy and looks well-used.",
    "loft" : "A wide area above the main part of the house.",
    "shelves" : "They hold spices, eggs, and some dried meat.",
    "sacks" : "The sacks are full of grain.",
  ]));
  set_exits(([
    "up":VPROOMS"house11_9_loft",
    "out":VPROOMS"town11_9"
  ]));
  load_object(query_exit("out"));
}

void reset() {
  ::reset();
  if (!present("nymph"))
    new(MOBS"nymph")->move(this_object());
}
