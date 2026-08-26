// Chernobog (3/15/22)
// Interior Yniam Road

#include <std.h>
#include "../defs.h"
inherit INH"road2";

void create(){
    ::create();
    set_long(::query_long()+"%^RESET%^%^CRST%^%^C101%^A broad %^C033%^ri%^C039%^v%^C045%^e%^C033%^r %^RESET%^%^C101%^winds its way through here, arriving from the north and curving off to the east as it heads towards the distant coast. A simple %^C244%^st%^C248%^o%^C059%^n%^C244%^e b%^C248%^r%^C245%^id%^C248%^g%^C244%^e %^RESET%^%^C101%^arches across the span, permitting small vessels to pass below.%^CRST%^\n");
    add_item("bridge", "%^RESET%^%^CRST%^%^C058%^Fashioned from the traditional %^C244%^bl%^C248%^a%^C059%^c%^C244%^k s%^C248%^t%^C245%^o%^C248%^n%^C244%^e %^RESET%^%^C058%^quarried from Tonovi, these bridges are solid and constantly put to the test by traveling caravans.%^CRST%^");
    add_item("river", "%^RESET%^%^CRST%^%^C058%^The rolling plains are interrupted by the %^C033%^si%^C039%^n%^C045%^u%^C033%^ou%^C039%^s %^C045%^w%^C033%^at%^C039%^e%^C045%^r%^C033%^s %^RESET%^%^C058%^of the Shelk passing through. Clear water flows in steady currents, and fish dart about quickly through the river.%^CRST%^");
    set_exits(([
        "southwest" : ROOMS"road1",
        "northeast" : ROOMS"palisade1",
        ]));
}

void reset(){
    ::reset();
    
    if(!present("ambiance device")) new(OBJ"ambiance")->move(this_object());
}

