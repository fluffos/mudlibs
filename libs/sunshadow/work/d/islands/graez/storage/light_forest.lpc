#include <std.h>
#include "../graez.h"

inherit CORE;

void create() {
    ::create();

    set_terrain(HEAVY_FOREST);
    set_travel(FOOT_PATH);
    set_property("indoors",0);

    set_name("light forest");
    set_short("%^C028%^light forest%^CRST%^");
    set_long("You have entered a %^C028%^light forest.%^CRST%^ "+
	"The %^C040%^trees %^CRST%^here are %^C060%^gnarled %^CRST%^and "+
	"dwarfed though as if they are constantly trying to fight "+
	"for %^C255%^life%^CRST%^. You can even hear %^C095%^small "+
	"animals%^CRST%^ in the %^C028%^trees%^CRST%^. The ground "+
	"is less compact here, and movement is harder through the "+
	"trees. Off to the north you see a %^C243%^mountain range%^CRST%^.\n");


    set_items(([
        ({"trees"}) : "The %^C028%^trees %^CRST%^here are dwarf and %^C060%^gnarled %^CRST%^close to the %^C095%^ground%^CRST%^, as if any attempt to grow is much harder than it would be anywhere else.",
        ({"ground"}) : "The %^C095%^ground%^CRST%^ here is %^C094%^softer soil%^CRST%^ that has not been compacted as much as the %^C060%^battleground %^CRST%^around it.",
    ]));

    set_smell("default","%^CRST%^You smell %^C094%^soil %^CRST%^and %^C028%^trees %^CRST%^around you.");
    set_listen("default","%^CRST%^You hear the sounds of %^C094%^small animals%^CRST%^.");

}
