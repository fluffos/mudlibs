//City Street Inherit

#include "../graez.h"
inherit VAULT;

void create() {
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("cobblestone city street");
    set_short("%^C142%^cobblestone city street%^CRST%^");
    set_long("This %^C059%^street %^CRST%^winds through the city of %^C255%^Graez%^CRST%^. The street itself is %^C060%^ancient cobblestone%^CRST%^ that has worn down by the feet of a thousand %^C111%^people %^CRST%^and %^C246%^soldiers%^CRST%^ marching over it. On either side of the street it dips down lower so %^C111%^water %^CRST%^can flow away from the centre. On either side are %^C059%^squat buildings%^CRST%^ that look new, as if they need to be reconstructed on a regular basis.\n");


    set_items(([
        ({"cobblestone","streets"}) : "The streets here are %^C060%^cobblestone%^CRST%^, but old enough that they have been smoothed down by decades of use.",
        ({"buildings"}) : "The %^C060%^buildings %^CRST%^here are squat and constructed of almost %^C143%^temporary materials%^CRST%^ as if they were recently destroyed.",
    ]));

    set_smell("default","You smell the %^C249%^chaotic %^C143%^smells %^CRST%^of the city around you.");
    set_listen("default","The %^C187%^bustle %^CRST%^of the city is all around you.");

}
