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
        "attack roston the town to the south. There is members of the "
        "drow army all around, they seem to be haveing fun and getting "
           "drunk. They seem to have no fears at all, while drunk.");

set_exits( ([ "south" : "/wizards/detach/roston/drow/room26",
              "north" : "/wizards/detach/roston/drow/room24" ]));
}                                                    
void reset() {
 

  ::reset();
     if(!present("archer"))
       {

new("/wizards/detach/roston/drow/mon/archer")->move(this_object());
   }

}
