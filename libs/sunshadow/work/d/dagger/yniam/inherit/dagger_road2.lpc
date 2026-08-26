// Chernobog (5/5/22)
// Dagger Road Inherit #2

#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(DIRT_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_name("along the Dagger Road");
    set_short("%^RESET%^%^CRST%^%^C030%^The %^C250%^r%^C247%^o%^C244%^a%^C059%^d %^C030%^through Dagger%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C030%^%^This heavily traveled %^C250%^r%^C247%^o%^C244%^a%^C059%^d %^C030%^cuts its way through the Dagger region, connecting several city-states in the area. The %^C036%^lush fields %^C030%^of the %^C144%^Yniam Plains %^RESET%^%^C030%^spread out to the west, the tall grasses and brush waving lightly in the breeze. The plains slowly give way to the encroaching %^C100%^marsh %^RESET%^%^C030%^far to the north, the vibrant vegetation descending into soggy muck and morass, though the trees of the %^C040%^Kilkean %^C030%^stand stalwart along the northeastern horizon. To the south, the massive %^C245%^zi%^C247%^g%^C245%^gu%^C247%^r%^C245%^a%^C247%^t %^C030%^of %^RESET%^%^C059%^Nurval %^C030%^rises up in the distance, the skies preternaturally %^C024%^darkened %^C030%^in its proximity.%^CRST%^\n");
    set_smell("default", "%^RESET%^%^CRST%^%^C144%^A breeze carries with it the smells of the %^C120%^pl%^C156%^a%^C120%^i%^C156%^n%^C120%^s%^C144%^.%^CRST%^");
    set_listen("default", "%^RESET%^%^CRST%^%^C024%^You can hear the rustling of the %^C045%^w%^C087%^in%^C045%^d%^C087%^s %^C024%^along the tall grasses.%^CRST%^");
    set_items(([
        "road" : "%^RESET%^%^CRST%^%^C058%^This trade route has seen countless caravans and travelers as it bisects the Dagger region. The ground is %^C136%^packed %^C058%^and %^C130%^scarred %^C058%^by deep ruts, bordered by a sparse collection of %^C244%^ro%^C247%^c%^C244%^k%^C247%^s %^RESET%^%^C058%^on either side.%^CRST%^",
        ({"fields", "plains"}) : "%^RESET%^%^CRST%^%^C156%^To the west, the land spreads out in %^C046%^ge%^C118%^nt%^C154%^le %^C046%^sl%^C118%^op%^C154%^es%^RESET%^%^C156%^, covered in tall grasses and a spattering of %^C065%^low brush%^C156%^.%^CRST%^",
        "ziggurat" : "%^RESET%^%^CRST%^%^C245%^Visible from this distance, the structure must be %^C059%^massive%^C245%^.%^CRST%^",
        "marsh" : "%^RESET%^%^CRST%^%^C100%^Just along the northern horizon, the Yniam Plains slowly transition to the swamplands of the %^C101%^Marsh of Fear%^C100%^.%^CRST%^",
        ({"forest", "trees"}) : "%^RESET%^%^CRST%^%^C065%^The %^C040%^Kilkean %^C040%^Forest %^RESET%^%^C065%^is dense and ancient, standing firm against the %^C059%^darkness %^C065%^of the %^C100%^Marsh of Fear%^C065%^. It forms the northeastern border of the Yniam Plains.%^CRST%^",
        ]));
}

