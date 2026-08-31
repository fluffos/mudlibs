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
        "of the drow army all around, the members seem to have very "
      "strange looks on there face. ");

set_exits( ([ "east" : "/wizards/detach/roston/drow/room43",
              "north" : "/wizards/detach/roston/drow/room46",
              "south" : "/wizards/detach/roston/drow/room45",
              "west" : "/wizards/detach/roston/drow/room47" ]));
}                                                
void reset() {
 

  ::reset();
     if(!present("archer"))
       {

new("/wizards/detach/roston/drow/mon/archer")->move(this_object());

new("/wizards/detach/roston/drow/mon/calvary")->move(this_object());
   }
}
