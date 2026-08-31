#include <std.h>
#include <cp.h>
inherit DOCKS;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 1, "beach"   : 1]) );
   set_short("Docks near a mountain");
   set_long(
            "Rough waves splash against the rocks. A dock is here "
            "where several boats are bobbing with the waves. A "
            "gigantic mountain range can be seen towering over "
            "many trees. If your boat isn't here, you may <recall "
	    "boat>. You may <board [name]> if it is.");
   set_items(([
            "waves" : "The waves are rough and high. They splash "
                        "against the rocks, creating an almost "
		 	"relaxing mist.",
            "rocks" : "The large, gray rocks are being beaten "
                 "by the fierce waves.",
            "dock" : "The dock is here where several boats "
                  "are parked, bobbing with the waves.",
            "mountain" : "The mountain really isn't that far away. "
		 "It stretches into the sky, high above many trees "
		 "that cover the island.",
	    "trees" : "Thousands of trees cover the island. High "
		 "above the trees an enormous mountain stretches "
		 "into the sky.",
	    "mist" : "The mist is rather heavy, yet almost relaxing."
   ]));
   set_smell("default", "The heavy mist smells salty.");
   set_listen("default", "The waves splashing against the rocks "
		 "is almost deafening.");
   set_exits( ([ 
        "east" :  ROOMS "outer_1"]));
}
