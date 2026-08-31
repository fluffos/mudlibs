#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
   set_property("mountain",1);
    set_property("no castle", 1);
    set("short", "Northern path of the Daroq Mountain pass");
    set("long",
	"The dangerous ledge to the east ends here, as the path "
        "heads down the slope, and feeds into the main pass. The pass "
        "runs right below the mountain ledge to the east. "
        "There are some sparse shrubs reaching out of the stony earth.");
   set_items( ([
     ({"shrubs","bushes","plants"}) :
     "That make out a strange circular pattern.",
   ]) );
    set_exits(([ "down" : ROOMS"npass10",
                 "east" : ROOMS"npass8" ]));
}


void init() {
   ::init();
   add_action("search","search");
}

int search(string str) {
   if(str != "shrubs"){
     notify_fail("You find nothing unusual.\n"); return 0; }
   write("As you approach a shrub the ground caves in.\n");
   this_player()->move("/d/aekari/room/ca1");
   tell_object(this_player(), "You hit the ground with a thump.\n");
   this_player()->add_hp(-30);
   return 1;
}
