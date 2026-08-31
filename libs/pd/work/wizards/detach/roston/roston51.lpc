#include <std.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "ice" : "A deep water that is frozen over ",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A snow path");
   set_long("This is a dark place in the Cavern. The Cavern walls "
            "seems to be sinking in on you. The ice on the wall is "
            "beging to melt away.");

   set_exits( (["east" : "/wizards/detach/roston/roston47",]));
}   
 void reset() {
::reset();
 if(!present("snake"))
       {
       new("/wizards/detach/roston/snake")->move(this_object());
       }

}           
