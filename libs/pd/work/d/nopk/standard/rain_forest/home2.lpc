#include <std.h>
#include <rain.h>
inherit ROOM;

create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 1, "town" :1 ]) );
   set_short("Second house on the block");
   set_long("A nice cottage. "
            "The palace is off to the south. Off to the west is the "
            "town square.");
   set_exits((["west" : ROOMS"home1",
               "south" : ROOMS"home5"]));
   set_items((["cottage" : "This is a small decent cottage"]));
}
