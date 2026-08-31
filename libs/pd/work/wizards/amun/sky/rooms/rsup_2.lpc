#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^BLACK%^The light grows almost pitch black as the path winds towards the east. The sound of screaming and %^RESET%^%^MAGENTA%^sorrowful song %^BOLD%^%^BLACK%^filters down along the path as if there is great agony around. The clouds grow higher and higher with dead %^RESET%^%^GREEN%^v%^ORANGE%^i%^GREEN%^nes %^BOLD%^%^BLACK%^hang from the beginnings of an arch. No breezes flow through the room, just stale, diluted heat.%^RESET%^");
    set_items( ([ "light": "%^BOLD%^%^BLACK%^The light grows almost pitch black as the path winds towards the east.%^RESET%^", "vines": "%^BOLD%^%^BLACK%^Dead %^RESET%^%^GREEN%^v%^ORANGE%^i%^GREEN%^nes %^BOLD%^%^BLACK%^hang from the beginnings of an arch.%^RESET%^", "arch" : "%^BOLD%^%^BLACK%^A blackened archway, stands infront of the gate. Limbs from bodies can be seen protruding from every space between the bars. These lifeless souls are trying to break free.%^RESET%^" ]) );
    set_exits( ([ "south" : SKYROOM "rsup_3", "east" : SKYROOM "rsup_1" ]) );
}
