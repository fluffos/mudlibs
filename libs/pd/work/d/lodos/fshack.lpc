#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Inside an old shack");
   set_property("light", 2);
   set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
   set_long("You are inside of a small and untidy shack. The walls have "
      "a few small holes in them. The roof is thached with straw. "
      "Old pots and pans litter the ground. A fire has been lit in the "
      "fireplace.");
   set_items(([
      "shack" : "The shack is generally unkept.",
      "holes" : "A few holes in the roof and walls.",
      ({ "pots", "pans" }) : "They are spread out across the ground.",
      ({ "fireplace", "fire" }) : "The fire looks warm and cozy."
   ]));
   set_exits(([ "north" : ROOMS"etown6" ]));
}

void reset() {
 ::reset();
   if (!present("centaur"))
     make(MOB"centaur");
   if (!present("artrell"))
     make(MOB"artrell");
   if (!present("warrior"))
     make(MOB"hdragon");
   if (!present("ogre"))
     make(MOB"ogre");
   if (!present("throk"))
     make(MOB"throk");
}

void init() {
 ::init();
   if (this_player()->query_name() == "llama")
    if (present("throk", this_object()))
     present("throk", this_object())->force_me("say Hey! Throk want trade "
       "monies for llama! Throk want llama back, Throk train.");
}
