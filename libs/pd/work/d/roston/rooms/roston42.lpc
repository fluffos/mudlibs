#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A snow path");
   set_long("The mountains all around you seem to blend together, "
            "except for the hill on the west which seems to have something "
            "on top of it. There are many footprints in the snow on the ground.");
set_exits(([   "north" : ROOMS "roston38",
               "east" : ROOMS "roston43",
               "west"  : ROOMS "roston44"]));          
}

    void reset() {

     if(!present("hunter"))
       {
       new(MOB "hunter")->move(this_object());
       }

}              
