// seeker

#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create()
{
 ::create();
set_short("lost in the rain forest");
set_long("The forest is extremely dark and thick. There are "
         "plants of various sizes scattered about. Monkeys swing "
         "from tree to tree.");

set_items( 
          ([ "vines" : "The vines go from tree to tree.",
             "trees" : "The trees tower over you.",
             "ground": "The grounds full of leaves and is soggy.",
             "monkeys" : "They seem to be moving quickly." ]) );

set_properties( ([ "light" : 3, "night light" : 1, "forest" :1 ]) );

set_smell("default", "The humid air stifils your senses.");
set_listen("default", "You hear animals squeeking.");

set_exits( (["north" : ROOMS"rain_forest/path6",
              "south" : ROOMS"rain_forest/dirt2"]) );

}


void reset()
{

 if (!present("monkey"))
   {
    new(ROOMS"rain_forest/mon/monkey")->move(this_object());
    new(ROOMS"rain_forest/mon/monkey")->move(this_object());
    new(ROOMS"rain_forest/mon/monkey")->move(this_object());
   }

}
   
