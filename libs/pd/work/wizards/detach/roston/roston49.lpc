#include <std.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["hay" : "A dark brown pice of hay",
               "snow"   : "A very deep white snow",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A Cavern");
   set_long("This is a space made by a giant crack in the cavern "
            "wall. it looks like someone lives in here. There a  "
            "stack of hay in the middile of the floor.");

set_exits(([ "out" : "/wizards/detach/roston/roston48"]));

}
    void reset() {      
::reset();
 
   if(!present("wizard"))
       {
       new("/wizards/detach/roston/wizard")->move(this_object());
       }

}                        
