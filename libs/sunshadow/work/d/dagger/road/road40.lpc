// Chernobog (5/5/22)
// Dagger Road Crossroads

#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create(){
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(DIRT_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_name("along the Dagger Road");
    set_short("%^RESET%^%^CRST%^%^C030%^The %^C250%^r%^C247%^o%^C244%^a%^C059%^d %^C030%^through Dagger%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C030%^%^This is the crossroads between several regions of Dagger. The %^C036%^lush fields %^C030%^of the %^C144%^Yniam Plains %^RESET%^%^C030%^spread out to the west, the tall grasses and brush waving lightly in the breeze. One road leads into the %^C100%^marsh %^RESET%^%^C030%^ to the north, the vibrant vegetation descending into soggy muck and morass, though the trees of the %^C040%^Kilkean %^C030%^stand strong to the east as they cage the foul swamp against the distant mountains.%^CRST%^\n");
    set_smell("default", "%^RESET%^%^CRST%^%^C100%^The stink of the nearby marsh %^C065%^fouls %^C100%^the air.%^CRST%^");
    set_listen("default", "%^RESET%^%^CRST%^%^C024%^You can hear the rustling of the %^C045%^w%^C087%^in%^C045%^d%^C087%^s %^C024%^along the tall grasses.%^CRST%^");
    set_items(([
        "road" : "%^RESET%^%^CRST%^%^C058%^This trade route has seen countless caravans and travelers as it bisects the Dagger region. The ground is %^C136%^packed %^C058%^and %^C130%^scarred %^C058%^by deep ruts, bordered by a sparse collection of %^C244%^ro%^C247%^c%^C244%^k%^C247%^s %^RESET%^%^C058%^on either side.%^CRST%^",
        ({"fields", "plains"}) : "%^RESET%^%^CRST%^%^C156%^To the west, the land spreads out in %^C046%^ge%^C118%^nt%^C154%^le %^C046%^sl%^C118%^op%^C154%^es%^RESET%^%^C156%^, covered in tall grasses and a spattering of %^C065%^low brush%^C156%^.%^CRST%^",
        "marsh" : "%^RESET%^%^CRST%^%^C100%^Just along the northern horizon, the Yniam Plains slowly transition to the swamplands of the %^C101%^Marsh of Fear%^C100%^.%^CRST%^",
        ({"forest", "trees"}) : "%^RESET%^%^CRST%^%^C065%^The %^C040%^Kilkean %^C040%^Forest %^RESET%^%^C065%^is dense and ancient, standing firm against the %^C059%^darkness %^C065%^of the %^C100%^Marsh of Fear%^C065%^. It forms the northeastern border of the Yniam Plains.%^CRST%^",
        ]));
    set_exits(([
        "north" : RPATH "road41",
        "southwest" : RPATH "road39",
        "east" : RPATH "road81",
        ]));
}

void reset(){
    ::reset();
    RDEMON->startup();
}

