#include <std.h>
#include <roston.h>

inherit ROOM;

   set_name("roston road");
   set_properties(([       "light" : 2,
                     "night light" : 1,
                            "town" : 1]));
   set_short("Castle road.");
   set_long("A well traveled road leading through well kept gardens. Patches of snow "
            "and muddy slush litter the sides of the road. A castle to the east "
            "looms large over the area. Large flowering plants grow next to the road in defiance of the "
            "bitter cold. The road continues to the east and west.");
   set_items(([    "snow" : "Snow covers the ground next to the road and the nearby mountains.",
	         "mountain" : "Snow covered mountains tower over this valley.",
                   "road" : "A smoothed wide semi frozen, slushy, muddy road.",
               "building" : "A small fortified castle."]));
   set_smell("default", "The air is fresh with a tinge of a musty odor.");
   set_listen("default", "The sound of clanging metal comes from the southwest.");  

    set_exits( (["west"  : ROOMS "roston19",
	"south" : ROOMS "garden" ]));

}                                                          

void reset() {

    if(!present("royal guard"))
    {
	new(MOB "loyalknight")->move(this_object());
	new(MOB "royalguard")->move(this_object());
	new(MOB "prince")->move(this_object());
    }

}                                           

