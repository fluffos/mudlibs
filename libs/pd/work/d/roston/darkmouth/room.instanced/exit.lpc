#include <std.h>

inherit INSTANCE;

void create() {
::create();
  set_instance_group_id("Shadow Caverns");
   set_name("The Caverns");
   set_items((["wall"   : "You wonder why you're looking at a wall if you're
lost"]));
   set_properties((["light":2, "night light":2]));
   set_short("The Caverns");                      
   set_long("%^BOLD%^%^BLACK%^ Welcome to the Nightstalkers home, he rules the Caverns from here. From this room every room of the Caverns can be seen.
                  Footsteps can be heard below you 

The Caverns lead: down, out");
set_exits( ([ "out" : "/d/roston/cave/cave20",
                  "down" : "/d/roston/darkmouth/room/100"]));
    add_pre_exit_function("out", "go_out");

set_invis_exits(({"out","down"}));


skip_obvious();
}
int go_out() {
  if(!this_player()->is_player()) return 0;
  return 1;
}
 void reset() {

     if(!present("nightstalker"))
       {
       new("/d/roston/darkmouth/mob/nightstalker")->move(this_object());
      }

}
