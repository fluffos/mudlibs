#include <std.h>
#include <rain.h>
inherit ROOM;

void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 2, "indoors" :1 ]) );
   set_long("A long hallway to the "
             "council room. Along the walls are statues of "
             "old kings, queens, and council members. There"
             " are also some paintings of royal people.");
   set_short("Inside a hallway to the council");
   set_items((["paintings" : "These are various paintings of royal people",
               "statues" : "There are many statues of kings, queens, and "
               "council members"]));
   set_exits((["southeast" : ROOMS"palace9",
               "northwest" : ROOMS"palace7"]));
}
