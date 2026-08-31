#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
  ::create();     

   set_name("roston road");
   set_properties(([       "light" : 2,
                     "night light" : 1,
                            "town" : 1]));
   set_short("Stone Quarry Path.");
   set_long("A muddy path. Patches of snow and muddy slush litter the sides of the "
            "path. Great piles of stone blocks are piled west of here. The muddy path "
            "continues to the east and east.");
   set_items(([    "snow" : "Snow covers the ground next to the road and the nearby mountains.",
	         "mountain" : "Snow covered mountains tower over this valley.",
                   "road" : "A smoothed wide semi frozen, slushy, muddy road.",
               "building" : "A small fortified castle."]));
   set_smell("default", "The air is fresh with a tinge of a musty odor.");
   set_listen("default", "The sound of clanging metal comes from the west.");

set_exits( ([ "east" : ROOMS "roston15",
              "west"  : ROOMS "stoneroom1" ]));
}                                                             
