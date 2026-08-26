// Chernobog & Titania (8/16/22)
// Wailing Isle - Abandoned House

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("an abandoned house");
    set_short("%^RESET%^%^CRST%^%^C138%^an abandoned house%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C065%^Time has been less kind to this room. The wall and ceiling have collapsed in one corner, inviting %^C064%^nature%^C065%^ to reclaim the space. %^C059%^Black mold%^RESET%^%^C065%^ grows along the fractured wall, hidden beneath the %^C070%^lush tendrils%^C065%^ of %^C070%^i%^C064%^v%^C070%^y%^RESET%^%^C065%^ that creep through the gaping hole. A rotted, %^C058%^empty chest%^C065%^ sits at the foot of a %^C058%^plain wooden bed%^C065%^. Dirty %^C071%^water stains%^RESET%^%^C065%^ weep from the ceiling to floor, peeling away at the %^C072%^green paint%^C065%^ of the faded walls.%^CRST%^\n");
    set_smell("default","%^RESET%^%^CRST%^%^C073%^The %^C079%^salt-tinged air%^C073%^ mingles with scent of %^C064%^m%^C058%^o%^C064%^ld%^RESET%^%^C073%^ and %^C064%^dec%^C058%^a%^C064%^y%^C073%^.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C065%^You hear the occasional bustle of activity from outside.%^CRST%^");
    set_items(([
        "bed" : "%^CRST%^%^RESET%^%^C243%^Although bare, a mattress is still settled on the bones of the creaky bed.%^CRST%^",
        "chest" : "%^CRST%^%^RESET%^%^C243%^The chest is little more than some planks of wood fitted together to form a box. The bottom is damp and rotted from water damage.%^CRST%^",
        ({"nature", "ivy", "mold", "holes"}) : "%^CRST%^%^RESET%^%^C070%^The large hole left in the wall from the collapse is filled with a thicket of %^C076%^ivy%^C070%^ that is actually quite pretty, despite its invasive destruction. %^C059%^Mold%^C070%^ lives in the damp spaces caused by outside elements, painting the wall a sinister shade of %^C059%^black%^C070%^.%^CRST%^",
        ]));
    set_exits(([
        "room" : ROOMS"house1",
        ]));
}

