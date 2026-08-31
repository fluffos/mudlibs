#include <lodos.h>
#include <std.h>
inherit ROOM;

int up() {
   if (this_player()->query_level() < 8)
    return notify_fail("You are too inexperienced to wander that far off.\n");
   this_player()->move_player(ROOMS"mount1", "up");
   return 1;
}

int go_up(string where) {
   if (where == "up") return up();
   return 0;
}

void init() {
 ::init();
   add_action("up", "up");
   add_action("go_up", "go");
}

void create() {
 ::create();
   set_short("Traveling on a mountain road");
   set_long("This mountain road leads south, towards a pass below. "
      "Far to the southeast, a small city can be seen, and even further "
      "the city's gates. Above this road, the Lodos town gates can be seen.");
   set_exits(([ "up" : ROOMS"mount1",
                "south" : ROOMS"mount3"]));
   set_properties(([ "light" : 2 ]));
   set_property("mountain",1);
}
/*
void reset() {
 ::reset();
   if (!present("guard")) {
      new(MOB"gate_guard")->move(this_object());
      new(MOB"gate_guard")->move(this_object());
   }
}
*/
