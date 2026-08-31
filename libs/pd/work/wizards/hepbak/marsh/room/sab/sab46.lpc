#include <std.h>
#include <sabserver.h>
inherit DESERT;
    set_exits( ([
"north" : SAB "sab54",
    ]) );
}
void init() {
   ::init();
   add_action("enter","enter");
}
int enter(string str) {
   if(str != "mirage"){
     notify_fail("Nothing happens.\n"); return 0; }
   write("The cool east wind blows on your face, and the dessert dissappears from view.\n");
   this_player()->move(FORT "fort14");
   tell_object(this_player(), "You are in shock, what a view!\n");
   return 1;
}
