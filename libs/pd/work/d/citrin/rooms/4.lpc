//  Created by Whit
#include <std.h>
#include <citrin.h>
inherit ROOM;

void create() {
    ::create();
    set_name("entrance to Citrin Forest");
    set_short("entrance to Citrin Forest");
    set_long("The grass that covers the path seems to have been "
      "cut down by a sharp object enabling access to the "
      "forest.  Tall trees stand to the east signifying the "
      "entrance to the forest.  The area surrounding the "
      "path is made of tall grass and small trees.");
    set_items(([
        "grass":"The grass seems to be cut down by some unknown force.",

        "path":"The path is covered with cut down grass",
        "tall trees":"The trees signify the entrance to the forest.",
        "small trees":"They surround the path.",
      ]));
    set_exits(([
        "west":ROOMS"2",
        "east":ROOMS"5",
    ]));
    set_pre_exit_functions( ({"west"}), ({"go_west"}) );
    set_properties((["light":1,"night light":1,"forest":1,]));
}

int go_west() {
   if(this_player()->is_player()) return 1;
   return 0;
}


