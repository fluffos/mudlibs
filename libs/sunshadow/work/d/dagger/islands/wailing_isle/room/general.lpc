// Chernobog & Titania (2/2/22)
// The Wailing Isle - General Store

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no sticks", 1);
    set_name("The General Store");
    set_short("%^RESET%^%^CRST%^%^C136%^The General Store%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C136%^Old %^C196%^c%^C124%^e%^C130%^r%^C202%^a%^C196%^m%^C124%^i%^C130%^c %^C202%^t%^C196%^i%^C124%^l%^C130%^e%^C196%^s%^RESET%^%^C136%^ crumble beneath your feet, trodden %^C102%^d%^C101%^o%^C100%^w%^C102%^n%^C136%^ and %^C102%^d%^C101%^i%^C100%^r%^C101%^t%^C102%^y%^RESET%^%^C136%^ from years of use and a %^C102%^g%^C100%^r%^C112%^i%^C102%^ev%^C100%^o%^C101%^u%^C102%^s%^RESET%^%^C136%^ lack of cleaning. %^C245%^Dusty shelves%^C136%^ line the walls, overflowing with mostly useless goods. Basic daily necessities are displayed in squat shelving that leads the way to the old glass counter where a %^C138%^clerk%^C136%^ watches you with an accusatory scowl. The %^C196%^fl%^C124%^ic%^C125%^ke%^C202%^ri%^C208%^ng %^C196%^fl%^C124%^am%^C125%^es%^RESET%^%^C136%^ from a few %^C102%^oil lamps%^C136%^ hung between the shelves barely manage to breach the %^C059%^s%^C243%^h%^C244%^a%^C059%^do%^C243%^w%^C059%^y c%^C243%^o%^C244%^r%^C059%^ne%^C243%^r%^C059%^s%^RESET%^%^C136%^ of the shop.\n%^CRST%^");
    set_smell("default","%^RESET%^%^CRST%^%^C150%^It smells like something %^C102%^died%^C150%^ somewhere in here.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C152%^The %^C151%^di%^C145%^so%^C139%^rd%^C151%^er%^C145%^ly %^C139%^so%^C151%^un%^C145%^ds%^RESET%^%^C152%^ of the %^C102%^street%^C152%^ spill into the shop.%^CRST%^");
    set_items(([
        "floor" : "%^RESET%^%^CRST%^%^C196%^Pa%^C124%^tt%^C130%^er%^C202%^ne%^C196%^d t%^C124%^il%^C130%^es%^RESET%^%^C247%^, %^C196%^red%^C247%^ with a %^C255%^white flower%^C247%^ motif, are crumbled into disrepair, held together by the sheer amount of %^C058%^dirt%^C247%^ and %^C058%^grime%^C247%^ covering the floor.%^CRST%^",
        "tall shelves" : "%^RESET%^%^CRST%^%^C243%^These shelves have a lot of junk that has probably sat here, disregarded, for years. Layers of %^C250%^dust%^C243%^ and %^C250%^cobwebs%^C243%^ cover the goods.%^CRST%^",
        "squat shelves" : "%^RESET%^%^CRST%^%^C101%^These shelves look fairly well maintained and hold supplies people living on the island might need as they go about their business.%^CRST%^",
        "counter" : "%^RESET%^%^CRST%^%^C152%^The counter seconds as a %^C151%^display case%^C152%^ where the rare pricier items can be found, if one manages to look beyond the smudges.%^CRST%^",
        ({ "lamps", "lanterns" }) : "%^RESET%^%^CRST%^%^C157%^Primitive in nature, these %^C101%^lanterns%^C157%^ serve their purpose of providing %^C155%^light%^C157%^ to a space. %^C243%^Barely.%^CRST%^",
        "shelves" : "%^RESET%^%^CRST%^%^C101%^There are a couple rows of squat shelves in the middle of the room, while tall shelves line the back wall.%^CRST%^",
        ]));
    set_exits(([
        "east" : ROOMS"market3",
        ]));
}

void reset(){
    if(!present("shopkeeper")) new(MON"mae")->move(this_object());
}

