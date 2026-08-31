#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A snow path");
   set_long("The mountain, is to the east, this is a "
            "very large hill. There seems to be tracks "
            "in the snow.");

   set_exits( (["west"  : ROOMS "roston34",        
                "east"  : ROOMS "roston31"]));
}
    void reset() {

     if(!present("bear"))
       {
       new(MOB "m_bear")->move(this_object());
       }

}                            
