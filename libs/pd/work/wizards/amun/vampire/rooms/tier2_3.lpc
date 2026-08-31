#include <std.h>
#include <vampq.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([  "no bump" : 1, "light" : 2, "no scry" : 1 ]));
    set("short", "Layer");
    set_long("%^BOLD%^%^BLACK%^description..oh joy%^RESET%^");
    set_items((["vegetation" : "%^BOLD%^%^BLACK%^There is no vegetation in the area.%^RESET%^", "sun" : "%^BOLD%^%^YELLOW%^The sun is beating down on you as if trying to take your life away.%^RESET%^" ]));
    set_exits( ([ "west" : VR"tier2_2", "east" : VR"tier2_4" ]) );
}
