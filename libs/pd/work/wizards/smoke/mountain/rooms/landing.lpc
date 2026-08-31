#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_properties((["light" : 2, "indoors" : 0]));
    set("short", "Atop a mountain peak");
    set("long",
        "This is the peak of a very large mountain in the middle of the ocean."
        "The air is thin and it's hard to breathe all the way up here. There "
        "isn't much room to move around. The ground is covered in snow."
    );
    set_items(([
        "clouds" : "The puffy clouds are all around you.. even below you!",
        "snow" : "The snow looks tightly packed and very deep.",
        "mountain" : "You can only see so far down the mountain, but it's huge."
    ]));
}

void init() {
  ::init();
    add_action("dig","dig");
}

int dig(string str) {
   if(!str) {
     notify_fail("You can't dig that!\n");
     return 0;
   }
   if(str != "snow") {
     notify_fail("You cannot dig that!.\n");
     return 0;
   }
   if(this_player()->query_level() < 25) {
     notify_fail("You dig and dig until you are exhausted.\n");
     return 0;
   }
   write("You dig and dig and the ground beneath you collapses!");
   say(" Suddenly "+this_player()->query_cap_name()+"  falls into "
        "the mountain peak!");
   this_player()->add_hp(-random(50));
   this_player()->move_player("/wizards/smoke/mountain/rooms/ent");
   message("info", "The snow blows back over the hole"
                   " before you know it.", this_object());
   return 1;
}
