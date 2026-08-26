// Chernobog & Titania (2/21/22)
// The Wailing Isle - Lookout Exterior

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_property("light", 1);
    set_property("indoors", 0);
    set_name("outside a lookout on the Wailing Isle");
    set_short("%^RESET%^%^CRST%^%^C067%^outside a lookout on the Wailing Isle%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C067%^Sitting alone here on a rocky foundation, an old %^C059%^s%^C243%^t%^C059%^o%^C243%^n%^C059%^e lo%^C243%^oko%^C059%^ut to%^C243%^w%^C059%^er%^RESET%^%^C067%^ stands sentinel against all who would try to suppress the free people of Wailing Isle. The island %^C101%^wharf%^C067%^ and its pandemonium is behind you now, and much of the chaos is muffled by the crashing of %^C069%^w%^C063%^a%^C069%^v%^C063%^e%^C069%^s%^C067%^ against the %^C059%^je%^C243%^t%^C059%^ty%^RESET%^%^C067%^. The %^C059%^j%^C243%^a%^C059%^gg%^C243%^e%^C059%^d s%^C243%^t%^C059%^on%^C243%^e%^C059%^s%^C067%^ make for some precarious steps, so you best tread with caution. The %^C031%^e%^C030%^n%^C031%^dle%^C030%^s%^C031%^s o%^C030%^c%^C031%^e%^C030%^a%^C031%^n%^RESET%^%^C067%^ spreads open before you, its %^C068%^gl%^C069%^it%^C075%^te%^C081%^ri%^C080%^ng %^C074%^wa%^C068%^te%^C062%^rs%^RESET%^%^C067%^ stretching to the horizon, where %^C101%^great ships%^C067%^ seek their fates and fortunes.\n%^CRST%^");
    set_smell("default","%^RESET%^%^CRST%^%^C070%^It smells like %^C064%^r%^C058%^o%^C064%^t%^C058%^t%^C064%^i%^C058%^n%^C064%^g%^RESET%^%^C070%^ fish.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C073%^The w%^C072%^a%^C073%^v%^C072%^e%^C073%^s c%^C072%^r%^C073%^a%^C073%^shi%^C072%^n%^C073%^g ag%^C072%^a%^C073%^inst the roc%^C072%^k%^C073%^s bl%^C072%^o%^C073%^cks out e%^C072%^v%^C073%^en the c%^C072%^r%^RESET%^%^C073%^y of the g%^C072%^u%^C073%^lls o%^C072%^v%^C073%^erhe%^C072%^a%^C073%^d.%^RESET%^%^CRST%^%^CRST%^");
    set_items(([
        "tower" : "%^RESET%^%^CRST%^%^C250%^Built from %^C255%^white stones%^C250%^ quarried from the island, this two-story round tower has stood here for ages. While %^C245%^weatherworn%^C250%^ and %^C245%^crumbling%^C250%^ in places, the tower remains strong against the %^C195%^salty winds%^C250%^ and %^C195%^water%^C250%^ that batter it.%^CRST%^",
        ({"sea", "ocean"}) : "%^RESET%^%^CRST%^%^C044%^Light ripples over the surface of the %^C038%^azure water%^C044%^ like diamonds, %^C051%^luring%^C044%^ you into its bountiful depths. The %^C250%^breeze%^C044%^ is constant, bringing with it the scents of the sea, and it whispers the %^C051%^promises%^C044%^ of adventures abound and treasures not yet plundered. The vastness of the sea is humbling to some... and something to be conquered by others.%^CRST%^",
        ({"stones", "ground","jetty"}) : "%^RESET%^%^CRST%^%^C059%^The rocks creating a small bit of land in the sea appears to be a man-made feature. The large jagged stones are soaked from the %^C033%^cr%^C032%^as%^C031%^hi%^C032%^ng %^C033%^wa%^C032%^ve%^C031%^s%^RESET%^%^C059%^, and covered in %^C160%^or%^C166%^an%^C172%^ge %^C160%^li%^C166%^ch%^C172%^en%^RESET%^%^C059%^ that makes them %^C244%^extra slippery%^C059%^.%^CRST%^",
        "ships" : "%^RESET%^%^CRST%^%^C178%^The ships float %^C090%^majestically%^C178%^ on the bay, awaiting their next %^C172%^adventure%^C178%^. They feature %^C250%^great sails%^C178%^, meant for the deep seas. Absent from their masts are the colors of any of the city states of the realm, and a few even sport %^C059%^black flags%^C178%^ with malicious icons.%^CRST%^",
        ]));
    set_exits(([
        "enter" : ROOMS"lookout2",
        "southwest" : ROOMS"path9",
        ]));
}

