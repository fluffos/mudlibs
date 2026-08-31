#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Climbing the steps further up the tower");
   set_properties((["town" : 1, "indoors" : 1, "building" : 1]));
   set_properties((["light" : 2]));
   set_long("The tower leads up even further, along with the red carpeted "
      "stairs. Two windows let in red and green light, because they are "
      "coloured. The air is warm and comfortable.");
   set_exits(([ "up" : ROOMS"ntower5",
                "north" : ROOMS"serv",
                "down" : ROOMS"ntower3"]));
   set_items(([
      "windows" : "The windows are coloured red and green",
      "stairs" : "Like most do, they lead up and down.",
      "air" : "The air is warm and comfortable.",
      "carpet" : "The carpet is a king's red."
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
