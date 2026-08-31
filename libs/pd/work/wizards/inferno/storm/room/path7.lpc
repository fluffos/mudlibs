#include <storm.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Climbing over some boulders");
   set_properties((["light" : 0, "night light" : -1]));
   set_long("Many large boulders have fallen to the east of here, "
            "not only blocking all travel in that direction, but also "
            "casting a deep shadow upon this section of the path. "
            "The path leads over the strewn boulders, sending the "
            "adventurer climbing over them.");
   set_exits(([ "west" : ROOMS "path6",
                "up" : ROOMS "path8" ]));
   set_items(([ "mountain" : "Mount Storm reaches up, past the clouds.",
                "boulders" : "They are certainly climbable.",
                "shadow" : "The shadow makes the path rather dark here.",
                "path" : "It leads above the boulders, higher onto the mountain."
            ]));
}

void init() {
 ::init();
   add_action("climb", "climb");
}

int climb(string str) {
   if (str != "boulders" && str != "boulder") return 0;
   write("You climb over the boulders.");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
         " climbs over the boulders.", ({ this_player()}) );
   this_player()->move(ROOMS"path8");
   return 1;
}
