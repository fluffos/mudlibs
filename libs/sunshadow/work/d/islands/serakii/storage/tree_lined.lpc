// Tree Lined Avenue - Karon'dale

#include <std.h>
#include "../serakii.h"

inherit VAULT;

string seas;

void create() {
    ::create();
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_property("indoors",0);
    set_name("tree lined avenue");
    set_short("%^C023%^tr%^C022%^e%^C023%^e "+
	"l%^C022%^i%^C023%^ned%^CRST%^ %^C101%^"+
	"a%^C103%^v%^C101%^en%^C103%^u%^C101%^e%^CRST%^");
    seas = season(time());
        set_long("blah");
    switch(seas){
    case "summer":
        set_long("The %^C247%^road %^CRST%^here "+
		"is wide, enough for several %^C094%^wagons "+
		"%^CRST%^to travel side by side. Instead of "+
		"the %^C059%^trade%^CRST%^ road that was "+
		"%^C094%^dirt%^CRST%^, this road is set "+
		"with %^C249%^interlocking bricks%^CRST%^ "+
		"each three feet wide and long. On either "+
		"side of the road is a strip of %^C028%^well "+
		"tended grass %^CRST%^and perfectly "+
		"%^C022%^manicured trees%^CRST%^. Even in "+
		"the heat of %^C124%^Summerstime %^CRST%^the "+
		"%^C028%^grass %^CRST%^is in perfect health, "+
		"meaning someone is expending great "+
		"%^C226%^resources %^CRST%^to keep the "+
		"%^C028%^grass %^CRST%^and %^C022%^trees "+
		"%^CRST%^perfect. This contrasts greatly "+
		"with the %^C241%^desolate ruins%^CRST%^ "+
		"on either side of the %^C059%^road%^CRST%^.\n");
        set_smell("default","%^C023%^You smell fresh grass%^CRST%^.");
        set_listen("default","%^C241%^You hear the wind whistling through the ruins%^CRST%^.");
    break;
	
    case "spring":
        set_long("The %^C247%^road %^CRST%^here is "+
		"wide, enough for several %^C094%^wagons "+
		"%^CRST%^to travel side by side. Instead "+
		"of the %^C059%^trade%^CRST%^ road that was "+
		"%^C094%^dirt%^CRST%^, this road is set with "+
		"%^C249%^interlocking bricks%^CRST%^ each "+
		"three feet wide and long. On either side "+
		"of the road is a strip of %^C028%^well "+
		"tended grass %^CRST%^and perfectly "+
		"%^C022%^manicured trees%^CRST%^. While "+
		"everything else you have seen on the "+
		"island is soaked in the %^C026%^Springstime "+
		"%^C159%^rain %^CRST%^the road has been "+
		"cleaned, meaning someone is expending great "+
		"%^C226%^resources %^CRST%^to keep the "+
		"%^C028%^grass %^CRST%^and %^C022%^trees "+
		"%^CRST%^perfect. This contrasts greatly "+
		"with the %^C241%^desolate ruins%^CRST%^ "+
		"on either side of the %^C059%^road%^CRST%^.\n");
        set_smell("default","%^C023%^You smell fresh grass%^CRST%^.");
        set_listen("default","%^C241%^You hear the wind whistling through the ruins%^CRST%^.");
    break;
	
    case "winter":
        set_long("The %^C247%^road %^CRST%^here is "+
		"wide, enough for several %^C094%^wagons "+
		"%^CRST%^to travel side by side. Instead "+
		"of the %^C059%^trade%^CRST%^ road that was "+
		"%^C094%^dirt%^CRST%^, this road is set with "+
		"%^C249%^interlocking bricks%^CRST%^ each "+
		"three feet wide and long. On either side "+
		"of the road is a strip of %^C028%^well tended "+
		"grass %^CRST%^and perfectly %^C022%^manicured "+
		"trees%^CRST%^. %^C255%^Snow%^CRST%^ has fallen "+
		"all around you but the road has been cleared, "+
		"small piles off to the side, meaning someone "+
		"is expending great %^C226%^resources "+
		"%^CRST%^to keep the %^C028%^grass %^CRST%^and "+
		"%^C022%^trees %^CRST%^perfect. This contrasts "+
		"greatly with the %^C241%^desolate ruins%^CRST%^ "+
		"on either side of the %^C059%^road%^CRST%^.\n");
        set_smell("default","%^C023%^You smell fresh grass%^CRST%^.");
        set_listen("default","%^C241%^You hear the wind whistling through the ruins%^CRST%^.");
    break;
	
    case "autumn":
        set_long("The %^C247%^road %^CRST%^here is "+
		"wide, enough for several %^C094%^wagons "+
		"%^CRST%^to travel side by side. Instead "+
		"of the %^C059%^trade%^CRST%^ road that was "+
		"%^C094%^dirt%^CRST%^, this road is set "+
		"with %^C249%^interlocking bricks%^CRST%^ "+
		"each three feet wide and long. On either "+
		"side of the road is a strip of "+
		"%^C028%^well tended grass %^CRST%^and "+
		"perfectly %^C022%^manicured trees%^CRST%^. "+
		"Piles of %^C100%^wet leaves%^CRST%^ have "+
		"been collected just off of the "+
		"%^C059%^road %^CRST%^and %^C028%^grass "+
		"%^CRST%^and onto the %^C241%^ruins "+
		"%^CRST%^beside, meaning someone is expending "+
		"great %^C226%^resources %^CRST%^to keep the "+
		"%^C028%^grass %^CRST%^and %^C022%^trees "+
		"%^CRST%^perfect. This contrasts greatly "+
		"with the %^C241%^desolate ruins%^CRST%^ "+
		"on either side of the %^C059%^road%^CRST%^.\n");
        set_smell("default","%^C023%^You smell fresh grass%^CRST%^.");
        set_listen("default","%^C241%^You hear the wind whistling through the ruins%^CRST%^.");
    break;
    }
    set_items(([
        ({"trees"}) : "The %^C028%^trees %^CRST%^along "+
		"the %^C059%^road %^CRST%^are set at a perfect "+
		"ten foot interval each. They have %^C094%^tall "+
		"straight trunks%^CRST%^ and a %^C028%^shaped "+
		"foliage%^CRST%^. They are not %^C124%^fruit "+
		"%^CRST%^bearing, or provide any "+
		"%^C241%^shade%^CRST%^, obviously here for "+
		"%^C025%^decoration %^CRST%^only.\n",
        ({"ruins"}) : "on either side of the perfect "+
		"road, are absolutely %^C241%^desolate "+
		"ruins%^CRST%^ of what was once a "+
		"%^C060%^city%^CRST%^. With the %^C060%^road "+
		"%^CRST%^and %^C028%^trees %^CRST%^so perfectly "+
		"maintained it is insanity that all these "+
		"%^C241%^ruins %^CRST%^have remained untouched.\n",
        ({"ground","road"}) : "The %^C059%^road "+
		"%^CRST%^is set with %^C241%^interlocking "+
		"stones%^CRST%^, each large enough it would "+
		"take a %^C095%^team %^CRST%^of men to place "+
		"it. It is impeccably maintained, as if "+
		"%^C095%^workers %^CRST%^are out constantly "+
		"cleaning and repairing it.\n",
    ]));

}

