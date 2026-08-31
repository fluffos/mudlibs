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
         "giant mountains are peeking up from the surface from "
         "all directions.");

set_exits( ([ "up" : ROOMS "r_crack4",
              "down" : ROOMS "r_crack6" ]));
}                                                                  
void reset() {
  ::reset();
     if(!present("yetti"))
       {
       new(MOB"yetti")->move(this_object());
       new(MOB"b_yetti")->move(this_object());
       new(MOB"f_yetti")->move(this_object());
   }
}                  
