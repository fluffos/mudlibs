#include <std.h>
#include "../serakii.h"

inherit CROOM;

string seas;

void create() {
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_name("trade road");
    set_short("%^C094%^t%^C181%^r%^C094%^ade ro%^C181%^a%^C094%^d%^CRST%^");
	
    seas = season(time());
        set_long("blah");
        switch(seas){
        case "summer":
            set_long("%^C160%^This %^C130%^trade road%^C160%^ has been %^C196%^baked %^C160%^and packed by a %^C250%^thousand years%^C160%^ of heavy travel and the heat of the %^C009%^Summerstime%^C160%^. The %^C130%^road %^C160%^itself is actually set with %^C250%^giant interlocking stones%^C160%^ though with age those have been covered in %^C130%^dirt%^C160%^. To the north you see three %^C244%^large fortresses%^C160%^ dominating the %^C074%^skyline %^C160%^and beyond that a %^C250%^massive mountain range%^C160%^ and a single shining %^C253%^beacon of a city%^C160%^. To the east is a %^C028%^large forest%^C160%^ obscured with %^C255%^mist %^C160%^and %^C250%^clouds%^C160%^. To the west you can still smell the %^C031%^sea%^C250%^.%^CRST%^\n");
        break;
        case "spring":
            set_long("%^C029%^This %^C130%^trade road%^C029%^ is a mess muck of %^C130%^mud %^C029%^from the %^C043%^Springstime %^C032%^rains%^C029%^. The %^C094%^road %^C029%^itself is actually set with giant interlocking stones though with age those have been covered in %^C094%^dirt%^C029%^. %^C201%^Flowers%^C029%^ and waves of %^C131%^pollen %^C029%^flow on the breeze. To the north you see %^C248%^three large fortresses%^C029%^ dominating the skyline and beyond that a %^C244%^massive mountain range%^C029%^ and a single %^C250%^shining beacon of a city%^C029%^. To the east is a %^C034%^large forest%^C029%^ obscured with %^C255%^mist %^C029%^and %^C250%^clouds%^C029%^. To the west you can still smell the %^C032%^sea%^C029%^.%^CRST%^\n");
        break;
        case "winter":
            set_long("%^C252%^Covered in a %^C247%^light dusting of snow%^C252%^, the %^C058%^road %^C252%^itself is actually set with %^C245%^giant interlocking stones%^C252%^ though with age those have been covered in %^C094%^dirt%^C252%^. To the north you see %^C246%^three large fortresses%^C252%^ dominating the %^C075%^skyline %^C252%^and beyond that a massive mountain range and a %^C244%^wall of steel black clouds%^C252%^ obscuring everything else. To the east is a %^C028%^large forest%^C252%^ obscured with %^C248%^mist %^C252%^and %^C245%^clouds%^C252%^. The snow banks around you change as the wind blows across the %^C094%^road%^C252%^.%^CRST%^\n");
        break;
        case "autumn":
            set_long("%^C066%^This %^C094%^trade road%^C066%^ is %^C246%^abandoned%^C066%^, but clear. The %^C094%^road %^C066%^itself is actually set with %^C246%^giant interlocking stones%^C066%^ though with %^C248%^age %^C066%^those have been covered in layers of %^C022%^fallen leaves%^C066%^ and %^C095%^dirt%^C066%^. To the north you see %^C246%^three large fortresses%^C066%^ dominating the skyline and beyond that a %^C246%^massive mountain range%^C066%^ and a single %^C252%^shining beacon of a city%^C066%^. To the east is a %^C022%^large forest%^C066%^ obscured with %^C250%^mist %^C066%^and %^C246%^clouds%^C066%^. To the west you can still smell the %^C027%^sea%^C066%^. There is an early %^C044%^chill %^C066%^to the air.%^CRST%^\n%^CRST%^");
        break;
    }

set_smell("default","%^C138%^You smell %^C094%^dirt %^C138%^and %^C243%^stone%^C094%^.%^CRST%^");

set_listen("default","%^C062%^the wind rushing along the road.%^CRST%^");


}
