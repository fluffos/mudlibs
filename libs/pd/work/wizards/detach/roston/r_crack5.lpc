#include <std.h>
inherit ROOM;

void create() {
  ::create();
set_name("Crack to Roston");
set_items((["snow"   : "A very deep white snow",
            "dirt"  : "A light brown mixture"]));
set_properties((["light":2, "night light":3]));
set_short("Crack in roston");
set_long("This is a great opening in the ground it semes to "
         "to lead all around the under the earth, it looks like "
         "giant mountains are peeking up from the surface, from "
         "all dirctons you can see. ");

set_exits( ([ "up" : "/wizards/detach/roston/r_crack4",
              "down" : "/wizards/detach/roston/r_crack6" ]));
}                                                                  
void reset() {
  ::reset();
     if(!present("yetti"))
       {
       new("/wizards/detach/roston/yetti")->move(this_object());
       new("/wizards/detach/roston/b_yetti")->move(this_object());
       new("/wizards/detach/roston/f_yetti")->move(this_object());
   }
}                  
