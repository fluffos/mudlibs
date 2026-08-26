// Chernobog (6/30/22)
// Temple of Edea - Written by Victoire

#include <std.h>

inherit "/std/temple";

void create(){
    ::create();
    set_temple("edea");
    set_property("indoors", 0); 
    set_property("light", 2);
    set_terrain(GARDEN);
    set_travel(PAVED_ROAD);
    set_name("Temple of the Celestial Light"); 
    set_short("%^BOLD%^%^WHITE%^Temple of the %^YELLOW%^Celestial Light%^RESET%^");
    set_long("%^RESET%^%^CRST%^%^C220%^This %^C226%^g%^C228%^o%^C231%^ld-e%^C228%^l%^C226%^f%^C220%^ styled %^C227%^t%^C228%^e%^C229%^mp%^C228%^l%^C227%^e%^C220%^ stands as an %^C160%^im%^C196%^p%^C160%^os%^C196%^s%^C160%^ib%^C196%^i%^C160%^lit%^C196%^y%^C220%^ in contrast to the %^C166%^oppressive%^RESET%^%^C220%^ %^C160%^heat%^C220%^ that lies inherent to the %^C160%^scorching%^C220%^ %^C226%^sun%^C220%^ of the Shadow Desert. %^C040%^G%^C028%^r%^C040%^o%^C034%^w%^C028%^i%^C034%^n%^C040%^g%^C220%^ from the tip of the %^C226%^sp%^C231%^i%^C228%^r%^C231%^e%^C220%^, all the way down around the %^C231%^sun-bleached%^C220%^ stone, trails %^C034%^l%^C046%^u%^C034%^sh%^C220%^ and %^C034%^gr%^C046%^e%^C034%^en g%^C046%^r%^C034%^o%^C040%^w%^C034%^th%^C220%^ with hundreds of %^RESET%^%^C161%^brimming%^C220%^ and %^C211%^blooming%^C220%^ %^C040%^f%^C162%^l%^C226%^o%^C196%^w%^C033%^e%^C217%^r%^C040%^s%^C220%^ delving forth all over from the %^C034%^gr%^C046%^o%^C040%^w%^C034%^th%^C220%^ on the outside surface of the structure, reaching all into the way across in lush greens over the dry sand. When the %^C242%^night%^C220%^ falls, instead a cascade of %^RESET%^%^C231%^moonflowers%^C220%^ appear to %^C231%^b%^C230%^l%^C229%^o%^C230%^o%^C231%^m%^C220%^, offering light even within the %^C243%^darkness%^C220%^. The spire itself stands and surrounds an %^C039%^o%^C045%^a%^C039%^s%^C045%^i%^C039%^s%^C220%^ from which all of the %^RESET%^%^C034%^gr%^C040%^o%^C046%^w%^C034%^th%^C220%^ climbs and springs from, reaching over across of the walls within to the outside. An %^RESET%^%^C229%^altar%^C220%^ sits at the middle, the very center of the %^C039%^o%^C045%^a%^C039%^s%^C045%^i%^C039%^s%^C220%^ and a %^RESET%^%^C231%^ra%^C228%^d%^C226%^i%^C220%^ant l%^C226%^i%^C228%^g%^C231%^ht%^C220%^ shines %^C231%^brightly%^C220%^ from above the %^C228%^altar%^C220%^. Overgrown %^C231%^statues of angels%^RESET%^%^C220%^, delicately adorned with precious pearls and %^C231%^d%^C159%^i%^C087%^a%^C051%^mo%^C087%^n%^C159%^d%^C231%^s%^C220%^ to reflect the divine light, rise from all around from the inner walls, hands held out holding a magical %^C231%^light%^C220%^ within their palms.%^CRST%^\n");
    set_smell("default","%^RESET%^%^CRST%^%^C203%^The heavy scent of blooming flowers hangs in the air.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C231%^The distant song of angels radiates at the back of the mind.%^CRST%^");
    set_items(([
        ({"ball", "light"}) : "%^RESET%^%^CRST%^%^C220%^The large light from above the altar radiates brightly all around and even beyond, and reaches up to the cascade of diamonds that the statues hold, creating small little beams of rainbows all across.%^CRST%^",
        "growth" : "%^RESET%^%^CRST%^%^C034%^The %^C046%^growth%^C034%^ all seems to flow out from the oasis and crawl along upwards on the interior of the spire. They reach up and slither through some openings in the walls, windows, and then more properly above, from which they trail along on the walls on the outside. Flowers grow along the vines and walls all across in all kinds of different hues and %^C196%^co%^C226%^lo%^C165%^u%^C045%^rs%^C034%^.%^CRST%^",
        "water" : "%^RESET%^%^CRST%^%^C039%^The oases is nestled around of the altar and blow of the brimming light, crystal clear and completely see-through, allowing sight on all of the little flowers%^CRST%^",
        ]));
    set_exits(([
        "northwest" : "/d/magic/temples/edea/temple_nw",
        "northeast" : "/d/magic/temples/edea/temple_ne",
        "southwest" : "/d/magic/temples/edea/temple_sw",
        "southeast" : "/d/magic/temples/edea/temple_se",
        ]));
}

void init(){
    ::init();
    add_action("read_charge", "read");
}

int read_charge(string str){
    if(!str || str != "charge") return __Read_me(str);
    write("%^BOLD%^%^WHITE%^The light of Edea grows and soon shall purge this world of all darkness. Her essence is within us all as we are all born of Her. Only those who embrace this truth can rise above their fear to become one of Her true children. Heed Her gentle whispers for all She asks is that you embrace your inner light and become a manifestation of holy power. Darkness cannot drive out darkness, only light can do that. Hate cannot drive out hate, only love can do that. Seek always to aid others so that they will be inspired to do the same; thus the kindness of Edea grows. Stand fast against the creeping corruption, for you are the flame and you shall know no fear.%^RESET%^");
    return 1;
}

