#include <std.h>
#include <rain.h>

inherit ROOM;
create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 1, "town" :1 ]) );
   set_short("Residential path");
   set_long("A short stone road leading to the residential "
            "area. Off to the southeast is a few houses, and off "
            "to the southwest you see the town square. Far off in the "
            "distance to the south there is a palace.");
   set_exits((["west" : ROOMS"village3",
               "southeast" : ROOMS"hpath2"]));
   set_items((["palace" : "Even from this distance the palace is a tall "
               "palace with elegant walls."]));
 }
