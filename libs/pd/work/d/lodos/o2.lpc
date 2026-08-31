#include <std.h>
#include <lodos.h>                                         
inherit VAULT;

void create() {
 ::create();
   set_short("Obstacle Course: Room 1");
   set_long("%^RESET%^%^ORANGE%^"
     "The very end of a massive grey stone slab. Midair, a single door "
     "floats about two or three feet above the slab. Only white emptiness can be "
     "seen past the floating door. The grey stone stops very abruptly at the "
     "bottom of the door. Along the eastern length of the slab, a cage rises "
     "higher than the door, as far up as can be seen. The cage bars look "
     "climbable. The only sky is an endless white vastness.");
   set_items(([
     "bars" : "They are sizzling hot",
     "cage" : "The cage reaches straight upwards, the bars are burning hot.",
     "door" : "Floating midair to the north.",
     "slab" : "A smoothly shaped grey stone slab floating in the middle of "
              "nowhere.. nothing strange here.",
     "sky"  : "The sky is a white expanse as far as the eye can see."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "outdoors" : 1,
     "no bump" : 1, "no attack" : 1, "no magic" : 1, "no teleport" : 1,
     "no steal" : 1 ]));
   set_door("door", ROOMS"o1", "north", "");
   set_exits(([
     "north" : ROOMS"o1"
   ]));
}

void finish_climbing(int i, object tp) {
   message("info", "You reach an opening in the cage and climb onto a platform. "
     "Your body goes into shock from the pain of the climb.", tp);
   tp->set_paralyzed(2, "You are in shock.");
   tp->damage((i * 17), "burn");
   tp->move(ROOMS"o3");
}

int climb(string str) {
   int i;
   if (!str) return 0;
   if (str != "bars") return notify_fail("Climb what?\n");
   i = 7 - (this_player()->query_stats("strength")/10);
   if (i < 1) i = 1;
   this_player()->set_paralyzed(i, "You are focusing all of your body away "
       "from the pain.");
   write("You focus your mind and body as you grab hold of the burning hot bars "
    "and begin to climb.");
   call_out("finish_climbing", i, i, this_player());
   return 1;
}

void init() {
 ::init();
   add_action("climb", "climb");
}
