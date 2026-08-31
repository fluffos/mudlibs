#include <std.h>
#include <zexor.h>
inherit ROOM;

void create() {
   ::create();
   set_short("In a swampy forest");
   set_long("The swampy side of the Zexorian forest. "
       "There are trees but they are covered with wasps, bees, a"
       "nd other insects. The mud on the ground bubbles every on"
       "ce in a while.");
   set_listen("default", "You hear the endless droning of insects.");
   set_items((["mud" : "Normal swamp mud which bubbles every once "
       "in a while.",
           "insects" : "Just little insects like bees, and wasps",
             "trees" : "Just some trees with their trunks covere"
                        "d in mud."]));
   set_exits((["northeast" : ROOMS"path11",
               "southwest" : ROOMS"path13"]));
}

void reset() {
   ::reset();
   if(!present("wasp")) {
     new(MOB"wasp")->move(this_object());
     new(MOB"wasp")->move(this_object());
     new(MOB"wasp")->move(this_object());
     new(MOB"wasp")->move(this_object());
     new(MOB"wasp")->move(this_object());
}
}
