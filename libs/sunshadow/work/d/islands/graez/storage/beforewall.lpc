
#include <std.h>
#include "../graez.h"

inherit CORE;

void create() {
    ::create();

    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_property("indoors",0);

    set_name("before the city walls");
    set_short("%^C059%^before the city walls%^CRST%^");
    set_long("You stand before the %^C060%^city "+
	"walls%^CRST%^ of the city of %^C060%^Graez%^CRST%^. The %^C095%^ground %^CRST%^leading up to the walls has been cleared of "+
	"all %^C022%^foliage%^CRST%^ and %^C088%^burned %^CRST%^so "+
	"none can grow. The %^C060%^wall %^CRST%^itself is ten "+
	"or so feet tall and there are no %^C060%^gates%^CRST%^, "+
	"however there are enough gaps in %^C245%^stones %^CRST%^that "+
	"you feel you can proceed over the %^C060%^wall %^CRST%^to "+
	"the west. At the top of the wall are crenellations for "+
	"archers to fire from. To the north you see a %^C244%^large "+
	"mountain range%^CRST%^ and to the south the %^C111%^ocean%^CRST%^.\n");


    set_items(([
        ({"ground",}) : "the ground here has been blasted not only through constant battle, but work has been done to ensure nothing can grow near the walls.",
        ({"walls","crenellations"}) : "The walls have been constructed from %^C246%^stone%^CRST%^, and while strong, you can see places where you could scramble over them. At the top are battlements with crenellations, gaps where archers can fire from cover.",
    ]));

    set_smell("default","%^CRST%^You smell %^C245%^ash %^CRST%^and %^C124%^spilled blood%^CRST%^.");
    set_listen("default","%^CRST%^The %^C158%^wind %^CRST%^whips through the empty area before the %^C060%^wall%^CRST%^.");

set_post_exit_functions(({"northwest", "southwest"}), ({"GoThroughDoor","GoThroughDoor"}));


}

int GoThroughDoor(){
   tell_object(TP,"You climb carefully up the wall, slipping through a crenel to stand on the wall.");
   return 1;
}
int GoThroughDoor2(){
   tell_object(TP,"You climb carefully up the wall, slipping through a crenel to stand on the wall.");
   return 1;
}

