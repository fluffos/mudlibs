#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 1, "mountains" : 1, "town" : 1]) );
   set_short("Bronze Street - Steel Hammer Village");
   set_long(
            "Bronze Street runs north and south here. There are "
            "several houses lined alongside the road. The city stretches "
            "east while a tall mountain dominates the west. Platinum "
	    "Street is south of here.");
   set_items(([
            "mountains" : "The mountains are west of here, enclosing "
                        "the village.",
            "platinum street" : "Platinum Street is the main street in the " 
                 "village. It is south of here and runs east to west.",
            "houses" : "Small stone buildings that have been carved from the "
                "mountains lie ahead. They're all in different "
                "shapes and sizes, but they are all pretty small.",
            "bronze street" : "Bronze Street is a residential street. There "
                "are many houses on the east side of the street and the"
                 " mountains act as the city wall on the western side.",
            "roads" : "A very interesting design. The road is stone, carved "
                "from the mountain, and into various designs. The designs "
                "are very artistic and beautiful."
   ]));
   set_smell("default", "The air is crisp and the air is humid.");
   set_listen("default", "The solf rumble of the village drones the air.");
   set_exits( ([ 
        "north" : ROOMS "n_bronze2",
        "south" : ROOMS "sh_3"]));
}
