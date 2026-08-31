#include <std.h>
#include <roston.h>
inherit ROOM;

void create() {
  ::create();
set_name("Crack to Roston");
set_items((["snow"   : "A very deep white snow",
            "dirt"  : "A light brown mixture"]));
set_properties((["light":2, "night light":3]));
set_short("Crack in roston");
set_long("This is a great opening in the ground. It seems "
         "to lead all around the under the earth.  It looks like "
         "giant mountains are peeking up from the surface.  The "
         "mountains are beging to fall through the roof as light "
         "seeps through the roof.");

set_exits( ([ "up" : ROOMS "r_crack7",
              "down" : ROOMS "r_crack9" ]));
}                                                              
void reset() {
  ::reset();
     if(!present("bear"))
       {
       new(MOB"p_bear")->move(this_object());
       new(MOB"p_bear")->move(this_object());
       new(MOB"p_bear")->move(this_object());
   }
}
                        
