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
         "giant mountains are peeking up from the surface, the "
         "mountains are beging to fall threw the roof, as light "
         "seeks threw the roof. ");

set_exits( ([ "up" : "/wizards/detach/roston/r_crack7",
              "down" : "/wizards/detach/roston/r_crack9" ]));
}                                                              
void reset() {
  ::reset();
     if(!present("bear"))
       {
       new("/wizards/detach/roston/p_bear")->move(this_object());
       new("/wizards/detach/roston/p_bear")->move(this_object());
       new("/wizards/detach/roston/p_bear")->move(this_object());
   }
}
                        
