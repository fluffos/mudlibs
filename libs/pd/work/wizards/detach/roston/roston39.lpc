#include <std.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A snow path");
   set_long("This is a giant hole in the side of the mountain "
            "There seems to be tons of hay and food on the ground "
            "This hole is a hudge place.");

   set_exits( (["west"  : "/wizards/detach/roston/roston37",]));
}
 void reset() {               
::reset();

 if(!present("yetti"))
       {
       new("/wizards/detach/roston/b_yetti")->move(this_object());
       new("/wizards/detach/roston/b_yetti")->move(this_object());
       new("/wizards/detach/roston/b_yetti")->move(this_object());
       new("/wizards/detach/roston/b_yetti")->move(this_object());
       }

}                   
