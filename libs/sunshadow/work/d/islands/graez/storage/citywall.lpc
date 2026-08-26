#include <std.h>
#include "../graez.h"

inherit CORE;

void create() {
    ::create();
    faction_control = 1;
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_property("indoors",0);

    set_name("on the city walls");
    set_short("%^C246%^on the city walls%^CRST%^");
    set_long("You stand on top of the %^C246%^city walls%^CRST%^ "+
	"of the city of Graez facing the %^C060%^battlefield%^CRST%^. "+
	"The top of the walls are wide enough that even %^C095%^mounted "+
	"cavalry%^CRST%^ could charge across it and shield formations "+
	"could be formed. Facing the city there are stairs down, "+
	"and facing the %^C106%^battlefield %^CRST%^there "+
	"are %^C060%^crenellations %^CRST%^you could squeeze "+
	"through to drop down.\n");


    set_items(([
        ({"stairs","stair"}) : "The %^C059%^stairs%^CRST%^ lead towards the %^C059%^city %^CRST%^and away from the %^C060%^walls%^CRST%^.",
        ({"crennelations","walls"}) : "The %^C060%^wall %^CRST%^facing the %^C106%^battlefield %^CRST%^features crenels that allow %^C246%^archers %^CRST%^to have some cover while they fire onto the %^C106%^battlefield%^CRST%^.",
        ({"ground","sawdust"}) : "The %^C094%^ground %^CRST%^here has been covered in a fine layer of %^C220%^sawdust %^CRST%^to allow for better footing if %^C124%^blood %^CRST%^is spilled.",
    ]));

    set_smell("default","%^CRST%^You smell %^C220%^sawdust %^CRST%^and %^C124%^blood%^CRST%^.");
    set_listen("default","%^CRST%^You hear the sounds of the %^C060%^city%^CRST%^.");

//    set_post_exit_functions(({"southeast"}),({"GoThroughDoor"}));
set_post_exit_functions(({"southeast", "northeast","west"}), ({"GoThroughDoor","GoThroughDoor","GoThroughDoor2"}));


}

int GoThroughDoor(){
   tell_object(TP,"\nYou slip through the crenels in the battlement and down onto the battlefield.\n");
   return 1;
}

int GoThroughDoor2(){
   tell_object(TP,"\nYou carefully walk down the steps off of the wall.\n");
   return 1;
}



