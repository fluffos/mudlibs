#include <std.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A snow path");
   set_long("The mountain, is to the east, this is a "
            "very large hill.There seems to be tracks "
            "in the snow.");

   set_exits( (["west"  : "/wizards/detach/roston/roston34",        
                "east" : "/wizards/detach/roston/roston31"]));
}
    void reset() {

     if(!present("bear"))
       {
       new("/wizards/detach/roston/m_bear")->move(this_object());
       }

}                            
