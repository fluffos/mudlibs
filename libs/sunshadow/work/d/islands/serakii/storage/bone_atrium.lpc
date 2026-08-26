
//Tower of Bone Atrium

#include <std.h>
#include "../serakii.h"

inherit CVAULT ;

int has_a_clue, items;
object ob;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",3);
    set_property("no teleport",1);
    set_name("atrium in a tower of bone");
    set_short("atrium in a tower of bone");
    set_long("You stand in a large room in the tower of %^C189%^bone%^CRST%^. The walls around you are formed of %^C189%^bone%^CRST%^, completely smooth and %^C195%^bleached white%^CRST%^. The floor is set in interlocking tiles of different %^C245%^shades of stone%^CRST%^ forming beautiful yet random patterns. The ceiling is high above you and the whole room is lit with a series of %^C206%^delicate lanterns%^CRST%^ that hang on the walls, basking the room in %^C204%^pale pink light%^CRST%^. The whole room is packed with pots of %^C022%^plants%^CRST%^ in a variety of %^C094%^pot %^CRST%^sizes. The area smells faintly of %^C126%^lilacs %^CRST%^and from around every corner you hear %^C062%^children giggling%^CRST%^. Overall the whole area seems extremely well cared for.\n");
	has_a_clue = 0;
    set_items(([
        ({"wall","walls"}) : "The walls of the tower are pure %^C193%^bleached bone%^CRST%^. It is not a collection of %^C193%^bones %^CRST%^either, it is as if the whole tower is a single %^C193%^bone %^CRST%^that has been carved and polished.",
        ({"floor","tiles"}) : "The floor is tiled with different %^C245%^shades of stone%^CRST%^, forming a chaotic yet fascinating pattern. It has been placed with care and obvious craftsmanship.",
        ({"lights","lanterns"}) : "Delicate lanterns made of %^C231%^silver %^CRST%^and %^C086%^glass %^CRST%^hang from the walls and cast a %^C206%^magical pink light%^CRST%^ across the room.",
        ({"plants","pots"}) : "The whole room is packed with pots of %^C034%^plants %^CRST%^in a variety of pot sizes. They range from %^C041%^small flowers%^CRST%^, to %^C058%^giant pots %^CRST%^with %^C028%^ferns %^CRST%^from %^C202%^exotic locales%^CRST%^. Obviously a collector of some love has curated this collection and kept them alive.",
    ]));

    set_smell("default","%^C129%^You smell sweet lilac.%^CRST%^");
    set_listen("default","%^C075%^You hear giggling.%^CRST%^");

}

