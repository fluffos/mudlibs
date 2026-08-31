#include <std.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A snow path");
   set_long("There are tons of mountains all around you. There "
            "are little hills in distance to see. There seems "
            "to be a giant hole in the ground to the west.");

   set_exits( (["west" : "/wizards/detach/roston/roston42",]));
}
 void reset() {  
::reset();
 if(!present("snake"))
       {
       new("/wizards/detach/roston/snake")->move(this_object());
       }

}         
