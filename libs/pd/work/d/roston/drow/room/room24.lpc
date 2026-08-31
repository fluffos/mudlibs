#include <std.h>
#include <roston.h>
inherit ROOM;

void create() {
  ::create();
set_name("Drow Camp");
set_items((["snow"   : "A deep white snow",
            "dirt"  : "A dark brown mixture"]));
set_properties((["light":2, "night light":3]));
set_short("camp");
set_long("This is the drow encampment, where the drows are waiting to "
        "attack roston the town to the south. There is members of the "
        "drow army all around, but one of the men stands out from the "
       "rest.");

set_exits( ([ "south" : DROWROOM"room25",
              "west" : DROWROOM"room23" ]));
}                                                              
void reset() {
 

  ::reset();
     if(!present("soldier"))
       {

new(DROWMOB"soldier")->move(this_object());

   }
}

