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
         "mountains are beging to fall threw the roof. ");

set_exits( ([ "up" : "/wizards/detach/roston/r_crack6",
              "down" : "/wizards/detach/roston/r_crack8" ]));
}     
void reset() {
  ::reset();
     if(!present("snake"))
       {
       new("/wizards/detach/roston/snake")->move(this_object());
       new("/wizards/detach/roston/snake")->move(this_object());
       new("/wizards/detach/roston/snake")->move(this_object());
   }
}               
