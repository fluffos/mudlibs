// Institute courtyard Port Serith Institute

#include <std.h>
#include "../../serakii.h"

inherit VAULT;

void create() {
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);

    set_name("Institute Courtyard");
    set_property("light",2);
    set_short("%^C246%^In%^C028%^s%^C246%^titute co%^C028%^u%^C246%^"+
    "rtya%^C029%^r%^C246%^d%^CRST%^");
set_long("Before you stands a %^C059%^single story complex%^CRST%^. "+
"The %^C043%^Institute for Trades%^CRST%^ is a %^C095%^half-timbered%^CRST%^ "+
"building consisting of decorative curved saltires filled "+
"with %^C246%^brick%^CRST%^. A gleaming glass and copper dome can "+
"be seen beyond the lower %^C088%^red tile roof%^CRST%^. You can "+
"tell that that the complex is expansive. Well maintained "+
"%^C028%^bushes%^CRST%^ line the building and a %^C220%^plaque "+
"is placed%^CRST%^ beside the door.\n");

    set_items(([

    ({"plaque"}) : "%^C221%^A brass plaque has been attached to the wall.\n\n"+
    "\n------------- The Port Serith Institute of Trades ------"+
    "---------\n\n%^C143%^This institute, and our "+
"ability to learn to rebuild is a gift we must pass on. "+
    "May our work ring true and our crafts used for the greater "+
    "good of the people.\n\nOur thanks go to those who made this "+
    "possible through donations and work. Sophia, Kye, "+
    "Gwenhwyfar, and Uriah.\n\nProvost Hastings Growingdays, 759 SG%^CRST%^\n\n"+
    "%^C221%^-----------------------------------------------------------------\n\n",
    ({"hedges","bushes"}) : "The %^C028%^bushes%^CRST%^ have been tended to carefully. "+
    "They are also, surprisingly %^C124%^fruit bearing%^CRST%^, allowing "+
    "the people to forage from them in the right season. ",


    ]));


set_smell("default","You smell a various mixture of %^C060%^interesting%^CRST%^ %^C142%^scents%^CRST%^ from inside the %^C245%^building%^CRST%^");
set_listen("default","You hear %^C074%^birds%^CRST%^ singing in the %^C028%^bushes%^CRST%^ and the sound of %^C059%^work%^CRST%^ inside");

   set_exits(([

          "north" : TOWN"3",
          "south" : TOWN"foyer",
   ]));

    set_door("wooden door",TOWN"foyer","south",0);
    set_door_description("wooden door","Thick wooden planks "+
    "are bound by solid bands of black iron. Both the hinges "+
    "and the handles are decorative, vines spiraling away and "+
    "ending in oak leaves, though its somewhat crudely worked. "+
    "Its said these are amongst the very first projects produced "+
    "by students here, and though there may be finer made fittings "+
    "they remain in honour of new beginnings..");
    set_string("wooden door", "open", "You push against the heavy door and it opens slowly.");
    set_string("wooden door", "close", "You close the heavy wooden door slowly.");

}



