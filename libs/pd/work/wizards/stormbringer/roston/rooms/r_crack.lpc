#include <std.h>
#include <roston.h>
inherit ROOM;

void create() {
  ::create();
set_name("Entrance to Crack");
set_items((["snow"   : "A very deep white snow",
            "dirt"  : "A light brown mixture"]));
set_properties((["light":2, "night light":3]));
set_short("entrance to crack");
set_long("This is the entrance to a giant crack in the ground.  The "
         "the ground seems to shake here.  The giant crack seems to "
         "to go down forever and ever.  The light of roston can be "
         "seen coming from outside this crack.");

set_exits( ([ "out" : ROOMS "roston7",
              "down" : ROOMS "r_crack2" ]));
}
                                              


void reset() {
  ::reset();
     if(!present("bear"))
       {
       new(MOB "m_bear")->move(this_object());
       new(MOB "m_bear")->move(this_object());
       new(MOB "m_bear")->move(this_object());  
   }
}
