// Chernobog & Titania (2/7/22)
// The Wailing Isle - Beach Inherit

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(BEACH);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("a beach along the bay");
    set_short("%^RESET%^%^CRST%^%^C172%^a b%^C100%^e%^C172%^a%^C100%^c%^C172%^h along the %^C116%^bay%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C186%^Soft sand surrounds you as %^C250%^seagulls%^C186%^ circle overhead. The %^C039%^w%^C045%^a%^C051%^t%^C045%^e%^C039%^r%^C045%^s%^RESET%^%^C186%^ are calm here, lapping %^C229%^gently%^C186%^ against the shore with a %^C229%^hypnotic%^C186%^ rhythm. Looking beyond the %^C179%^breakers%^C186%^, the %^%^C033%^v%^C038%^a%^C043%^s%^C042%^t %^C043%^s%^C038%^e%^C033%^a%^RESET%^%^C186%^ spreads wide against the horizon with her promises of %^C184%^fortune%^C186%^ and %^C184%^freedom%^C186%^. %^C186%^To the northwest, craggy %^C253%^cliffs%^C186%^ loom over the bones of a once lively port town, a %^C193%^haunting backdrop%^C186%^ to the %^C246%^re%^C244%^so%^C246%^un%^C248%^di%^C246%^ng %^C244%^wa%^C246%^il%^C248%^s%^RESET%^%^C186%^ that echo over the isle. Across the bay to the south, a %^C040%^t%^C041%^h%^C042%^r%^C043%^i%^C042%^v%^C041%^i%^C040%^n%^C041%^g %^C042%^f%^C043%^o%^C042%^r%^C041%^e%^C040%^s%^C041%^t%^RESET%^%^C186%^ sits in the lee of the %^C253%^cliffs%^C186%^, full of %^C210%^c%^C203%^o%^C196%^l%^C197%^o%^C204%^r%^RESET%^%^C186%^ and %^C043%^li%^C042%^f%^C043%^e%^RESET%^%^C186%^.%^CRST%^\n");
    set_smell("default","%^RESET%^%^CRST%^%^C116%^The %^C123%^scents%^C116%^ of the %^C045%^vast sea%^C116%^ leave a %^C123%^salty tinge%^C116%^ in your nose.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C044%^Th%^C080%^e s%^C050%^ou%^C044%^nd %^C080%^of %^C050%^ge%^C080%^nt%^C044%^ly %^C050%^la%^C080%^pp%^C044%^in%^C050%^g %^C080%^wa%^C044%^ve%^C050%^s%^RESET%^%^C044%^ is %^C050%^me%^C080%^sm%^C044%^er%^C050%^iz%^C044%^i%^C080%^ng%^RESET%^%^C040%^.%^CRST%^");
    set_items(([
        "sand" : "%^RESET%^%^CRST%^%^C230%^The %^C255%^white sands%^C230%^ swallow your feet into its pillowy soft depths. Because the %^C069%^bay%^C230%^ is largely enclosed, few shells or other sea debris make it onto the shore here, allowing one to enjoy their experience without any unfortunate foot impalements.%^CRST%^",
        ({"seagulls", "gulls"}) : "%^RESET%^%^CRST%^%^C255%^The white birds circle overhead, occasionally diving down to spear a %^C078%^fish%^C255%^ in their long beaks.%^CRST%^",
        "sea" : "%^RESET%^%^CRST%^%^C044%^Light ripples over the surface of the %^C038%^azure water%^C044%^ like diamonds, %^C051%^luring%^C044%^ you into its bountiful depths. The %^C250%^breeze%^C044%^ is constant, bringing with it the scents of the sea, and it whispers the %^C051%^promises%^C044%^ of adventures abound and treasures not yet plundered. The vastness of the sea is humbling to some... and something to be conquered by others.%^CRST%^",
        "breakers" : "%^RESET%^%^CRST%^%^C101%^The tip of the island curves into the bay, blocking the worst of the sea's waves. An old %^C102%^lookout tower%^C101%^ stands sentinel on a rocky outcropping at the edge of the %^C069%^bay%^C101%^.%^CRST%^",
        ({"lookout", "tower", "lookout tower"}) : "%^RESET%^%^CRST%^%^C102%^It seems to be just a small building built of stone. It is unremarkable aside from the fact that it manages to still stand while looking so ramshackle.%^CRST%^",
        "cliffs" : "%^RESET%^%^CRST%^%^C255%^White cliffs rise up behind the %^C250%^small village%^C255%^, their craggy, steep surface making climbing a very dangerous prospect. The cliffs are riddled with %^C244%^hidden caves%^C255%^ and %^C244%^caverns%^C255%^, so that when the %^C250%^wind%^C255%^ whips through them they let out a %^C059%^mournful cry%^C255%^ that can be heard across the entire island... hence the island's namesake.%^CRST%^",
        ({"buildings", "village", "road"}) : "%^RESET%^%^CRST%^%^C139%^A narrow %^C243%^cobblestone road%^C139%^ winds its way through the village and up along the steep foothills of the cliffs. The %^C144%^buildings%^C139%^ seem to have fallen into disrepair over time, although one can see signs of the %^C125%^co%^C124%^lo%^C196%^rf%^C197%^ul %^C198%^gr%^C199%^an%^C200%^de%^C201%^ur%^RESET%^%^C139%^ they once possessed. The %^C140%^market square%^C139%^ and its shops are along the first tier of the cliff side, while the higher tier seem to be the %^C144%^crumbling residences%^C139%^ of the permanent citizens of the island.%^CRST%^",
        "forest" : "%^RESET%^%^CRST%^%^C040%^The lush beauty of this %^C046%^forest%^C040%^ stands in contrast to the stark bleakness of the %^C250%^cliffs%^C040%^ and its crumbling %^C243%^village%^C040%^. Even from this distance you can see %^C047%^verdant fauna%^C040%^ and %^C160%^fr%^C088%^ui%^C094%^t b%^C100%^ea%^C172%^ri%^C166%^ng %^C160%^tr%^C088%^e%^C089%^es%^RESET%^%^C040%^. The forest is very much alive and thriving, and so overgrown as to be almost impassable except to someone who knows its secrets well.%^CRST%^",
        ]));
}

void reset(){
    if(!present("ambiance device")) new(MON"ambiance_beach")->move(this_object());
}

