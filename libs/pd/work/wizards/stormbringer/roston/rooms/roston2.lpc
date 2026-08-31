#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
 ::create();
   set_name("roston n road 1");
   set_properties(([       "light" : 2,
                     "night light" : 1,
                            "town" : 1]));
   set_short("North Roston road.");
   set_long("A well traveled road north of Roston Square. Patches of snow "
            "and muddy slush litter the sides of the road. A muddy path leads off "
            "to the west. The road continues to the north and south. A building to "
            "the northeast looms large over the area.");
   set_items(([    "snow" : "Snow covers the ground next to the road and the nearby mountains.",
	         "mountain" : "Snow covered mountains tower over this valley.",
                   "path" : "A mud soaked worn footpath.",
                   "road" : "A smoothed wide semi frozen, slushy, muddy road.",
               "building" : "A small fortified castle."]));
   set_exits(([   "south" : ROOMS "roston",
                   "west" : ROOMS "roston23",
                  "north" : ROOMS "roston14"]));
   set_smell("default", "The scent of leather wafts in from the south.");
   set_listen("default", "The sound of clanging metal comes from the southwest.");
}

  void reset() {

     if(!present("townsman"))
       {
       new(MOB "t_man")->move(this_object()); 
       }

}                                                 
