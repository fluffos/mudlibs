#include <std.h>
#include <roston.h>

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
   set_long("The Cave to the east seems to be fadeing away. "
            "The cracks on the ground seem to be growing larger "
            "as you get closer to the cave.");

   set_exits( (["north"  : ROOMS "roston52"]));
}             
 

   void reset() {

     if(!present("bear"))
       {
       new(MOB "p_bear")->move(this_object());
       }

}    
