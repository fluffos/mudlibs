
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
    "There are several low tables with shelves around the walls of this house. "
    "Cushions on the floor look as if they've been used for sitting. "
    "A small stove sits in one back corner, opposite a ladder that climbs "
    "up to a modest loft."
  );
  set_items(([
    "tables" : "Three tables stand near the walls. They are low to the ground "
      "and have shelves on them.",
    "cushions" : "They are earthy greens and browns, with rounded indents in "
      "their centers.",
    "stove" : "The stove is empty of wood and has nothing on top of it.",
    "ladder" : "The flat steps of the ladder allow one to climb up to the "
      "loft above.",
    "shelves" : "The shelves are basic wooden planks connected at their ends. "
      "A few odds and ends are stored on them.",
    "loft" : "The loft is a modest overhead area.",
  ]));
  set_touch("stove", "It is cool to the touch.");
  set_touch("cushions", "They feel like they are stuffed with feathers.");
  set_smell("stove", "It smells faintly of burnt wood.");
  set_exits(([
    "up":VPROOMS"house13_7_loft",
    "out":VPROOMS"town13_7"
  ]));
  load_object(query_exit("out"));
}

void reset() {
  ::reset();
  if (!present("satyr"))
    new(MOBS"satyr")->move(this_object());
}

