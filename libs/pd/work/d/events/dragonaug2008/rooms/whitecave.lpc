
#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties( ([
    "light" : 1, "night light" : 0, "indoors" : 1, "mountain" : 1,
  ]) );
//  set_short("a cave");
  set_short("%^BOLD%^Realm of the White Dragon%^RESET%^");
  set_long(
    "%^BOLD%^Realm of the White Dragon%^RESET%^\n"
    "The inside of the cave is enormous, easily holding eight or nine "
    "full sized dragons at a time. Round patches dot the floor where "
    "stalagmites were cleared away long ago. The walls and ceiling are "
    "mostly rough stone, but there are many smooth indentations in the "
    "floor, mostly near the walls. On the back wall, a crystalline "
    "formation in the shape of a dragon seems to be hung."
  );
  set_items( ([
    "cave" : "A very large cave which is all around you.",
    "patches" : "They are different colors and have a slightly different "
      "grain from the rock around them.",
    "floor" : "All solid rock, some smooth, some rough.",
    "walls" : "Solid rock.",
    "ceiling" : "It is hard to see, as it is very far above.",
    "indentations" : "They are just about the right size for a dragon "
      "to lie down in.",
    ({ "back wall", "wall" }) : "The back wall has a crystalline formation "
      "on it, but is otherwise unremarkable.",
    ({ "formation", "crystal", "crystalline formation" }) :
      "On closer inspection, the crystal is part of the wall itself!\n"
      "It is in the form of a dragon, as seen from above, "
      "with its wings spread.",
  ]) );
  set_exits( ([
    "west" : DRAG_ROOMS+"whitecaveoutside",
  ]) );
}

void reset() {
  int i = random(4);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("white dragon "+i))) {
    ob = new(DRAG_MOBS+"whitedragon");
    ob->move(this_object());
  }

  if(!present("microphone")) {
    ob = new("/wizards/pyro/personal/microphone");
    if(ob) {
      ob->set_microphone_name(path_file(file_name(this_object()))[1]);
      ob->set_owner(DRAG_D);
      ob->set_invincible(1);
      ob->move(this_object());
    }
  }
}

