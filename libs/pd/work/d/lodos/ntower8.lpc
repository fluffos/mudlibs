#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("A small waiting room");
   set_properties((["light" : 2]));
   set_properties((["town" : 1, "indoors" : 1, "building" : 1]));
   set_long("You find yourself in some kind of a waiting room. The red "
      "carpet leads north. This looks like a guard's post. The floor "
      "here is mostly wooden, although the red carpet leads through it.");
   set_exits(([ "north" : ROOMS"ntower9",
                "down" : ROOMS"ntower7"]));
   set_items(([
      "carpet" : "The carpet leads to the north.",
      "floor" : "The floor is mostly wooden.",
      "post" : "This apears to be a guard's post.",
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
   if (!present("knight"))
     make(MOB"knight");
   if (!present("paladin"))
     make(MOB"paladin");
   if (!present("guardian"))
     make(MOB"guardian");
}
