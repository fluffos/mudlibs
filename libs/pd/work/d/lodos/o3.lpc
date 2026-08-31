#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Obstacle Course: Room 2");
   set_long("%^RESET%^%^ORANGE%^"
     "A sizzling hot cage encloases this platform. The cage bars reach "
     "straight upwards as far as the eye can see. A door-sized hole is cut into "
     "the southern wall of the cage. This platform is just twenty feet above a "
     "wide pool of liquid hot magma. There is a large rock sticking out of the "
     "lava to the south. Because of the strangely increased gravity the only way "
     "across the pool is a single iron bar. Through it is hot, the bar could still "
     "be crossed.");
   set_items(([
     "bars" : "The cage bars are sizzling hot",
     "cage" : "The cage reaches straight upwards, the bars are burning hot.",
     "door" : "Floating midair to the north.",
     "foo"  : "bar",
     "bar"  : "A single iron bar streches from this platform across the lava "
              "pool to a large rock. You could cross it with minimal difficulty.",
     "pool" : "A boiling pool of liquid hot magma.",
     "sky"  : "The sky is a white expanse as far as the eye can see."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "outdoors" : 1,
     "no bump" : 1, "no attack" : 1, "no magic" : 1, "no teleport" : 1,
     "no steal" : 1 ]));
   set_exits(([
   ]));
}

void finish_climbing(int i, object tp) {
   message("info", "You reach the stone slab below the cage. Your body goes "
     "into shock from the pain of the climb.", tp);
   tp->set_paralyzed(2, "You are in shock.");
   tp->damage((i * 17), "burn");
   tp->move(ROOMS"o2");
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
    "and begin to decend the cage bars.");
   call_out("finish_climbing", i, i, this_player());
   return 1;
}

void finish_crossing(object tp) {
   message("info", "You hop off the end of the bar and land on a large rock. On "
     "your landing you slip and fall towards the pool of lava! You get scraped "
     "and a little burnt, but manage to pull yourself back onto the rock.", tp);
   tp->damage(90, "burn");
   tp->move(ROOMS"o4");
}

int cross(string str) {
   if (!str || str != "bar") return notify_fail("Cross what?\n");
   this_player()->set_paralyzed(3, "You must concentrate completely on crossing "
     "the pool of lava.");
   write("You carefully balance on top of the bar and begin to cross.");
   call_out("finish_crossing", 3, this_player());
   return 1;
}

void init() {
 ::init();
   add_action("cross", "cross");
   add_action("climb", "climb");
}
