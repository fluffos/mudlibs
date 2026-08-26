// Chernobog (3/15/22)
// Road Inherit

#include <std.h>

inherit ROOM;

void create(){
    string fields;
    
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(DIRT_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_name("A roadway around the Yniam Plains");
    set_short("%^RESET%^%^CRST%^%^C156%^A %^C059%^r%^C244%^o%^C059%^a%^C244%^dw%^C059%^a%^C244%^y %^C156%^around the %^C144%^Yniam Plains%^CRST%^");
    switch(season(time())){
        case "spring" :
            fields = "%^C130%^T%^C136%^i%^C130%^l%^C136%^l%^C130%^e%^C136%^d %^C130%^f%^C136%^u%^C130%^r%^C136%^r%^C130%^o%^C136%^w%^C130%^s %^RESET%^%^C156%^interrupt the plains where farms are just beginning to prepare for the season, as %^C040%^g%^C034%^re%^C040%^e%^C046%^n%^C040%^e%^C034%^ry %^RESET%^%^C156%^springs forth in the surrounding area.";
            break;
        case "summer" : 
            fields = "%^C046%^Rich, %^C040%^v%^C046%^e%^C040%^r%^C034%^da%^C040%^n%^C046%^t %^C040%^g%^C046%^ree%^C040%^n%^C046%^s %^RESET%^%^C156%^of the farmers' fields form a patchwork here and there where farms have taken root, while the untamed growths are dotted with %^C104%^w%^C098%^i%^C092%^l%^C144%^d%^C150%^f%^C046%^l%^C040%^o%^C210%^w%^C204%^e%^C196%^r%^C202%^s %^RESET%^%^C156%^and low %^C065%^shrubberies%^C156%^.";
            break;
        case "autumn" :
            fields = "A patchwork of %^C137%^b%^C136%^r%^C137%^ow%^C136%^n%^C137%^s %^C156%^and %^C065%^fa%^C064%^de%^C065%^d gre%^C064%^en%^C065%^s %^C156%^paint the plains as farmers prepare for the harvests.";
            break;
        case "winter" :
            fields = "%^C252%^S%^C255%^n%^C087%^o%^C255%^w %^C252%^blankets %^C156%^the countryside, making most features indistinct and cloaking the usual vibrant colors of the low hills.";
            break;
    }
    set_long("%^RESET%^%^CRST%^%^C156%^The lands of the %^C144%^Yniam Plains %^C156%^spread out in all directions, the land gently sloping in shallow hills covered in grass and sparse brush. "+fields+"%^CRST%^\n");
    set_smell("default", "%^RESET%^%^CRST%^%^C144%^A breeze carries with it the smells of the %^C120%^pl%^C156%^a%^C120%^i%^C156%^n%^C120%^s%^C144%^.%^CRST%^");
    set_listen("default", "%^RESET%^%^CRST%^%^C030%^You can hear the rustling of the %^C045%^w%^C087%^in%^C045%^d%^C087%^s %^C030%^along the plains.%^CRST%^");
    set_items(([
        ]));
}

