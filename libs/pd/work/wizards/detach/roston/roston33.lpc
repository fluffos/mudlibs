#include <std.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A snow path");
   set_long("There is a giant Cave to the east. There all tons of "
            "mountains all around you. The ground is covered with "
            "snow. There seems to be vapors comeoing out of the ground.");

   set_exits( (["west"  : "/wizards/detach/roston/roston31",
                "east" : "/wizards/detach/roston/roston52"]));
}
    void reset() { 

      if(!present("hunter"))
       {
       new("/wizards/detach/roston/hunter")->move(this_object());
       }

}   
