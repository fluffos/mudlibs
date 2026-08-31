#include <std.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A snow path");
   set_long("To the west is a large monster, this is "
            "is the middile of 2 hills, its as if your "
            "stuck. The path leads over the hill to the south.");

   set_exits( (["east"  : "/wizards/detach/roston/roston37",
                "south" : "/wizards/detach/roston/roston42",]));
}                                                          
 void reset() {
 ::reset();
 if(!present("fox"))
       {
       new("/wizards/detach/roston/fox")->move(this_object());
       }

}                         
