// Chernobog & Titania (2/21/22)
// The Wailing Isle - Lookout Top

#include <std.h>
#include "../defs.h"
inherit VAULT;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_property("light", 1);
    set_property("indoors", 0);
    set_property("no sticks", 1);
    set_name("atop a lookout on the Wailing Isle");
    set_short("%^RESET%^%^CRST%^%^C075%^atop a lookout on the Wailing Isle%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C075%^You stand atop the lookout tower of the Wailing Isle. The view from here is expansive, with the %^C073%^o%^C068%^p%^C063%^e%^C068%^n %^C073%^s%^C079%^e%^C073%^a%^RESET%^%^C075%^ to one side dotted with %^C101%^ships%^C075%^ along the wharf, the %^C253%^t%^C252%^o%^C251%^w%^C252%^e%^C253%^r%^C254%^i%^C255%^n%^C254%^g %^C253%^c%^C252%^l%^C251%^i%^C250%^f%^C251%^f%^C252%^s%^RESET%^%^C075%^ of the island rising up to dwarf the %^C147%^village%^C075%^ in its shadow, and the %^C039%^e%^C045%^t%^C051%^e%^C087%^r%^C081%^n%^C075%^a%^C069%^l %^C075%^s%^C081%^k%^C087%^i%^C051%^e%^C045%^s%^RESET%^%^C075%^ overhead that can change in an instant when the %^C081%^winds%^C075%^ turn. The %^C081%^waves%^C075%^ slam against the %^C247%^j%^C243%^a%^C247%^gg%^C243%^e%^C247%^d r%^C243%^o%^C247%^cks%^RESET%^%^C075%^ far beneath your feet, and you can feel the strength of the sea resonating through the old stones, right to your very core. A small %^C247%^stone wall%^C075%^ wraps around the tower top, providing the only barrier between you and the %^C247%^c%^C243%^r%^C247%^ag%^C243%^g%^C247%^y j%^C243%^e%^C247%^tty%^RESET%^%^C075%^ and %^C073%^h%^C074%^u%^C073%^ng%^C074%^r%^C073%^y s%^C074%^e%^C073%^a%^RESET%^%^C075%^ down below. The %^C250%^wind%^C075%^ blows fierce, tearing at your clothes and hair.%^CRST%^\n");
    set_smell("default","%^RESET%^%^CRST%^%^C072%^The %^C078%^li%^C079%^be%^C078%^ra%^C079%^ti%^C078%^ng sc%^C079%^en%^C078%^ts%^RESET%^%^C072%^ of the %^C066%^sea%^C072%^ and %^C066%^sky%^C072%^ %^C078%^in%^C079%^vi%^C078%^go%^C079%^ra%^C078%^te%^RESET%^%^C072%^ you.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C073%^The w%^C072%^a%^C073%^v%^C072%^e%^C073%^s c%^C072%^r%^C073%^a%^C073%^shi%^C072%^n%^C073%^g ag%^C072%^a%^C073%^inst the roc%^C072%^k%^C073%^s bl%^C072%^o%^C073%^ck out e%^C072%^v%^C073%^en the c%^C072%^r%^RESET%^%^C073%^y of the g%^C072%^u%^C073%^lls o%^C072%^v%^C073%^erhe%^C072%^a%^C073%^d.%^RESET%^%^CRST%^%^CRST%^");
    set_items(([
        ({"sea", "ocean"}) : "%^RESET%^%^CRST%^%^C044%^Light ripples over the surface of the %^C038%^azure water%^C044%^ like diamonds, %^C051%^luring%^C044%^ you into its bountiful depths. The %^C250%^breeze%^C044%^ is constant, bringing with it the scents of the sea, and it whispers the %^C051%^promises%^C044%^ of adventures abound and treasures not yet plundered. The vastness of the sea is humbling to some... and something to be conquered by others.%^CRST%^",
        "cliffs" : "%^RESET%^%^CRST%^%^C255%^White cliffs rise up behind the %^C250%^small village%^C255%^, their craggy, steep surface making climbing a very dangerous prospect. The cliffs are riddled with %^C244%^hidden caves%^C255%^ and %^C244%^caverns%^C255%^, so that when the %^C250%^wind%^C255%^ whips through them they let out a %^C059%^mournful cry%^C255%^ that can be heard across the entire island... hence the island's namesake.%^CRST%^",
        "ships" : "%^RESET%^%^CRST%^%^C102%^The ships float %^C090%^majestically%^C102%^ on the bay, awaiting their next %^C172%^adventure%^C102%^. They feature %^C250%^great sails%^C102%^, meant for the deep seas. Absent from their masts are the colors of any of the city states of the realm, and a few even sport %^C059%^black flags%^C102%^ with malicious icons.%^CRST%^",
        ({"walls", "wall"}) : "%^CRST%^%^RESET%^%^C059%^Uneven stones have been mortared together in a %^C243%^pa%^C245%^tc%^C247%^hw%^C249%^or%^C243%^k d%^C245%^is%^C247%^pl%^C249%^ay%^RESET%^%^C059%^ of masonry. For as old as this structure appears, the walls are solid and seem likely to hold for a long time.%^CRST%^",
        ]));
    set_exits(([
        "down" : ROOMS"lookout2",
        ]));
    set_door("trapdoor", ROOMS "lookout2", "down", 0);
	set_door_description("trapdoor","Planks of weather-worn wood have been banded together in iron to serve as a barrier. It can be pushed open, or pulled closed by a large metal ring set along an edge.");
}

