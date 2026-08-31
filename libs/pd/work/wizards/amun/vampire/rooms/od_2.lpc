#include <std.h>
#include <vampq.h>
inherit VR+"sun_room";
void create() {
    ::create(); 
    set_properties(([  "no bump" : 1, "light" : 2, "no scry" : 1, "outdoors" : 1, "night light" : 0 ]));
    set("short", "Outdoors");
    set_long("%^BOLD%^%^YELLOW%^The sun shines down brightly in this area. There is no vegetation to provide any shade for travelers. Nothing can be seen in any direction except more sun. This is not a good area for those turning into creatures of the night.%^RESET%^");
    set_items((["vegetation" : "%^BOLD%^%^BLACK%^There is no vegetation in the area.%^RESET%^", "sun" : "%^BOLD%^%^YELLOW%^The sun is beating down on you as if trying to take your life away.%^RESET%^" ]));
    set_exits( ([ "north" : VR"od_3", "northwest" : VR"od_b1", "northeast" : VR"od_b2", "south" : VR"od_1" ]) );
    set_period(4);
}
