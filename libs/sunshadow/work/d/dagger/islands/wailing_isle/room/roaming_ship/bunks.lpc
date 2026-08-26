// Chernobog & Titania (4/8/22)
// The Wailing Isle - Roaming Ship Hallway

#include <std.h>
#include "../../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no sticks", 1);
    set_name("crew quarters");
    set_short("%^RESET%^%^CRST%^%^C037%^The Crew Quarters of a Merchant's Ship%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C037%^Berthing compartments line the walls, three bunks high on either side. Each compartment contains a %^C081%^small bed%^C037%^ and an even smaller space to keep personal effects, with a meager allowance of privacy in the form of a %^C025%^linen curtain%^C037%^. There is not a lot of space to move around in here, but a %^C123%^small window%^C037%^ lets in some %^C158%^light%^C037%^ and %^C087%^air%^RESET%^%^C037%^.%^CRST%^\n");
    set_smell("default","%^RESET%^%^CRST%^%^C152%^It smells of the %^C159%^sea%^C152%^ and too many %^C159%^s%^C123%^w%^C159%^ea%^C123%^t%^C159%^y bo%^C123%^di%^C159%^es%^RESET%^%^C152%^ in tight company.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C138%^The paneled walls creak in time with the rocking of the ship.%^CRST%^");  
	set_items(([
		"window" : "%^RESET%^%^CRST%^%^C123%^This small circular window lets in a small bit of %^C158%^light%^C123%^, and it can even be opened to %^C087%^air out%^C123%^ the room from time to time.%^CRST%^",
		({"bunks", "berth", "curtains"}) : "%^RESET%^%^CRST%^%^C101%^The small compartments are nothing fancy. A simple bed covered in %^C025%^blue linens%^C101%^, tucked behind a %^C025%^matching curtain%^C101%^. Each compartment has a %^C102%^small locked chest%^C101%^ where the ship's crew can stash some personal belongings. It isn't much, but on a ship like this, even a semblance of privacy and personal space can buy some %^C105%^sanity%^C101%^.%^CRST%^",
		"floor" : "%^RESET%^%^CRST%^%^C101%^The small area is kept tidy and free from obstacles.%^CRST%^",
        ]));
    set_exits(([
        "galley" : SHIP"galley",
        "hallway" : SHIP"hallway",
        ]));
}

