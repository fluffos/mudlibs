#include <std.h>
inherit ROOM;

void create() {
  ::create();         

set_name("north of square");
set_items((["snow"   : "A very deep white snow",
            "dirt"  : "A light brown mixture"]));        
set_properties((["light":2, "night light":3]));
set_short("A dirt path");
set_long("The white palace is to the east of here. The "
         "snow is getting deeper, the dirt looks like "
         " its getting lighter. The path seems to be getting "
         " wider");

set_exits( ([ "north" : "/wizards/detach/roston/roston30",
              "east" : "/wizards/detach/roston/roston18", 
              "south" : "wizards/detach/roston/roston16" ]));
}                            
 void reset() {
    ::reset();
     if(!present("spy"))
       {
       new("/wizards/detach/roston/spy")->move(this_object());
       }

}                        
