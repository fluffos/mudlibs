#include <std.h>
inherit ROOM;


void create() {
    ::create();
    set_properties((["light" : 0, "indoors" : 1]));
    set("short", "The inside of a mountain");
    set("long",
        "The walls here are very cold. It is quite dark and hard to breathe. "
        "There is snow on the ground, which fell through the peak of the mountain. "
        "Some light can be seen peeking through the snow above."
    );
    set_items(([
        "walls" : "The walls are freezing cold.",
        "snow" : "The snow covers the ground.",
        "light" : "Some light peeks through the snow above you."
    ]));
    set_exits( ([ "east" :  "/wizards/smoke/mountain/rooms/1"
    ]) );
}

void init() {
  ::init();
    add_action("climb","climb");
}

int climb(string str) {
   if(!str) {
     notify_fail("You cannot climb that!\n");
     return 0;
   }
   if(str != "out") {
     notify_fail("You cannot climb that!\n");
     return 0;
   }
   write("You grab the wall and pull yourself out!");
   say(" "+this_player()->query_cap_name()+"  grabs onto the wall "
        "and climbs out of a hole in the ceiling!");
   this_player()->add_hp(-random(50));
   this_player()->move_player("/wizards/smoke/mountain/landing");
   message("info", "Some snow falls down from above.", this_object());
   return 1;
}
