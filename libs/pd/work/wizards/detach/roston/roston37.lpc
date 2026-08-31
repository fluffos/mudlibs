#include <std.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A snow path");
   set_long("To the east there is a large building, to the east "
            "there seems to be a large hole in the wall. There "
            "are many large tracks on the floor.");

   set_exits( (["west"  : "/wizards/detach/roston/roston38",
                "east" : "/wizards/detach/roston/roston39",
                "north" : "/wizards/detach/roston/roston34"]));
}
    void reset() {              
 
 if(!present("yetti"))
       {
       new("/wizards/detach/roston/f_yetti")->move(this_object());
       }

}                                  
