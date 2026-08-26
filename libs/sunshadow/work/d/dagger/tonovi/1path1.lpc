// Chernobog (3/15/22)
// Western Yniam Road

#include <std.h>
#include "/d/dagger/tonovi/short.h"

inherit VAULT;
object guard;
void create(){
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("%^RESET%^%^CRST%^%^C255%^Outside a large inn%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C245%^A towering %^C059%^cathedral%^RESET%^%^C245%^ has been built to the northwest on the very crest of a hill. Oddly enough, the sound of %^C201%^dr%^C207%^u%^C201%^nk%^C207%^e%^C201%^n l%^C207%^au%^C201%^ght%^C207%^e%^C201%^r%^RESET%^%^C245%^ reaches your ears, and you realize this isn't a cathedral at all, but an inn. A %^C059%^%^sign%^RESET%^%^C245%^ hanging above the door proudly declares it to be %^RESET%^%^CRST%^%^C244%^\"T%^C243%^h%^C059%^e %^C196%^B%^C124%^lo%^C196%^od%^C124%^y %^RESET%^%^C124%^S%^C196%^co%^C124%^ur%^C196%^g%^C124%^e%^RESET%^ %^C244%^I%^C243%^n%^C059%^n\"%^RESET%^%^C245%^.%^CRST%^\n");
    set_smell("default", "%^RESET%^%^CRST%^%^C214%^There is a faint scent of liquor on the breeze.%^CRST%^");
    set_listen("default", "%^RESET%^%^CRST%^%^C126%^Laughter and drunken conversations spill out over the hills.%^CRST%^");
    set_items(([
        "hills" : "%^RESET%^%^CRST%^%^C156%^You are surrounded by these great majestic green monsters.%^CRST%^",
        "road" : "%^RESET%^%^CRST%^%^C244%^The new road here is just starting to get ruts in it, as is burns an ominous scar across the plains.%^CRST%^",
        "cathedral" : "%^RESET%^%^CRST%^%^C245%^By the looks of it, this was probably once a temple rather than the place of %^C059%^debauchery%^RESET%^%^C245%^ that it has become. Its massive walls loom before you, and %^C214%^i%^C220%^nv%^C226%^it%^C220%^in%^C214%^g l%^C220%^i%^C226%^gh%^C220%^t%^C214%^s%^RESET%^%^C245%^ shine from behind %^C196%^s%^C124%^t%^C201%^a%^C206%^i%^C196%^n%^C206%^e%^C201%^d %^C206%^g%^C201%^%^C196%^l%^C124%^a%^C201%^s%^C206%^s%^RESET%^%^C245%^ windows. A sign hanging above the heavy wooden doors proclaims it to be %^C244%^\"T%^C243%^h%^C059%^e %^C196%^B%^C124%^lo%^C196%^od%^C124%^y %^RESET%^%^C124%^S%^C196%^co%^C124%^ur%^C196%^g%^C124%^e%^RESET%^ %^C244%^I%^C243%^n%^C059%^n\"%^RESET%^%^C245%^.%^CRST%^",
        "sign" : "%^RESET%^%^CRST%^%^C245%^The sign is %^C058%^%^wooden%^RESET%^%^C245%^ and %^C059%^worn%^RESET%^%^C245%^. The lettering is written in %^C196%^b%^C124%^r%^C196%^ig%^C124%^h%^C196%^t r%^C124%^e%^C196%^d%^RESET%^%^C245%^, and beneath it is the image of a %^C059%^black%^RESET%^%^C245%^ and %^C255%^%^coiled%^C059%^ nine-stranded scourge%^RESET%^%^C245%^.%^CRST%^",
        ]));
    set_exits( ([
        "north" : "/d/dagger/tonovi/1path2",
        "inn" : "/d/player_houses/innaeli/rooms/bar",
        "south" : "/d/dagger/road/road7",
        "northeast" : "/d/dagger/yniam/room/road1",
        ]));
    set_door("cathedral door", "/d/player_houses/innaeli/rooms/bar", "inn", 0);
    set_door_description("cathedral door", "%^RESET%^%^CRST%^%^C059%^The doors are made of thick stone that looks quite heavy. They can be swung open to create a grand entrance into the establishment. Each gray stone door has a centrally placed, large iron knocker, featuring the image of a laughing face although upon closer inspection it appears the mouth is parted into an anguished scream. How inviting!%^CRST%^");
}

