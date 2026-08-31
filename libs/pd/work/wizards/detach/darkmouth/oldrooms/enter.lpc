#include <std.h>

inherit ROOM;

void create() {
::create();
   set_name("The Caverns");
   set_items((["wall"   : "You wonder why your looking at a wall if your
lost"]));
   set_properties((["light":2, "night light":2]));
   set_short("The Caverns");                      
   set_long("%^BOLD%^%^BLACK%^Welcome to the Caverns, The keeper stands guard over the Caverns.
                  Footsteps can be heard below you %^RESET%^%^BLACK%^

The Caverns lead down");
set_exits( ([ "down" : "/wizards/detach/darkmouth/1"]));

set_invis_exits(({"down"}));


skip_obvious();
}
 void reset() {

     if(!present("keeper"))
       {
       new("/wizards/detach/darkmouth/mob/keeper")->move(this_object());
      }

}
