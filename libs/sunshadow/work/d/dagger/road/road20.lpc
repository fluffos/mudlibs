#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create(){
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_name("along the Dagger Road");
    set_short("%^RESET%^%^CRST%^%^C030%^The %^C250%^r%^C247%^o%^C244%^a%^C059%^d %^C030%^through Dagger%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C030%^%^This heavily traveled %^C250%^r%^C247%^o%^C244%^a%^C059%^d %^C030%^cuts its way through the Dagger region, connecting several city-states in the area. The %^C036%^lush fields %^C030%^of the %^C144%^Yniam Plains %^RESET%^%^C030%^spread out to the west, the tall grasses and brush waving lightly in the breeze. In the east, the massive %^C245%^zi%^C247%^g%^C245%^gu%^C247%^r%^C245%^a%^C247%^t %^C030%^of %^RESET%^%^C059%^Nurval %^C030%^rises up in the distance, the skies preternaturally %^C024%^darkened %^C030%^in its proximity. %^C028%^There is a bend in the road with a curious %^C058%^camp %^C028%^set up to the side.%^CRST%^\n");
    set_smell("default", "%^RESET%^%^CRST%^%^C144%^A breeze carries with it the smells of the %^C120%^pl%^C156%^a%^C120%^i%^C156%^n%^C120%^s%^C144%^.%^CRST%^");
    set_listen("default", "%^RESET%^%^CRST%^%^C024%^You can hear the rustling of the %^C045%^w%^C087%^in%^C045%^d%^C087%^s %^C024%^along the tall grasses.%^CRST%^");
    set_items(([
        "road" : "%^RESET%^%^CRST%^%^C058%^This trade route has seen countless caravans and travelers as it bisects the Dagger region. The ground is %^C136%^packed %^C058%^and %^C130%^scarred %^C058%^by deep ruts, bordered by a sparse collection of %^C244%^ro%^C247%^c%^C244%^k%^C247%^s %^RESET%^%^C058%^on either side.%^CRST%^",
        ({"fields", "plains"}) : "%^RESET%^%^CRST%^%^C156%^To the west, the land spreads out in %^C046%^ge%^C118%^nt%^C154%^le %^C046%^sl%^C118%^op%^C154%^es%^RESET%^%^C156%^, covered in tall grasses and a spattering of %^C065%^low brush%^C156%^.%^CRST%^",
        "ziggurat" : "%^RESET%^%^CRST%^%^C245%^Visible from this distance, the structure must be %^C059%^massive%^C245%^.%^CRST%^",
        "camp" : "%^RESET%^%^CRST%^%^C058%^The grass is faded and trampled around the wagon. A small ring of %^C244%^st%^C248%^o%^C244%^n%^C248%^e%^C244%^s %^RESET%^%^C058%^rests nearby, full of ash from previous campfires.%^CRST%^",
        ]));
    set_exits(([
        "southwest" : RPATH "road19",
        "north" : RPATH "road21",
        "west" : "/d/dagger/yniam/room/road7",
        ]));
    if(!present("shopkeeper"))   new("/d/token_hunt/mid_vendor")->move(TO);
    if(!present("dino"))         new("/d/token_hunt/mid_dino")->move(TO);
    if(!present("wagon"))        new("/d/token_hunt/wagon")->move(TO);
}

void init(){
    ::init();
    // Calls wandering monster daemon
    RDEMON->startup();
}

void reset(){
    ::reset();
    if(!present("shopkeeper"))   new("/d/token_hunt/mid_vendor")->move(TO);
    if(!present("dino"))         new("/d/token_hunt/mid_dino")->move(TO);
    if(!present("wagon"))        new("/d/token_hunt/wagon")->move(TO);
}

