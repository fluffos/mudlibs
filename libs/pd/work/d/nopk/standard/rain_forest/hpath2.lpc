#include <std.h>
#include <rain.h>

inherit ROOM;
create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 1, "town" :1 ]) );
   set_short("Merchant path");
   set_long("A residential area. "
            "Directly to the south is a house. Off in the di"
            "tance is the palace and town square.");
   set_exits((["south" : ROOMS"home1",
               "northwest" : ROOMS"hpath1"]));
}
