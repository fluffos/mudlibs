#include <storm.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("A small, dirt pathway leading up to a mountain");
   set_properties((["light" : 2, "night light" : 1]));
   set_long("A thin, dirt path winds around the rather steep side "
            "of the fabled Mount Storm. Several trees can be seen "
            "along the side of the mountain. The top of the mountain "
            "is hidden above the clouds.");
   set_listen("default", "A strange hush fills the air.");
   set_exits(([ "north" : ROOMS "path2" ]));
   set_items(([ "mountain" : "Mount Storm reaches up, past the clouds.",
                "path" : "A small, winding, dirt path.",
                "trees" : "They are scattered about the side of the mountain."
            ]));
}
