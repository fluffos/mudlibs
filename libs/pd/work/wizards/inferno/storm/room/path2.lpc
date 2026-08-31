#include <storm.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("A small, dirt pathway leading up to a mountain");
   set_properties((["light" : 2, "night light" : 1]));
   set_long("The dirt path continues up the mountain, through "
            "several scattered trees. The air is crisp and cool. "
            "A cool wind blows across your face, sending a slight "
            "chill down your spine.");
   set_listen("default", "A strange hush fills the air.");
   set_exits(([ "south" : ROOMS "path1",
                "north" : ROOMS "path3" ]));
   set_items(([ "mountain" : "Mount Storm reaches up, past the clouds.",
                "path" : "A small, winding, dirt path.",
                "trees" : "They are scattered along near the path."
            ]));
}
