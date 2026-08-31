#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Obstacle Course: Room 5");
   set_long("%^RESET%^%^ORANGE%^"
     "Stepping stones lead up to this platform. The closest platform to the "
     "lava yet, the heat and gravity are intense. All around this platform, except "
     "to the immediate south, the pool of lava boils. On the southern edge of the "
     "square platform is a stone wall. The wall looks much like the side of a "
     "very steep and very tall cliff.");
   set_items(([
     "wall"    : "The wall is more of a cliff, really.",
     "cliff"   : "A huge cliff towers over you like a monsterous giant. Along "
                 "the side of the wall, there are only three notches in the "
                 "wall.",
     "notches" : "It would take a while to search for notches, possibly it would "
                 "prove easier to investigate the wall itself.",
     "platform": "It is further north in the lava pool, how you could get to it, "
                 "though, you can't imagine.",
     "pool"    : "You are in a lava pool. The is largest rock sticking out of "
                 "the lava is too far north to jump to, though there are others.",
    ({ "stones", "rocks" }) : "Several sharp rocks stick out of the lava. You "
                 "need to get to the only one of them that could possibly provide "
                 "any real support. Enough rocks stick out of the pool that you "
                 "could hop on them over to the northern rock.",
     "rock"    : "It is a large rock that reaches about twenty something feet "
                 "out of the lava pool.",
     "lava"    : "A boiling pool of liquid hot magma.",
     "sky"     : "The sky is a white expanse as far as the eye can see."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "outdoors" : 1,
     "no bump" : 1, "no attack" : 1, "no magic" : 1, "no teleport" : 1,
     "no steal" : 1 ]));
   set_search("wall", "You notice a doorway and three notches. You guess that "
     "you probably have to choose one of the notches to open the door. But if "
     "you choose the wrong notch.. what then?");
   set_search("cliff", "You notice a doorway and three notches. You guess that "
     "you probably have to choose one of the notches to open the door. But if "
     "you choose the wrong notch.. what then?");
   set_exits(([
   ]));
}

void stop_hopping(object tp) {
   message("info", "You lunge from the last stone onto the large rock.", tp);
   tp->move(ROOMS"o5");
}

int hop(string str) {
   if (!str) return 0;
   if (member_array(str, ({ "rocks", "on rocks", "stones", "on stones" }) ) == -1) return 0;
   write("You jump from rock to rock, trying desperatly not to slip into the "
     "magma.");
   this_player()->set_paralyzed(1, "You jump from rock to rock towards the "
     "largest one of them.");
   call_out("stop_hopping", 1, this_player());
   return 1;
}

int choose(string str) {
   if (!str) return 0;
   if (str != "1" && str != "2" && str != "3") return notify_fail("Choose "
     "what?\n");
   write("You press the inside of the notch. The doorway slides open.");
   this_object()->add_exit(ROOMS"o7", "south");
   return 1;
}

void init() {
 ::init();
   add_action("choose", "choose");
   add_action("hop", ({ "hop", "jump" }));
}
