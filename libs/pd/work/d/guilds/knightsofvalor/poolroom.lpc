#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("The Repentence Chambers");
   set_long("This small room is alike the rest of the hall, surrounded by white bricks.  There is very little to this room, besides a pool sitting in the middle of it.  A %^BOLD%^%^YELLOW%^holy light%^RESET%^ floats in the air, beaming directly into the water, which pulsates with holy energy.  There are white stone steps leading into the pool.");
   set_properties(([ "no attack" : 1, "no magic" : 1, "no bump" : 1,
     "no steal" : 1, "no teleport" : 1, "indoors" : 1, "light" : 2 ]));
   set_items(([
     "pool"  :     "You could <repent> your sins, take a dip and see how it feels.",
     "water" :     "The waters are clear, except where a golden holy light shines in.",
     "steps" :     "Flawless white marble steps lead into the small pool.",
   ]));
   set_exits(([ "east" : "/d/guilds/knightsofvalor/hall" ]));
}

int repent(string str) {
   write("You descend the steps into the pool.");
   this_player()->move_player("/d/guilds/knightsofvalor/pool", "pool");
   return 1;
}

void init() {
 ::init();
   add_action("repent", "repent");
}

