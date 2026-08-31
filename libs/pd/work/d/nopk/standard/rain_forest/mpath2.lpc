#include <rain.h>
#include <std.h>
inherit ROOM;

  void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 1, "town" :1 ]) );
    set_short("Traveling the merchant path");
    set_long("This is the merchant path which leads to all the "
             "stores. A few shops are to the southeast. The "
             "path continues south and east.");
    set_exits((["south": ROOMS"mpath3",
                "east": ROOMS"mpath1"]));

}
