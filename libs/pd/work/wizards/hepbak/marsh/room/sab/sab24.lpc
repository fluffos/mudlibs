#include <std.h>
#include <sabserver.h>
inherit DESERT;
    set_exits( ([
"northeast" : SAB "sab32",
"south" : SAB "sab18",
"northwest" : SAB "sab31",
"east" : SAB "sab25",
    ]) );
}
void init() {
   ::init();
   add_action("enter","enter");
}
int enter(string str) {
   if(str != "mirage"){
     notify_fail("You find yourself eating sand.\n"); return 0; }
 if(!query_night()) {
  write("The cool east wind blows on your face, and the dessert dissappear
from view.\n");
   this_player()->move_player(FORT "mirage", "into a mirage");
   tell_object(this_player(), "You are in shock, what a view!\n");
   return 1;
}
this_player()->move_player(FORT "moredesert");
return 1;
}
