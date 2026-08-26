
//Bone Tower Gate

#include <std.h>
#include "../../serakii.h"

inherit VAULT;



void create() {
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(RUTTED_TRACK);
    set_property("indoors",0);
    set_property("no teleport",1);
    set_property("no scry",1);
    set_name("bone tower gate in a corrupted forest");
    set_short("%^C195%^bo%^C231%^n%^C195%^e tow%^C231%^e%^C195%^r "+
    "gate i%^C231%^n%^C195%^ a %^CRST%^%^C058%^co%^C059%^r%^C058%^ru%^C059%^"+
	"p%^C058%^t%^C022%^e%^C058%^d f%^C022%^o%^C059%^"+
	"r%^C058%^e%^C022%^s%^C058%^t%^CRST%^");
    set_long("This %^C022%^forest %^CRST%^is a strange "+
	"thing, and to call it a %^C022%^forest%^CRST%^ "+
	"at all anymore is a stretch. %^C022%^Immense "+
	"trees%^CRST%^ grow around you, each %^C094%^"+
	"trunk %^CRST%^two meters across, but instead "+
	"of proper %^C094%^branches%^CRST%^, the %^C058%^"+
	"bark %^CRST%^is split and %^C061%^writhing "+
	"tentacles%^CRST%^ emerge and flap about limply. "+
	"As you look up the %^C062%^tentacles %^CRST%^grow "+
	"together, blocking out the sky completely as a "+
	"nest of interlocking %^C062%^strange flesh%^CRST%^. "+
	"The %^C058%^ground %^CRST%^here feels mushy but "+
	"you cannot see it through a %^C056%^thick purple "+
	"miasma%^CRST%^ that rises thick over the %^C059%^"+
	"ground %^CRST%^at a foot height. You hear %^C244%^"+
	"strange chanting%^CRST%^ though it is hard to tell "+
	"if it comes from the %^C022%^trees%^CRST%^, or from "+
	"something under the %^C062%^miasma%^CRST%^. The "+
	"air itself feels almost %^C081%^wet %^CRST%^as you "+
	"breathe.\n");
    set_items(([
        ({"trees","trunks","tentacles"}) : "The %^C022%^"+
		"trees %^CRST%^here grow tall and strong in an "+
		"initial look though where %^C058%^branches%^CRST%^ "+
		"are supposed to be are instead %^C062%^fleshy "+
		"tentacles%^CRST%^ dangle and move limply.",
        ({"sky","canopy"}) : "The %^C087%^sky %^CRST%^is "+
		"completely obscured by the %^C062%^intertwined "+
		"tentacles%^CRST%^ above you.",
        ({"ground","mist","miasma"}) : "The %^C059%^"+
		"ground %^CRST%^is covered by a thick foot deep "+
		"layer of %^C056%^miasma %^CRST%^that smells "+
		"like %^C194%^ozone%^CRST%^.",
    ]));

set_exits(([

    "southwest" : FOR"b22",
    "gate" : BONE"2",

]));

set_smell("default","%^C159%^You smell ozone.%^RESET%^");
set_listen("default","%^BLACK%^%^BOLD%^You hear strange chanting all around you.%^RESET%^");

set_door("heavy gate",BONE"2","gate",0);
set_door_description("heavy gate","%^C058%^Formed from solid "+
    "wood, this door looks very "+
    "heavy. An iron ring hangs from it to allow it "+
    "to be opened.%^RESET%^");
set_string("heavy gate", "open", "%^C058%^The door opens silently.%^RESET%^");
set_string("heavy gate", "close", "%^C058%^The door closes silently.%^RESET%^");


}

query_weather() { return "The air around you is %^C081%^wet %^CRST%^like it just %^C068%^rained%^CRST%^.\n"; }



