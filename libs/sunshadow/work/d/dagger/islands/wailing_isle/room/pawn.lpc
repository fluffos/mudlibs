// Chernobog & Titania (2/14/22)
// The Wailing Isle - Pawn Shop/Fence

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
    set_name("The Pawn Shop");
    set_short("%^RESET%^%^CRST%^%^C243%^The Pawn Shop%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C243%^Stone steps lead down into the underbelly of the tavern, where the %^C059%^shadows%^C243%^ gather like hungry predators surrounding their kill. You can hear the distant sounds of a rowdy crowd overhead, but the %^C059%^darkness%^C243%^ seems to swallow even that for the most part. A few %^C246%^c%^C150%^a%^C149%^n%^C246%^dl%^C150%^e%^C246%^s%^RESET%^%^C243%^ burn here and there, providing a minimal light that only seems to enhance the %^C059%^murk%^C243%^. The %^C247%^wa%^C245%^rp%^C243%^ed %^C247%^st%^C245%^on%^C243%^e w%^C247%^al%^C245%^ls%^RESET%^%^C243%^ wrap around the room, cracked and dripping and sagging with age, and the floor is little more than %^C058%^packed dirt%^C243%^. The room is without any manner of ornamentation, short of an empty %^C245%^c%^C243%^ra%^C245%^ck%^C243%^e%^C245%^d gla%^C243%^s%^C245%^s di%^C243%^sp%^C245%^lay c%^C243%^a%^C245%^se%^RESET%^%^C243%^, and a %^C060%^hulking figure%^C243%^ looming in wait behind it, watching the room warily.%^CRST%^\n");
    set_smell("default","%^CRST%^%^RESET%^%^C065%^The damp scent of the sea weighs heavily here.%^CRST%^");
    set_listen("default","%^CRST%^%^RESET%^%^C060%^A few %^C061%^thumps%^C060%^ and %^C061%^bumps%^C060%^ manage to spill through from the bar above.%^CRST%^");
    set_items(([
        "candles" : "%^RESET%^%^CRST%^%^C246%^The %^C150%^candles%^C246%^ provide just enough light that you probably won't smack into any walls. The %^C243%^shadows%^C246%^ shift in their flicking flames.%^CRST%^",
        "case" : "%^RESET%^%^CRST%^%^C247%^The case doesn't really seem to serve any purpose beyond that of being an obstacle. No goods are on display. %^C245%^What sort of lame shop is this?%^CRST%^",
        "steps" : "%^RESET%^%^CRST%^%^C243%^You came down them, and you'll probably go up them. Be watchful of the crevices.%^CRST%^",
        ]));
    set_exits(([
        "stairs" : ROOMS"alley",
        ]));
}

void reset(){
    if(!present("cragur")) new(MON"cragur")->move(this_object());
}

