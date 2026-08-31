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
         "all dirctons you can see light begins to peek out of the "
         "the roof. ");

set_exits( ([ "up" : "/wizards/detach/roston/r_crack5",
              "down" : "/wizards/detach/roston/r_crack7" ]));
}                                                               
void reset() {
  ::reset();
     if(!present("bear"))
       {
       new("/wizards/detach/roston/m_bear")->move(this_object());
       new("/wizards/detach/roston/m_bear")->move(this_object());
       new("/wizards/detach/roston/m_bear")->move(this_object());
   }
}          
