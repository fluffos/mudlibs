#include <std.h>
#include <rain.h>
inherit ROOM;

create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 2, "indoors" :1 ]) );
   set_short("Inside the palace");
   set_long("A short passage inside the elven "
            "palace. It is plain white with old swords lining "
            "the walls.");
   set_exits((["west" : ROOMS"palace6",
               "east": ROOMS"palace1"]));
}
