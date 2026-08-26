// Hound Camp -LoKi 2021

#include <std.h>
#include "../serakii.h"

inherit CROOM;
void pick_critters();

string seas;

void create() {
    pick_critters();
    set_repop(30);
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(RUTTED_TRACK);
    set_property("indoors",0);
    set_name("chaotic military camp");
    set_property("light",2);
    set_short("%^C242%^chao%^C062%^t%^C242%^ic mi%^C062%^"+
	"l%^C242%^itary c%^C063%^a%^C242%^mp%^CRST%^");
    seas = season(time());
        set_long("blah");
        switch(seas){
        case "summer":
        set_long("%^C028%^This military camp is at the same "+
		"time %^C013%^chaotic %^C028%^and %^C005%^organized%^C028%^, "+
		"though without a keen eye or a guide to their movements, "+
		"there is more chaos here than organization. The %^C003%^"+
		"ground %^C028%^has been pounded hard and %^C227%^dry "+
		"%^C028%^in the %^C197%^summer heat%^C028%^ and every "+
		"step pulls up a plume of %^C094%^dust%^C028%^. Large "+
		"%^C243%^canvas tents%^C028%^ line up on either side of "+
		"you and look to be for officers and supplies. There "+
		"are %^C094%^catapults %^C028%^and %^C247%^large "+
		"arbalests%^C028%^ ready for deployment and "+
		"%^C247%^equipment %^C028%^is stacked and ready. "+
		"With all the %^C022%^trees %^C028%^felled the "+
		"%^C160%^heat%^C028%^ is oppressive.\n%^CRST%^");
    break;
        case "spring":
        set_long("%^C111%^This %^C094%^military camp%^C111%^ is "+
		"at the same time %^C135%^chaotic %^C111%^and "+
		"%^C055%^organized%^C111%^, though without a keen eye "+
		"or a guide to their movements, there is more chaos here "+
		"than organization. The ground is %^C094%^muddy %^C111%^with "+
		"the recent %^C019%^rains %^C111%^and %^C019%^puddles of "+
		"water %^C111%^pool near the %^C246%^tents%^C111%^. Large "+
		"canvas tents line up on either side of you and look to be "+
		"for officers and supplies. There are %^C094%^catapults "+
		"%^C111%^and %^C246%^large arbalests%^C111%^ ready for "+
		"deployment and equipment is stacked and ready. The site "+
		"looks like it used to be a %^C022%^forest%^C111%^, as there "+
		"are %^C094%^wet tree stumps%^C111%^ here and there.\n%^CRST%^");
    break;

    case "winter":
        set_long("%^C015%^This %^C094%^military camp%^C015%^ is at the "+
		"same time %^C135%^chaotic %^C015%^and %^C055%^organized%^C015%^"+
		", though without a keen eye or a guide to their movements, "+
		"there is more chaos here than organization. A %^C247%^thin "+
		"coat of snow%^C015%^ covers the ground and %^C251%^piles of "+
		"snow%^C015%^ from clearing it are piled near the %^C242%^"+
		"tents%^C015%^. Large %^C243%^canvas tents%^C015%^ line up on "+
		"either side of you and look to be for officers and supplies. "+
		"There are %^C094%^catapults %^C015%^and %^C242%^large "+
		"arbalests%^C015%^ ready for deployment and %^C094%^equipment "+
		"%^C015%^is stacked and ready.\n%^CRST%^");
    break;
    case "autumn":
        set_long("%^C143%^This %^C094%^military camp%^C143%^ is at "+
		"the same time %^C135%^chaotic %^C143%^and %^C092%^"+
		"organized%^C143%^, though without a keen eye or a guide "+
		"to their movements, there is more chaos here than "+
		"organization. %^C100%^Dry leaves%^C143%^ from the %^C028%^"+
		"faraway forest%^C143%^ somehow have drifted here on the "+
		"%^C044%^chill wind%^C143%^ to fly around you. Large %^C242%^"+
		"canvas tents%^C143%^ line up on either side of you and look "+
		"to be for officers and supplies. There are %^C094%^catapults "+
		"%^C143%^and %^C242%^large arbalests%^C143%^ ready for "+
		"deployment and %^C094%^equipment %^C143%^is stacked and "+
		"ready.\n%^CRST%^");
    break;
    }
    set_items(([
({"catapult","arbalest"}) : "%^C094%^the %^C241%^arbalests "+
"%^C094%^and %^C142%^catapults %^C094%^are each wagon sized "+
"%^C124%^siege %^C094%^weapons ready for action.%^CRST%^",
({"tents","canvas tents"}) : "%^C242%^Black canvas tents dot "+
"the camp, obviously for important soldiers and equipment%^CRST%^",
({"trees","stumps"}) : "%^C028%^This used to be a forest, "+
"but it was obviously %^C088%^cut %^C028%^down to make a "+
"place for this %^C242%^camp %^C028%^and all that is left are %^C094%^stumps%^C028%^.%^CRST%^",

    ]));

set_smell("default","%^C142%^You smell %^C094%^leather %^C142%^and %^C242%^steel%^C142%^.%^CRST%^");
set_listen("default","%^C022%^You hear the %^C094%^busy camp%^C022%^ all around you.%^CRST%^");


}

void pick_critters(){
   switch(random(6)){
         case 0:   set_monsters(
({MOBS"hound",MOBS"attack_dog"}),({random(4),random(2)}) );
                   break;
         case 1:   set_monsters(
({MOBS"hound"}),({random(5)}) );
                   break;
         case 2:   set_monsters(
({MOBS"houndoff",MOBS"attack_dog"}),({1,random(1)+1}) );
                   break;
         case 3:   set_monsters(
({MOBS"hound"}),({random(5)}) );
                   break;
         case 4..5: break;
   }
}
