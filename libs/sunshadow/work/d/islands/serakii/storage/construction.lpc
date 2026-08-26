// Construction Site 

#include <std.h>
#include "../serakii.h"

inherit CROOM;

void create(){
   ::create();
    set_property("indoors",0);
    set_name("work site");
    set_short("%^C059%^wo%^C094%^r%^C059%^k s%^C094%^i%^C059%^te%^CRST%^");
set_long("%^C058%^This used to be some other %^C060%^building%^C058%^ but "+
"it has been torn down to the roots for some new construction. %^C251%^Half "+
"walls%^C058%^ stand around you with fresh mortar and the %^C061%^floors%^C058%^ "+
"are half-laid. Piles of %^C243%^rubble%^C058%^ lay off to the side for workers "+
"to clear and new building %^C094%^supplies%^C058%^ are prepared for "+
"construction.%^CRST%^\n");

    set_items(([
        ({"floor"}) : "%^C059%^The floors here are rough and only the start of tiles have been laid.%^CRST%^",
        ({"walls"}) : "%^C245%^The first foundations of walls are constructed.%^CRST%^",
({"rubble","supplies"}) : "%^C102%^rubble from the previous building has been piled up for collection and new wood and tiles have been set up for the next phase of construction.%^CRST%^",
    ]));

set_smell("default","%^C066%^You smell %^C094%^sawdust%^C066%^ and %^C252%^stone%^CRST%^");
set_listen("default","%^C038%^You hear %^C060%^construction%^C038%^ all around you.%^CRST%^");

}
