#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Climbing the steps further up the tower");
   set_properties((["light" : 2]));
   set_properties((["town" : 1, "indoors" : 1, "building" : 1]));
   set_long("The red carpet and the gold lined stairs make this tower "
      "look expensive in itself. The rail for the stairs is almost calling "
      "to you to slide on it. The walls and ceiling are marble.");
   set_exits(([ "up" : ROOMS"ntower7",
                "down" : ROOMS"ntower5"]));
   set_items(([
      "rail" : "The rail is calling to you: sliiide on meeee..",
      "stairs" : "They wind up the tower.",
      "tower" : "It must have cost a fortune to build.",
      ({ "walls", "ceiling" }) : "The walls and ceiling are marble."
   ]));
}

int slide(string str) {
   if (!str) return 0;
   if (str != "rail" && str != "on rail") return notify_fail(
     "Slide on what?\n");
   write("You cannot resist the urge!! WHEEEeeeeeeeeeeeee!!!....");
   this_player()->move_player(ROOMS"ntower1", "sliding down the rail");
   return 1;
}
void init() {
 ::init();
   add_action("slide", "slide");
}

void reset() {
 ::reset();
   if (!present("servant"))
     make(MOB"servant");
   if (!present("noble")) {
     make(MOB"noble");
     make(MOB"noble");
   }
}
