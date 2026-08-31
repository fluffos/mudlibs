#include <std.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A snow path");
   set_long("There are mountains all around, to the west there " 
            "a huge mountain, The hill to the west looks like its "
            "there something on it,there are many foot prints on "
            "the ground. The snow seems to be turning to ice.");
set_exits(([  "north" : "/wizards/detach/roston/roston38",
               "east" : "/wizards/detach/roston/roston43",
              "west" : "/wizards/detach/roston/roston44"]));          
}

    void reset() {

     if(!present("hunter"))
       {
       new("/wizards/detach/roston/hunter")->move(this_object());
       }

}              
