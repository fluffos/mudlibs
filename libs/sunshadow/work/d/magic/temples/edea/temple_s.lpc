// Chernobog (6/30/22)
// Temple of Edea - Written by Victoire

#include <std.h>

inherit VAULT;

void create(){
    ::create();
    set_property("indoors", 0); 
    set_property("light", 2);
    set_terrain(GARDEN);
    set_travel(PAVED_ROAD);
    set_name("Gardens of the Celestial Light"); 
    set_short("%^BOLD%^%^WHITE%^Gardens of the %^YELLOW%^Celestial Light%^RESET%^");
    set_long("%^RESET%^%^CRST%^%^C034%^An overtaking %^C046%^sprawl%^C034%^ of %^C046%^lush%^C034%^ and %^C046%^green growth%^C034%^ overtakes the scenery here, %^C046%^vines%^C034%^ and %^C046%^roots%^C034%^ trailing along the %^C229%^sandy%^C034%^ ground with no explanation of how this growth survives under the %^C124%^oppressive heat%^C034%^, still, many %^C214%^flowers%^C034%^ bloom across the %^C046%^vine%^C034%^s and %^C130%^roots%^C034%^, bringing %^C196%^colour%^C034%^ to the %^C229%^sandy%^C034%^ environment. Overgrown, white, %^C226%^elven walls%^C034%^ that hold a hue of %^C164%^senzokuan%^C034%^ architecture, have been erected around the proximity to the %^C171%^south%^C034%^, warding off against %^C124%^clandestine%^C034%^ %^C160%^winds%^C034%^ and %^C039%^weather%^C034%^. A %^C228%^path%^C034%^ leads through the %^C046%^growth%^C034%^ from the %^C130%^south%^C034%^, where the walls connect to a gateway, %^C130%^north%^C034%^ towards the spire nestled at the centre and origin of the sprawl.%^CRST%^\n");
    set_smell("default","%^RESET%^%^CRST%^%^C177%^An incredibly heavy scent of a multitude of flowers hangs around the area.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C040%^The quiet noise of chatter and the work being done here can be heard.%^CRST%^");
    set_items(([
        "spire" : "%^RESET%^%^CRST%^%^C220%^An %^C034%^overgrown%^C220%^ %^C228%^spire%^C220%^ stands as the origin of the %^C046%^growth%^C220%^. %^C034%^Vines%^C220%^ and %^C034%^plants%^C220%^, blooming %^C196%^flowers%^C220%^ and herbals of any kind nearly cover the whole building up. Large %^C246%^archways%^C220%^ lead into the spire itself, where a %^C255%^bright light%^C220%^ shines out from. During the night moonflowers begin to bloom over it.%^CRST%^",
        "growth" : "%^RESET%^%^CRST%^%^C034%^The entire area is covered with %^C130%^veins%^C034%^, %^C130%^roots%^C034%^ and %^C046%^plant life%^C034%^ above a %^C229%^sandy%^C034%^ ground. It stands as a near %^C124%^impossibility%^C034%^ under the %^C124%^oppressive heat%^C034%^. %^C226%^Flowers%^C034%^, %^C208%^fruits%^C034%^ and even some %^C136%^vegetables%^C034%^ sprout from all along the growing %^C046%^growth%^C034%^.%^CRST%^",
        "wall" : "%^RESET%^%^CRST%^%^C171%^A %^C166%^sun elven%^C171%^-styled %^C249%^wall%^C171%^ has been erected around, serving to protect the growth from %^C124%^merciless%^C171%^ %^C037%^wind%^C171%^ and %^C098%^people%^C171%^ that might come to attempt to %^C124%^harm%^C171%^ it. A hue of %^C165%^Senzokuan%^C171%^ architecture is added through %^C165%^narrow slits%^C171%^ and a senzokuan %^C242%^roofing%^C171%^ and over it.%^CRST%^",
        ]));
    set_exits(([
        "east" : "/d/magic/temples/edea/temple_se",
        "west" : "/d/magic/temples/edea/temple_sw",
        "south" : "/d/shadow/virtual/desert/27,10.desert",
        ]));
}

