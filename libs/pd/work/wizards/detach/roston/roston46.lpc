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
   set_long("This is the nothern part of the Cavern, the ice grows "
            "thicker here. The walls are coverd with ice. A large "
            "shadow can be seen to the north.");
set_exits(([  "north" : "/wizards/detach/roston/roston48",
              "south" : "/wizards/detach/roston/roston45",]));
}
    void reset() {                         
::reset();
 if(!present("hunter"))
       {
       new("/wizards/detach/roston/hunter")->move(this_object());
       }

}  
