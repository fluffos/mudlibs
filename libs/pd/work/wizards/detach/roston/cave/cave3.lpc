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
   set_long("This is a great place in the cave. It is where the "
            "Polar Bear's rest during the long winter. Most Polar"
            "Bear's just stay here to have there babys then leave "
            "but some come to sleep to let the winter pass. The "
            "vapors here seem to be changing to a red color.");

   set_exits( (["north"  : "/wizards/detach/roston/cave/cave5",
                "south"  : "/wizards/detach/roston/cave/cave2",
                "east"   : "/wizards/detach/roston/cave/cave10",
                "west"   : "/wizards/detach/roston/cave/cave4"]));
}



   void reset() {
::reset();

     if(!present("bear"))                    
         {
       new("/wizards/detach/roston/p_bear")->move(this_object());
       }

}      
