// Chernobog & Titania (2/21/22)
// The Wailing Isle - Lookout Interior

#include <std.h>
#include "../defs.h"
inherit VAULT;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no sticks", 1);
    set_name("inside a lookout on the Wailing Isle");
    set_short("%^RESET%^%^CRST%^%^C243%^inside a lookout on the Wailing Isle%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C243%^The inside of the lookout tower is about as dull as you would imagine. A small rectangular window looks out over the sea. A %^C059%^st%^C243%^on%^C059%^e s%^C243%^ta%^C059%^irc%^C243%^as%^C059%^e%^RESET%^%^C243%^ leads up to a %^C101%^tr%^C100%^a%^C101%^pdo%^C100%^o%^C101%^r%^RESET%^%^C243%^ in the roof, the steps worn down from centuries of use. A few %^C142%^oil lamps%^C243%^ are set into %^C059%^small alcoves%^C243%^ in the walls, but it does not appear as if they've been used lately. This place seems all but abandoned to the %^C059%^spiders%^C243%^ creeping around in their %^C247%^webs%^C243%^.\n%^CRST%^");
    set_smell("default","%^RESET%^%^CRST%^%^C070%^It smells like %^C064%^r%^C058%^o%^C064%^t%^C058%^t%^C064%^i%^C058%^n%^C064%^g%^RESET%^%^C070%^ fish.%^CRST%^");    
	set_listen("default","%^CRST%^%^RESET%^%^C108%^The %^C109%^th%^C110%^un%^C109%^de%^C108%^ro%^C109%^us cr%^C110%^as%^C109%^hi%^C110%^ng%^RESET%^%^C108%^ of the %^C110%^waves%^RESET%^%^C108%^ is muffled.%^CRST%^");
    set_items(([
        "lamps" : "%^CRST%^%^RESET%^%^C059%^The lamps are cold and dark, their oil vats empty.%^CRST%^",
        "spiders" : "%^CRST%^%^RESET%^%^C059%^You know they're here, lurking in the dark.%^CRST%^",
        ({"steps", "staircase"}) : "%^CRST%^%^RESET%^%^C243%^A stone staircase leads up to a %^C101%^trapdoor%^C243%^ in the roof, the steps worn down from centuries of use.%^CRST%^",
        ({"walls", "wall"}) : "%^CRST%^%^RESET%^%^C059%^Uneven stones have been mortared together in a %^C243%^pa%^C245%^tc%^C247%^hw%^C249%^or%^C243%^k d%^C245%^is%^C247%^pl%^C249%^ay%^RESET%^%^C059%^ of masonry. For as old as this structure appears, the walls are solid and seem likely to hold for a long time.%^CRST%^",
        ]));
    set_exits(([
        "up" : ROOMS"lookout3",
        "out" : ROOMS"lookout1",
        ]));
    set_door("trapdoor", ROOMS "lookout3", "up", 0);
	set_door_description("trapdoor","%^CRST%^%^RESET%^%^C101%^Planks of weather-worn wood have been banded together in %^C243%^iron%^C101%^ to serve as a barrier. It can be pushed open, or pulled closed by a %^C243%^large metal ring%^C101%^ set along an edge.%^CRST%^");
}

