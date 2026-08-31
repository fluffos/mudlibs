#include <std.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A snow path");
   set_long("There is a huge Cave to the east. The mountains seems "
            "seem to be closeing in on you. The ground feels as if "
            "its moveing. There seems to be vapors comeing out of "
            "the ground.");

   set_exits( (["west"  : "/wizards/detach/roston/roston33",
                "east" : "/wizards/detach/roston/roston53",
                "south" : "/wizards/detach/roston/roston54",
                "north" : "/wizards/detach/roston/roston55"]));
}
    void reset() {  
 
       if(!present("snake"))
       {
       new("/wizards/detach/roston/snake")->move(this_object());
       }

}     
