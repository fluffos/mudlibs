// Chernobog & Titania (3/7/22)
// The Wailing Isle - Residential Inherit

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(BEACH);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_property("no sticks", 1);
    set_name("a residential street");
    set_short("%^RESET%^%^CRST%^%^C138%^a residential street%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C138%^Residents of the Wailing Isle live along this street in %^C221%^c%^C215%^o%^C209%^l%^C203%^o%^C209%^r%^C215%^f%^C221%^u%^C227%^l%^RESET%^%^C138%^ multilevel homes that are now %^C137%^faded%^C138%^ from too many years of the elements bearing down on them. The paint is %^C139%^p%^C140%^e%^C139%^eli%^C140%^n%^C139%^g%^RESET%^%^C138%^ from the stucco walls, revealing the %^C245%^f%^C245%^i%^C243%^s%^C244%^su%^C244%^r%^C243%^e%^C245%^s%^RESET%^%^C138%^ and %^C245%^b%^C243%^o%^C245%^n%^C243%^e%^C245%^s%^RESET%^%^C138%^ beneath. The houses are built flush against the %^C250%^cliff wall%^C138%^ that rises up sharply behind them, capturing them in its %^C243%^s%^C245%^h%^C243%^ad%^C245%^o%^C243%^w%^RESET%^%^C138%^. The steep %^C059%^c%^C243%^o%^C245%^b%^C246%^b%^C059%^l%^C243%^e%^C245%^s%^C246%^t%^C059%^o%^C243%^n%^C245%^e %^C246%^s%^C059%^t%^C243%^r%^C245%^e%^C246%^e%^C059%^t%^RESET%^%^C138%^ treads its way ever upward, passing by some %^C077%^h%^C071%^a%^C065%^r%^C071%^d%^C077%^y %^C071%^t%^C065%^r%^C071%^e%^C077%^e%^C071%^s%^RESET%^%^C138%^ that have managed to flourish on this %^C245%^r%^C243%^o%^C245%^c%^C243%^k%^C245%^y t%^C243%^e%^C245%^rr%^C243%^ai%^C245%^n%^C138%^. A small %^C245%^s%^C243%^t%^C245%^o%^C243%^n%^C245%^e w%^C243%^al%^C245%^l%^RESET%^%^C138%^ is all that prevents you from the long drop down to the lower tiers of the city, but the view of the %^C039%^e%^C033%^n%^C032%^d%^C031%^l%^C030%^e%^C036%^s%^C037%^s %^C038%^s%^C039%^e%^C033%^a%^RESET%^%^C138%^ from here is breathtaking.%^CRST%^\n");
    set_smell("default","%^RESET%^%^CRST%^%^C123%^The breeze brings the %^C195%^s%^C194%^a%^C195%^lty t%^C194%^a%^C195%^ng%^RESET%^%^C123%^ of the sea all the way up here.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C109%^Distant %^C110%^waves%^C109%^ are almost drowned out by the %^C115%^w%^C110%^a%^C115%^ili%^C110%^n%^C115%^g%^RESET%^%^C109%^ of the %^C115%^w%^C110%^i%^C115%^nd%^C109%^ further up the cliffside.%^CRST%^");
    set_items(([
        ({"homes", "houses"}) : "%^CRST%^%^RESET%^%^C223%^These %^C221%^st%^C215%^uc%^C209%^co %^C203%^ho%^C209%^us%^C215%^es%^RESET%^%^C223%^ once stood as a point of pride to the island. Like everything else, they have fallen into a sad state of disrepair. Many appear to be abandoned, with %^C101%^boarded up%^C223%^ windows and doors. What were once colorful facades are now faded and peeling, and certainly in need of some care. A few of the houses have made an attempt at sprucing up the formerly grand architecture with %^C201%^f%^C200%^l%^C199%^o%^C198%^w%^C197%^e%^C196%^r%^C124%^s%^RESET%^%^C223%^ growing from %^C101%^window boxes%^C223%^, or small %^C165%^co%^C175%^lo%^C185%^rf%^C154%^ul %^C215%^mo%^C205%^sa%^C201%^ics%^RESET%^%^C223%^ lining their paths.%^CRST%^",
        ({"cobblestone road", "road", "path", "street"}) : "%^CRST%^%^RESET%^%^C247%^The road is mostly smooth from years of travel. The %^C076%^m%^C070%^o%^C064%^s%^C058%^s-d%^C064%^a%^C070%^p%^C076%^p%^C070%^l%^C064%^e%^C058%^d%^RESET%^ %^C059%^co%^C243%^bb%^C245%^le%^C243%^st%^C059%^on%^C243%^es%^RESET%^%^C247%^ are various shades of %^C244%^gray%^C247%^ with %^C059%^darker stones%^C247%^ lining the borders.%^CRST%^",
        ({"wall", "stone wall"}) : "%^CRST%^%^RESET%^%^C244%^This low crumbling wall is all that stands between you and a thirty foot drop off into the market below. Some %^C034%^ivy%^C244%^ creeps through its crevices.%^CRST%^",
        "sea" : "%^CRST%^%^RESET%^%^C027%^The sea extends as far as the eye can see, reflecting the %^C033%^sky%^C027%^ upon its %^C032%^tu%^C037%^rq%^C042%^uo%^C036%^is%^C031%^e s%^C026%^ur%^C027%^fa%^C033%^ce%^RESET%^%^C027%^.%^CRST%^",
        ({"cliffs", "cliff", "cliff wall"}) : "%^RESET%^%^CRST%^%^C255%^White cliffs rise up behind the %^C250%^small village%^C255%^, their craggy, steep surface making climbing a very dangerous prospect. The cliffs are riddled with %^C244%^hidden caves%^C255%^ and %^C244%^caverns%^C255%^, so that when the %^C250%^wind%^C255%^ whips through them they let out a %^C059%^mournful cry%^C255%^ that can be heard across the entire island... hence the island's namesake.%^CRST%^",
        "mosaics" : "%^RESET%^%^CRST%^%^C103%^A few of the houses have small walkways that are covered in these %^C110%^de%^C117%^li%^C051%^gh%^C086%^tf%^C079%^ul%^C074%^ly %^C069%^co%^C135%^lo%^C128%^re%^C133%^d s%^C138%^to%^C143%^ne%^C148%^s%^RESET%^%^C103%^ and %^C148%^g%^C226%^l%^C191%^a%^C186%^s%^C181%^s%^RESET%^%^C103%^. Once lovingly placed to form cheerful images of the %^C191%^sun%^C103%^ and %^C069%^sea%^C103%^, they have been left to the mercy of the elements, mostly chipped and trodden with %^C101%^dirt%^C103%^ and %^C101%^sand%^RESET%^%^C103%^.%^CRST%^",
        ({"flowers", "window boxes"}) : "%^RESET%^%^CRST%^%^C146%^Little bursts of %^C127%^c%^C126%^o%^C125%^l%^C124%^o%^C196%^r%^RESET%^%^C146%^ and %^C040%^l%^C046%^i%^C082%^f%^C076%^e%^RESET%^%^C146%^ poke up from small %^C101%^wooden window boxes%^C146%^, while a few %^C125%^pots%^C146%^ tucked along porches or in small %^C070%^ga%^C076%^rde%^C070%^ns%^RESET%^%^C146%^ lining the path add a touch of %^C141%^whimsy%^C146%^ to the rows of derelict homes.%^CRST%^",
        "trees" : "%^RESET%^%^RESET%^%^C065%^Despite the %^C059%^harshness%^C065%^ of the %^C243%^r%^C245%^o%^C243%^ck%^C245%^y t%^C243%^err%^C245%^ai%^C243%^n%^RESET%^%^C065%^ and the tinge of %^C195%^salt%^C065%^ in the air, these %^C064%^trees%^C065%^ manage to, while not exactly thrive, survive. A small testament to the %^C060%^resilience%^RESET%^%^C065%^ of the isle and its people.%^CRST%^",
        ]));
}

void reset(){
    if(!present("ambiance device")) new(MON"ambiance_residential")->move(this_object());
}

