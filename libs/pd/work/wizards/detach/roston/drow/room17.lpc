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
       "all around as far as you can see. These parts of the camp are "
       "for the weaker troops that stay back. The general has never "
       "been this far back in the camp.");

set_exits( ([ "north" : "/wizards/detach/roston/drow/room18",
              "south" : "/wizards/detach/roston/drow/room16" ]));
}                                                              
void reset() {
 

  ::reset();
     if(!present("archer"))
       {

new("/wizards/detach/roston/drow/mon/calvary")->move(this_object());
       new("/wizards/detach/roston/drow/mon/archer")->move(this_object());
   }
}

