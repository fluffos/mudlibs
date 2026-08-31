#include <std.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "cracks" : "A huge hole in the ground",
               "vapors" : "A wired looking mist",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A snow path");
   set_long("The cave seems to travel to the north, the east "
            "part of the cave is a very wet and sticky and no "
            "creature wants to live here.");

   set_exits( (["west"  : "/wizards/detach/roston/cave/cave1"]));      

}


void reset() {
::reset();

     if(!present("hunter"))
         {
       new("/wizards/detach/roston/hunter")->move(this_object());
       }

}
                                      
