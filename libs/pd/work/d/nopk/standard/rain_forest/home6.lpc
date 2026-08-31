#include <std.h>
#include <rain.h>
inherit ROOM;

create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 1, "town" :1 ]) );
   set_short("Edge of Residential district");
   set_long("This is the residential district just outside the gates. The area seems deserted.");
   set_exits((["east" : ROOMS"home4",
               "north" : ROOMS"home3",
               "southwest" : ROOMS"pgate"]));
}
