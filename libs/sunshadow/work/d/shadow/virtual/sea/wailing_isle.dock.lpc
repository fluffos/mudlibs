// Chernobog & Titanis (4/30/22)
// The Wailing Isle Dock

#include <std.h>
#include <objects.h>

inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create(){
    ::create();
    set_terrain(BEACH);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_property("no sticks", 1);
    set_property("no teleport",1);
    set_name("a wharf extending into the bay");
    set_short("%^RESET%^%^CRST%^%^C100%^a %^C101%^wharf%^C100%^ extending into the %^C033%^b%^C039%^a%^C045%^y%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^RESET%^%^CRST%^%^C101%^The slapping of %^C033%^water%^C101%^ against the old %^C100%^wooden wharf%^C101%^ is nearly drowned out by the bustle of activity that consumes the area, night and day. %^C250%^G%^C247%^u%^C250%^lls%^RESET%^%^C101%^ cry overhead, competing against the shouts of %^C107%^men%^RESET%^%^C101%^ moving goods, the mewls of %^C095%^whores%^C101%^ looking to line their pockets with a lonely sailor's fortune, and the growls of %^C102%^mongrels%^C101%^ as they fight over pillaged fish. %^C100%^Crates%^C101%^ and %^C100%^barrels%^C101%^ are piled along the %^C101%^warped planks%^C101%^, so that just keeping your footing along the wet and narrow pathways proves to be an arduous task. Small %^RESET%^%^C245%^longboats%^C101%^ are tethered haphazardly to %^C100%^wooden posts%^C101%^, waiting to return to the %^RESET%^%^C059%^great ships%^C101%^ anchored in the %^C033%^d%^C039%^e%^C045%^e%^C051%^p%^C045%^e%^C039%^r %^C033%^w%^C039%^a%^C045%^t%^C051%^e%^C045%^r%^C039%^s%^RESET%^%^C101%^ of the bay.\n%^CRST%^");
    set_smell("default","%^RESET%^%^CRST%^%^C106%^It smells of %^C113%^r%^C107%^o%^C113%^tt%^C107%^e%^C113%^n fi%^C107%^s%^C113%^h%^C106%^ and %^C108%^s%^C109%^e%^RESET%^%^C108%^a w%^C109%^a%^C108%^t%^C109%^e%^C108%^r.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C096%^Your ears are assaulted by dozens of different sounds, all vying to be heard.%^CRST%^");
    set_items(([
        ({"docks", "dock", "wharf"}) : "%^RESET%^%^CRST%^%^C101%^The dock seems sturdy enough, even as it sways in time with the lapping of the %^C051%^w%^C045%^a%^C039%^v%^C033%^e%^C027%^s%^RESET%^%^C101%^ beneath. It is old, that is for certain, but it seems like it might still have a couple years left before the sea claims it.%^CRST%^",
        ({"crates", "barrels"}) : "%^RESET%^%^CRST%^%^C101%^The cargo doesn't stay in place for long, constantly being shifted out and taken to town or loaded into the %^C102%^longboats%^C101%^ to return to the ships anchored in the %^C045%^bay%^C101%^.%^CRST%^",
        ({"men", "whores"}) :  "%^RESET%^%^CRST%^%^C103%^Sailors and dock hands move along the pier, transferring %^C101%^cargo%^C103%^ or preparing to return to their %^C102%^longboats%^C103%^. At several spots along the wharf, %^C097%^whores%^C103%^ have staked out territory from which to distract and entice customers.%^CRST%^",
        "gulls" : "%^RESET%^%^CRST%^%^C251%^The %^C255%^white birds%^C251%^ circle overhead, squawking and adding to the cacophony below. Occasionally, they will dart down to snatch a %^C080%^fish%^C251%^ or other tidbit from the dock to the dismay of the sailors who quickly wave them off.%^CRST%^",
        "mongrels" : "%^RESET%^%^CRST%^%^C102%^Stray dogs of indeterminate breed roam along the pier, quick to catch a dropped %^C080%^fish%^C102%^ or a %^C252%^lazy gull%^C102%^. Fights are quick to break out between them, and just as quickly ended with a %^C138%^whimper%^C102%^.%^CRST%^",
        ({"longboats", "boats"}) : "%^RESET%^%^CRST%^%^C101%^These boats bob in the water, tethered to the wooden posts of the wharf.%^CRST%^",
        "ships" : "%^RESET%^%^CRST%^%^C178%^The ships float %^C090%^majestically%^C178%^ on the bay, awaiting their next %^C172%^adventure%^C178%^. They feature %^C250%^great sails%^C178%^, meant for the deep seas. Absent from their masts are the colors of any of the city states of the realm, and a few even sport %^C059%^black flags%^C178%^ with malicious icons.%^CRST%^",
        ]));
    set_exits(([
        "south" : "/d/dagger/islands/wailing_isle/room/wharf3",
        ]));
}

void reset(){
    if(!present("ambiance device")) new("/d/dagger/islands/wailing_isle/mon/ambiance_wharf")->move(this_object());
}