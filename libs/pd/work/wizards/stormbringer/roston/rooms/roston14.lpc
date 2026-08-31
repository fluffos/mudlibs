#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
  ::create();          

   set_name("roston road");
   set_properties(([       "light" : 2,
                     "night light" : 1,
                            "town" : 1]));
   set_short("North Roston road.");
   set_long("A well traveled dirt road north of Roston Square. Patches of snow "
            "and muddy slush litter the sides of the road. The road continues to the north and "
            "south. A building to the east looms large over the area. Great piles of stone "
            "blocks are piled northwest of here");
   set_items(([    "snow" : "Snow covers the ground next to the road and the nearby mountains.",
	         "mountain" : "Snow covered mountains tower over this valley.",
                   "road" : "A smoothed wide semi frozen, slushy, muddy road.",
               "building" : "A small fortified castle."]));
   set_smell("default", "The area smells of fresh mountain air tinged with an earthy scent.");
   set_listen("default", "The faint sound of clanging metal comes from the west.");
   set_exits( ([  "north" : ROOMS "roston15",
                  "south" : ROOMS "roston2" ]));
}
                                                               
