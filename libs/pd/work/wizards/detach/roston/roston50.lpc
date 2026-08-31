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
   set_long("This part of the cavern is very huge. The walls "
            "are covered of giant pices of ice. The walls seem  "
            "to be sinking in on you.");

set_exits(([ "west" : "/wizards/detach/roston/roston47",]));

}                              

  void reset() {

::reset();
 if(!present("bear"))
       {
       new("/wizards/detach/roston/p_bear")->move(this_object());
       }

}                 
