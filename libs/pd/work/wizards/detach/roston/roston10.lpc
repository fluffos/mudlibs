#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_items((["snow"   : "The snow is dirty and spoiled.",
               "building":"The small building has no windows.",
               "dirt"  : "The thick, black sort."]));        
   set_properties((["light":2, "night light":3, "town":1]));
   set_short("Entrance to the Incinerator");
   set_day_long("The Roston daylight floods into the small alley "
     "leading east up to a small darkened building. The snow around "
     "here is dirty and has a coat of filth over it.");
   set_day_long("The moonlight is hidden from this small Roston "
     "alley. A small, dark building with no windows and a small door "
     "is here. The snow is coated in filth and dirt.");
   set_exits(([ "west" : "/wizards/detach/roston/roston7",
                "enter": "/wizards/detach/roston/incinerator" ]));
}
