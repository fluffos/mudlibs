#include <std.h>
#include <roston.h>
inherit ROOM;

void create() {
  ::create();
set_name("Drow Camp");
set_items((["snow"   : "A deep white snow",
            "tent"  : "this is where the member of the drow army rest",
             "dirt"  : "A dark brown mixture"]));
set_properties((["light":2, "night light":3]));
set_short("camp");
set_long("This is the drow encampment, where the drows are waiting to "
        "attack roston the town to the south. There are tents layed out "
       "all around as far as you can see. The mountains are as high as "
     "you can see. The ground seems to be very soft here.");

set_exits( ([ "north" : DROWROOM"room13",
              "south" : DROWROOM"room11" ]));
}                                                             
