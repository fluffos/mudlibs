#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/base";

int boneExists;

void create() {
  ::create();
  set_property("forest", 1);
  set_short("%^GREEN%^A dense jungle.");
  set_long("%^GREEN%^A dense forest. "
    "The forest becomes so dense here that it blocks off the path to the north, leaving the only exit to the south. Trees and foliage crowd in upon the path from every direction.");
  set_exits( ([
    "south" : DRAG_ROOMS"py/6",
  ]) );
  set_items( ([
    "trees" : "Extremely tall trees that block out the sky.",
    "forest" : "It feels like it's closing in on you.",
    "foliage" : "There is a good amount of foliage nestled amongst the trees.",
    "path" : "It is made up of dirt and rocks, which collects into a small pile below you. It is choked off to the north, and continues through the forest to the south.",
    "pile" : "A pile of dirt in the center of the path.",
  ]) );
  boneExists = 1;
}

void init() {
  ::init();
  add_action("dig_bone", ({"dig", "search"}));
}

int dig_bone(string str) {
  if(str != "path" && str != "pile" && str != "up path" && str != "up dirt")
    return notify_fail("You cannot dig that.\n");
  if(!boneExists)
    return notify_fail("You are unable to find anything within the pile of dirt.\n");

  boneExists = 0;
  new(DRAG_ITEMS"bone")->move(this_player());
  write("You find a bone within the dirt!");
  return 1;
}
