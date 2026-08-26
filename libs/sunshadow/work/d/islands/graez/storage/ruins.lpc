
//Ruins - LoKi 2022

#include <std.h>
#include "../graez.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("indoors", 0);
    set_name("charred ruins");
    set_short("%^C246%^charred ruins%^CRST%^");
    set_long("This area of the city has been leveled with what "+
    	"must have been a %^C060%^devastating%^CRST%^ %^C088%^fire%^CRST%^. "+
    	"The walls and ceilings of buildings have been %^C243%^destroyed%^CRST%^ "+
    	"and the walls have been %^C242%^charred%^CRST%^ and in places "+
    	"even %^C242%^melted%^CRST%^ from some extreme %^C088%^heat%^CRST%^.\n");
    set_smell("default","%^C246%^It smells like ash and smoke%^CRST%^");
    set_listen("default","%^C143%^You hear the sounds of the city in the distance%^CRST%^");


    set_items(([
        ({"walls"}) : "%^RESET%^%^ORANGE%^The walls are %^C241%^charred%^CRST%^ and "+
        "almost %^C088%^melted%^CRST%^ in points.%^RESET%^",
        ({"ground"}) : "%^RESET%^%^ORANGE%^The ground is filled with %^C060%^debris%^CRST%^, "+
        "pools of %^C111%^water%^CRST%^ from where people tried to put out "+
        "the %^C088%^fires%^CRST%^, and %^C243%^ash%^CRST%^.%^RESET%^",
    ]));
    
}

