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
   set_long("This is part of the Cave, where there walls seem "
            "closeing in on you. The vapors here seem to be "
            "chaning colors. Its looks as if creatures come here "
            "to rest.");

   set_exits( (["east"  : "/wizards/detach/roston/cave/cave3"]));
}



   void reset() {
    ::reset();
     if(!present("elder hunter"))
           {
       new("/wizards/detach/roston/cave/hunter2")->move(this_object());                
         }

}     
