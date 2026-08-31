
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
    "This log cabin-style house is completely square in shape, "
    "with pleasantly rounded and notched logs making up the walls. "
    "There are a few windows dotted about as well. The usual assortment "
    "of food and cooking implements lie tidily in a front corner. "
    "Beneath a side window are two small beds with a nightstand "
    "between them."
  );
  set_items(([
    ({ "logs", "walls" }) : "The logs are notched at the ends "
      "and laid on top of each other to create sturdy walls, then "
      "filled in with some kind of insulating material.",
    ({ "window", "side window", "windows" }) : "Plain, square "
      "glass windows to let the light in.",
    "food" : "Dried meat, a loaf of bread, and some fruits and nuts.",
    ({ "cooking implements", "implements" }) : "Just some pots and pans.",
    "corner" : "It has some food and cooking implements lying in it.",
    "beds" : "Each bed is large enough for one person.",
    "nightstand" : "A small table.",
  ]));
  set_smell("default", "The log walls smell fresh and woody.");
  set_exits(([
    "out":VPROOMS"town11_7"
  ]));
  load_object(query_exit("out"));
}

void reset() {
  ::reset();
  if (!present("nymph"))
    new(MOBS"nymph")->move(this_object());
  if (!present("satyr"))
    new(MOBS"satyr")->move(this_object());
}

