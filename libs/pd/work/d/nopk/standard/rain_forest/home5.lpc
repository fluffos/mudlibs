#include <std.h>
#include <rain.h>
inherit ROOM;

void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 1, "town" :1 ]) );
   set_short("Fifth house on the block");
   set_long("A small hut. The logs of this hut seem to be some kind of "
            "prefabricated siding. Other houses are located near here.");
   set_items((["logs" : "These logs are a cheaper version of wood."]));
   set_exits((["north" : ROOMS"home2",
               "west" : ROOMS"home4",
               "enter" : ROOMS"house5"]));
}

void reset() {
   ::reset();
   if(!present("child"))
   new(MOB"pchild")->move(this_object());
}
