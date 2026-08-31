#include <std.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A snow path");
   set_long("There seems to be a giant holy in the face "
            "of the hill. There are very large prints on "
            " ground, ice begins to form on the ground.");
set_exits( ([ "south" : "/wizards/detach/roston/roston37",
              "north" : "/wizards/detach/roston/roston35",
               "east" : "/wizards/detach/roston/roston32"]));
}

    void reset() {                       
  
     if(!present("yetti"))
       {
       new("/wizards/detach/roston/yetti")->move(this_object());
       }

}              
