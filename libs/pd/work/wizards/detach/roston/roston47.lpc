#include <std.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "ice"    : "A very hard and thick pice of ice",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A Cavern");
   set_long("This is the southern part of the cavern, the walls "
            "are coverd in ice. The Cavern walls seem to be "
            "sinking in on you, the room is getting smaller.");
set_exits(([  "north" : "/wizards/detach/roston/roston45",
              "east" : "/wizards/detach/roston/roston50",
              "west" : "/wizards/detach/roston/roston51",]));
}
    void reset() {  
::reset();

 if(!present("hunter"))
       {
       new("/wizards/detach/roston/hunter")->move(this_object());
       }

}       
