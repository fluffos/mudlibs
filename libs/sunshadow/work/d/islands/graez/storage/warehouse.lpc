//Warehouse Inherit

#include "../graez.h"
inherit VAULT;

void create() {
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("warehouse");
    set_short("%^C094%^warehouse%^CRST%^");
    set_long("This building has been hastily constructed of %^C143%^light material%^CRST%^ to build a building for any purpose. The walls are %^C094%^lumber %^CRST%^with a %^C231%^daub %^CRST%^over it  and the floors are %^C094%^bare lumber%^CRST%^ with a sprinkling of %^C220%^straw %^CRST%^on it.\n");


    set_items(([
        ({"walls","daub"}) : "The walls are constructed of %^C094%^lumber %^CRST%^with %^C231%^daub %^CRST%^in between the posts. this quick construction method protects the inside but without much expense.",
        ({"floor","straw"}) : "The %^C094%^floors %^CRST%^are %^C094%^bare lumber%^CRST%^ with a sprinkling of %^C220%^straw%^CRST%^.",
    ]));
}
