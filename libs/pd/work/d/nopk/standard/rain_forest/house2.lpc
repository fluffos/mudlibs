#include <rain.h>
#include <std.h>
inherit ROOM;

create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 2, "indoors" :1 ]) );
   set_short("Decent hut");
   set_long("This is a hutt. There "
            "is a bed sitting in the corner of this room. A "
            "fireplace is located directly next to the bed, and a small "
            "table is sitting near the center of this hut");
   set_items((["fireplace" : "There are a few red hot embers left in "
               "the fireplace.",
               "bed" : "This is a small cot",
               "table" : "This is a small coffee table with nothing "
               "on it."]));
   set_exits((["out" : ROOMS"home3"]));
}

reset() {
   ::reset();
   if(!present("peasant"))
   new(MOB"hpeasant")->move(this_object());
}
