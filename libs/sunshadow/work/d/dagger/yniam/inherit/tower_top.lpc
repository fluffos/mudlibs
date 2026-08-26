// Chernobog (3/15/22)
// Watch Tower Top Inherit

#include <std.h>

inherit ROOM;

void create(){
    string fields;
    
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(DIRT_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_name("A lookout station on the Yniam Plains");
    set_short("%^RESET%^%^CRST%^%^C058%^A lookout station on the %^C144%^Yniam Plains%^CRST%^");
    switch(season(time())){
        case "spring" :
            fields = "%^C130%^T%^C136%^i%^C130%^l%^C136%^l%^C130%^e%^C136%^d %^C130%^f%^C136%^u%^C130%^r%^C136%^r%^C130%^o%^C136%^w%^C130%^s %^RESET%^%^C058%^interrupt the plains where farms are just beginning to prepare for the season, as %^C040%^g%^C034%^re%^C040%^e%^C046%^n%^C040%^e%^C034%^ry %^RESET%^%^C058%^springs forth in the surrounding area.";
            break;
        case "summer" : 
            fields = "%^C046%^Rich, %^C040%^v%^C046%^e%^C040%^r%^C034%^da%^C040%^n%^C046%^t %^C040%^g%^C046%^ree%^C040%^n%^C046%^s %^RESET%^%^C058%^of the farmers' fields form a patchwork here and there where farms have taken root, while the untamed growths are dotted with %^C104%^w%^C098%^i%^C092%^l%^C144%^d%^C150%^f%^C046%^l%^C040%^o%^C210%^w%^C204%^e%^C196%^r%^C202%^s %^RESET%^%^C058%^and low %^C065%^shrubberies%^C058%^.";
            break;
        case "autumn" :
            fields = "A patchwork of %^C137%^browns %^C058%^and %^C065%^faded greens %^C058%^paint the plains below as farmers prepare for the harvests.";
            break;
        case "winter" :
            fields = "%^C252%^S%^C255%^n%^C087%^o%^C255%^w %^C252%^blankets %^C058%^the countryside, making most features indistinct and cloaking the usual vibrant colors of the low hills.";
            break;
    }
    set_long("%^RESET%^%^CRST%^%^C058%^At the top of a watchtower, the lands of the %^C144%^Yniam Plains %^C058%^spread out below. "+fields+" %^RESET%^%^C058%^A low wooden railing is the only caution afforded up here on the platform, and a %^C136%^pole %^C058%^rises up from the corner to display the %^C040%^l%^C046%^iv%^C040%^e%^C046%^r%^C040%^y %^C058%^of %^C144%^Yniam%^C058%^.%^CRST%^\n");
    set_smell("default", "%^RESET%^%^CRST%^%^C144%^A breeze carries with it the smells of the %^C120%^pl%^C156%^a%^C120%^i%^C156%^n%^C120%^s %^C144%^below.%^CRST%^");
    set_listen("default", "%^RESET%^%^CRST%^%^C030%^You can hear the rustling of the %^C045%^w%^C087%^in%^C045%^d%^C087%^s %^C030%^along the plains.%^CRST%^");
    set_items(([
        ({"pole", "livery"}) : "%^RESET%^%^CRST%^%^C058%^The insignia of Yniam flaps in the breeze, that of an %^C040%^e%^C046%^me%^C040%^r%^C046%^a%^C040%^l%^C046%^d c%^C040%^i%^C046%^rcl%^C040%^e %^C058%^containing a white stylized silhouette of gathered %^C144%^stalks of wheat %^C058%^alongside a %^C136%^pair of barrels%^C058%^.%^CRST%^",
        "railing" : "%^RESET%^%^CRST%^%^C058%^This is a simple wooden rail that runs the periphery of the platform. A %^C214%^c%^C220%^urle%^C214%^d h%^C220%^or%^C214%^n %^C058%^hangs from a peg, available for the guards to alert the nearby %^C120%^pl%^C156%^a%^C120%^i%^C156%^n%^C120%^s%^C058%^.%^CRST%^",
        ]));
}

