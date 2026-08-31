#include <storm.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("A small, dirt pathway leading up to a mountain");
   set_properties((["light" : 2, "night light" : 1]));
   set_long("The dirt path begins to slope upwards, onto the "
            "mountain. A single pine tree stands in the center of "
            "the path. The air is cool and dry.");
   set_listen("default", "Some bird's cry can be heard in the distance.");
   set_exits(([ "southwest" : ROOMS "path3",
                "northeast" : ROOMS "path5" ]));
   set_items(([ "mountain" : "Mount Storm reaches up, past the clouds.",
                "path" : "A small, winding, dirt path.",
                "tree" : "A single, small sapling. A small nest rests atop it.",
                "nest" : "It has a couple of %^RED%^red%^RESET%^ and %^BOLD%^%^BLACK%^black %^RESET%^eggs in it.",
                "eggs" : "The largest eggs you've seen in your life!"
            ]));
}
