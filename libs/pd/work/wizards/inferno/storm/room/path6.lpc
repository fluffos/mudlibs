#include <storm.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("A small, dirt pathway leading up to a mountain");
   set_properties((["light" : 2, "night light" : 1]));
   set_long("A small carpet of moss covers the ground, near some "
            "of the trees along the path. Clouds hang in the lifeless "
            "sky. A flock of birds circle high above you.");
   set_exits(([ "west" : ROOMS "path5",
                "east" : ROOMS "path7" ]));
   set_items(([ "mountain" : "Mount Storm reaches up, past the clouds.",
                "trees" : "Most of them are pine trees.",
                "moss" : "The home of many strange insects and bugs.",
                "birds" : "They are vultures, waiting for your demise."
            ]));
}

