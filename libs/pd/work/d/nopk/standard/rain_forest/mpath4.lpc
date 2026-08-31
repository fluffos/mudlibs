#include <rain.h>
#include <std.h>
inherit ROOM;

  void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 1, "town" :1 ]) );
    set_short("Shop entrance");
    set_long("The old path leads north and south through "
             "the town. The town weaponry is east and the "
             "armoury is west. Both shops are small and sturdy. "
             "The shadows of the armoury and weaponry lay across "
             "this path.");
    set_items(([ ({ "shop", "shops" }) : "These shops are small "
                    "stone buildings.",
                 "shadows" : "The shadows lay across your path."]));
    set_exits((["north": ROOMS"mpath3",
                "south": ROOMS"mpath5",
                "west" : ROOMS"shop2",
                "east" : ROOMS"shop1"]));

}
