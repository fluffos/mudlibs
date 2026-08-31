#include <std.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A Cavern");
   set_long("This is the middile of a giant cavern. It was formed in "
            "the side of the mountain. There are giant ice spikes "
            "on top of the cavern.");
set_exits(([  "north" : "/wizards/detach/roston/roston46",
              "south" : "/wizards/detach/roston/roston47",
              "out" : "/wizards/detach/roston/roston44"]));
}                                                                 
    void reset() {

     if(!present("ice elemental"))
       {
       new("/wizards/detach/roston/elemental")->move(this_object());
       }

}                              
