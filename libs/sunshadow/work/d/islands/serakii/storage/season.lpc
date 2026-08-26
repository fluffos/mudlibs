// Season room template

#include <std.h>
#include "../serakii.h"

inherit CROOM;

string seas;

void create() {
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(RUTTED_TRACK);
    set_property("indoors",0);
    set_name("name");
    set_property("light",2);
    set_short("%^RESET%^%^ORANGE%^short%^RESET%^");
    seas = season(time());
	set_long("%^RESET%^blah%^RESET%^");
	switch(seas){
	case "summer": 
        set_long("%^RESET%^%^ORANGE%^summer. %^RESET%^");
    break;
	case "spring": 
        set_long("%^RESET%^%^ORANGE%^spring. %^RESET%^");
    break;
    case "winter":
        set_long("%^RESET%^%^ORANGE%^winter. %^RESET%^");
    break;
    case "autumn":
        set_long("%^RESET%^%^ORANGE%^autumn. %^RESET%^");
    break;
    }	
    set_items(([
        ({"something"}) : "%^RESET%^%^ORANGE%^something.%^RESET%^",
({"somethingelse","somethingelse2"}) : "%^RESET%^%^ORANGE%^somethingelse2%^RESET%^",
    ]));
    set_property("room lore",1);

set_smell("default","%^RESET%^%^ORANGE%^Nothing.%^RESET%^");
set_listen("default","%^RESET%^%^GREEN%^Nothing.%^RESET%^");


}
