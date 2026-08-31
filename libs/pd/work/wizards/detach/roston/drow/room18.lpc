#include <std.h>
inherit ROOM;

void create() {
  ::create();
set_name("Drow Camp");
set_items((["snow"   : "A deep white snow",
            "dirt"  : "A dark brown mixture"]));
set_properties((["light":2, "night light":3]));
set_short("camp");
set_long("This is the drow encampment, where the drows are waiting to "
        "attack roston the town to the south. There are tents layed out "
       "all around as far as you can see. The general never ventures "
       "this far back in the camp, she is too important to travel with "
       "the army men.");

set_exits( ([ "north" : "/wizards/detach/roston/drow/room19",
              "west" : "/wizards/detach/roston/drow/room38",
              "south" : "/wizards/detach/roston/drow/room17" ]));
}                                                              
void reset() {
 

  ::reset();
     if(!present("cavalry"))
       {

new("/wizards/detach/roston/drow/mon/calvary")->move(this_object());

new("/wizards/detach/roston/drow/mon/calvary")->move(this_object());
   }
}

