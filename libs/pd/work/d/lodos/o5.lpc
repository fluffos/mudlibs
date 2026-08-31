#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Obstacle Course: Room 4");
   set_long("%^RESET%^%^ORANGE%^"
     "The bottom of this rock is getting fairly close to the lava "
     "pool. Jagged rocks make it possible to ascend this crag. Lava boils and "
     "spits onto the rock. The pool is much like a boiling lake. Lava bubbles "
     "float into the air and burst, throwing magma everywhere. The sky is an "
     "endless white space, streching as far as the eye can see, and even further "
     "then. A platform is visible further south, but is too far to jump onto.");
   set_items(([
     "platform": "It is further south in the lava pool, how you could get to it, "
                 "though, you have no clue.",
     "pool"    : "You are in a lava pool. This is the largest rock sticking out of "
                 "the lava, though there are others.",
     "rocks"   : "Several sharp rocks stick out of the lava. You are on the only "
                 "one of them that could possibly provide any real support. Enough "
                 "rocks stick out of the pool that you could hop on them over to "
                 "the southern platform.",
     "rock"    : "You stand on a large rock in the lava.",
     "lava"    : "A boiling pool of liquid hot magma.",
     "sky"     : "The sky is a white expanse as far as the eye can see."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "outdoors" : 1,
     "no bump" : 1, "no attack" : 1, "no magic" : 1, "no teleport" : 1,
     "no steal" : 1 ]));
   set_exits(([
     "up" : ROOMS"o4"
   ]));
}

void stop_hopping(object tp) {
   message("info", "You lunge from the last rock onto the platform.", tp);
   tp->move(ROOMS"o6");
}

int hop(string str) {
   if (!str || str != "rocks") return 0;
   write("You jump from rock to rock, trying desperatly not to slip into the "
     "pool.");
   this_player()->set_paralyzed(1, "You jump from rock to rock towards the "
     "platform.");
   call_out("stop_hopping", 1, this_player());
   return 1;
}

void init() {
 ::init();
   add_action("hop", "hop");
}
