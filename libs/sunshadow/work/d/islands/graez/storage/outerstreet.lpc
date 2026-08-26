

#include <std.h>
#include "../graez.h"

inherit CORE;

void create() {
    ::create();

    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_property("indoors",0);

    set_name("road along the city wall");
    set_short("%^C060%^road along the city wall%^CRST%^");
    set_long("This is a %^C060%^road %^CRST%^along the %^C060%^city "+
	"wall%^CRST%^. It is %^C094%^dusty %^CRST%^and mostly empty "+
	"as most people and businesses prefer to be as far from "+
	"the %^C060%^city walls%^CRST%^ as possible. The area near "+
	"the walls does however house some %^C190%^small "+
	"tents%^CRST%^ of the poorest citizens and %^C196%^small "+
	"campfires%^CRST%^ where %^C060%^soldiers %^CRST%^huddle. "+
	"There are wide %^C059%^stairs %^CRST%^at several places "+
	"leading to the east that allow you to climb to the "+
	"top of the %^C059%^walls%^CRST%^.\n");


    set_items(([
        ({"fires","campfires"}) : "There are %^C124%^campfires %^CRST%^here where %^C060%^soldiers %^CRST%^can huddle over and stay warm",
        ({"tent","tents"}) : "pitiful %^C143%^little tents%^CRST%^ are propped up against the %^C060%^wall %^CRST%^where the %^C142%^poorest %^CRST%^of the city live. While protected from the elements, if the %^C060%^walls %^CRST%^fall they will face the %^C090%^undead %^CRST%^first.",
        ({"stairs"}) : "%^C060%^Wide stairs%^CRST%^ lead up to the top of the %^C061%^walls%^CRST%^. They are wide enough and at an angle where even %^C094%^cavalry %^CRST%^",
    ]));

    set_smell("default","%^CRST%^You smell the %^C088%^cookfires%^CRST%^.");
    set_listen("default","%^CRST%^You hear the %^C106%^bustle %^CRST%^of the %^C060%^city%^CRST%^.");

    set_post_exit_functions(({"east"}), ({"GoThroughDoor"}));

}

int GoThroughDoor(){
   tell_object(TP,"\nYou carefully climb the steps to the top of the wall.\n");
   return 1;
}