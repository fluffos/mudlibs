#include <std.h>
#include "../graez.h"

inherit CROOM;
void pick_critters();

void create() {
    pick_critters();
    ::create();
    set_terrain(HEAVY_FOREST);
    set_travel(FOOT_PATH);
    set_property("indoors",0);
    set_name("dark forest");
    set_short("%^C022%^da%^C028%^r%^C022%^k fore%^C029%^s%^C022%^t%^CRST%^");
    set_long("The %^C065%^trees%^CRST%^ of the %^C022%^forest%^CRST%^ "+
        "%^C244%^loom%^CRST%^ close to you and seem to block out any "+
        "attempt to look at the %^C075%^sky%^CRST%^. The %^C022%^trees%^CRST%^ "+
        "themselves are mature and healthy, and you see places where "+
        "the %^C060%^city%^CRST%^ has tried to run small incursions to "+
        "do %^C058%^logging%^CRST%^ with some success, though discarded "+
        "%^C246%^axes%^CRST%^ and %^C244%^saws%^CRST%^ %^C088%^rusting%^CRST%^ "+
        "on the ground in places proves they are not always successful. "+
        "The %^C058%^ground%^CRST%^ is softer here than the compacted "+
        "%^C060%^battlefield%^CRST%^.\n");

    set_items(([
        ({"trees"}) : "The %^C028%^trees %^CRST%^here are large and %^C060%^tower over you.%^CRST%^creating a fair amount of shade on the %^C095%^ground%^CRST%^.",
        ({"ground"}) : "The %^C095%^ground%^CRST%^ here is %^C094%^softer soil%^CRST%^ that has not been compacted as much as the %^C060%^battleground %^CRST%^around it.",
    ]));

    set_smell("default","%^CRST%^You smell %^C094%^soil "+
        "%^CRST%^and %^C028%^trees %^CRST%^around you.");
    set_listen("default","%^CRST%^You hear %^C094%^howls%^CRST%^ in the distance.");

}


void pick_critters(){
   switch(random(6)){
         case 0:   set_monsters(
({MOBS"deserter",MOBS"wolf"}),({random(4),random(8)}) );
                   break;
         case 1:   set_monsters(
({MOBS"deserter"}),({random(5)}) );
                   break;
         case 2:   set_monsters(
({MOBS"deserter",MOBS"wolf"}),({1,random(6)+2}) );
                   break;
         case 3:   set_monsters(
({MOBS"deserter"}),({random(5)}) );
                   break;
         case 4..5: break;
   }
}