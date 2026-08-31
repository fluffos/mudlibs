#include <std.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "ice"    : "A very hard and thick pice of ice",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A Cavern");
   set_long("The Carven walls have began to crack, the ice seems "
            "to be gone, there is a huge crack in the wall. The "
            "moist here, with little snow left.");
set_exits(([  "crack" : "/wizards/detach/roston/roston49",
              "south" : "/wizards/detach/roston/roston46",]));
}
    void reset() {               
  
::reset();
 if(!present("dragon"))
       {
       new("/wizards/detach/roston/dragon")->move(this_object());
       }

}                           
