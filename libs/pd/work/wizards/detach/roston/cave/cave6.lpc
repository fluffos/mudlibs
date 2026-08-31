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
   set_long("This is one part of this giant cave. It is to the "
            "north of the entrance. This is where elder creatures come"
            " to sleep off there battle for food. This room seems to be"
            "very dark.");

   set_exits( (["west"  : "/wizards/detach/roston/cave/cave7",    
                "south"  : "/wizards/detach/roston/cave/cave5",
                "east"   : "/wizards/detach/roston/cave/cave8"]));
}



   void reset() {
::reset();

     if(!present("bat"))
           {
       new("/wizards/detach/roston/cave/bat")->move(this_object());   
            }

}      
