#include <std.h>
inherit ROOM;

void create() {
  ::create();
set_name("Drow Camp");
set_items((["snow"   : "A deep white snow",
            "tent"  :"This tent is very the army comes to rest",
            "dirt"  : "A dark brown mixture"]));
set_properties((["light":2, "night light":3]));
set_short("camp");
set_long("This is the drow encampment, where the drows are waiting to "
        "attack roston the town to the south. There is members of the "
        "of the drow army all around, This seems to be a coner of the "  
         "camp, soldiers seem to gather here, and talk to other members.");

set_exits( ([ "south" : "/wizards/detach/roston/drow/room40" ]));
}                                                
void reset() {
 

  ::reset();
     if(!present("archer"))
       {

new("/wizards/detach/roston/drow/mon/soldier")->move(this_object());

new("/wizards/detach/roston/drow/mon/archer")->move(this_object());
   }
}
