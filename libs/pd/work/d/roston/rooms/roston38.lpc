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
   set_long("To the west a large monster is visible. This is the "
            "middle of 2 hills, and it seems as if you are stuck "
            "between them. The path leads over the hill to the south.");

   set_exits( (["east"  : ROOMS "roston37",
                "south" : ROOMS "roston42"]));
}                                                          
 void reset() {
 ::reset();
 if(!present("fox"))
       {
       new(MOB "fox")->move(this_object());
       }

}                         
